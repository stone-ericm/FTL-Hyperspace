// bridge/bridge.cpp
#include "bridge.h"
#include <cstdio>
#include <cstring>

#define G_ Global::GetInstance()

namespace ftl_rl {

// Static member initialization
HANDLE Bridge::pipe_ = INVALID_HANDLE_VALUE;
BridgeConfig Bridge::config_;
bool Bridge::connected_ = false;
bool Bridge::episode_done_ = false;
bool Bridge::fled_this_step_ = false;
EpisodeResult Bridge::last_result_ = EpisodeResult::LOSS;
float Bridge::game_time_accumulator_ = 0.0f;
ShipManager* Bridge::cached_enemy_ = nullptr;
Pointf Bridge::cached_enemy_world_pos_ = {0.0f, 0.0f};
ResetPhase Bridge::reset_phase_ = ResetPhase::NONE;
int Bridge::reset_wait_frames_ = 0;
float Bridge::state_buffer_[OBS_FIELD_COUNT] = {};
int32_t Bridge::action_buffer_[ACTION_HEAD_COUNT] = {};
int32_t Bridge::persistent_actions_[ACTION_HEAD_COUNT] = {};
std::array<std::array<int, BEAM_PATH_ROOMS>, BEAM_PATH_COUNT> Bridge::beam_paths_ = {};

void Bridge::init(const BridgeConfig& config) {
    // Redirect stderr to file for debugging (B.1 only)
    freopen("C:\\Users\\stone\\ftl-rl\\bridge_log.txt", "w", stderr);
    setvbuf(stderr, nullptr, _IONBF, 0); // unbuffered

    config_ = config;

    // Build pipe name
    char pipe_name[256];
    snprintf(pipe_name, sizeof(pipe_name), "\\\\.\\pipe\\ftl_rl_%d", config_.instance_id);

    fprintf(stderr, "[Bridge] Creating pipe: %s\n", pipe_name);
    pipe_ = create_pipe(pipe_name);
    if (pipe_ == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "[Bridge] FATAL: Could not create pipe\n");
        return;
    }

    fprintf(stderr, "[Bridge] Waiting for Python client...\n");
    if (!wait_for_connection(pipe_, 0)) {
        fprintf(stderr, "[Bridge] FATAL: Client connection failed\n");
        close_pipe(pipe_);
        pipe_ = INVALID_HANDLE_VALUE;
        return;
    }

    connected_ = true;
    fprintf(stderr, "[Bridge] Connected! Instance %d, speed %.1fx, step %.2fs\n",
            config_.instance_id, config_.speed_multiplier, config_.step_interval);

    // Apply speed multiplier
    setSpeedMultiplier(config_.speed_multiplier);

    // Wait for initial RESET from Python
    MsgType msg_type;
    uint32_t payload_size;
    if (!recv_message(pipe_, msg_type, nullptr, 0, payload_size,
                      config_.timeout_seconds * 1000)) {
        fprintf(stderr, "[Bridge] Failed to receive initial RESET\n");
        handleDisconnect();
        return;
    }
    if (msg_type != MsgType::RESET) {
        fprintf(stderr, "[Bridge] Expected RESET, got %d\n", static_cast<int>(msg_type));
        handleDisconnect();
        return;
    }

    // Don't call handleReset() — need to wait for combat to start.
    // Use FINDING_COMBAT (not RESTARTING_GAME): by the time init() fires
    // from ShipManager::OnLoop, the game is already running (auto-start
    // states 0-5 have completed). We just need to find the first enemy.
    // RESTARTING_GAME would incorrectly try to dismiss a game-over screen.
    episode_done_ = false;
    reset_phase_ = ResetPhase::FINDING_COMBAT;
    fprintf(stderr, "[Bridge] Initial RESET received, entering FINDING_COMBAT\n");
}

void Bridge::shutdown() {
    if (pipe_ != INVALID_HANDLE_VALUE) {
        close_pipe(pipe_);
        pipe_ = INVALID_HANDLE_VALUE;
    }
    connected_ = false;
    fprintf(stderr, "[Bridge] Shutdown\n");
}

void Bridge::step() {
    if (!connected_ || reset_phase_ != ResetPhase::NONE) return;

    // Per-frame episode check: catch bDestroyed before OnLoop stops firing.
    if (!episode_done_) {
        EpisodeResult result;
        if (checkEpisodeDone(result)) {
            fprintf(stderr, "[Bridge] Episode end detected in per-frame check (result=%d)\n",
                    static_cast<int>(result));
            sendEpisodeDone(result);
            return;
        }
    }

    // Per-frame weapon code removed. Weapons now fire via:
    // 1. applyWeaponFire() sets correct Targetable ptr + calls Fire() when ready
    // 2. autoFiring flag causes game's own ProjectileFactory::Update() to fire between steps
    // Root cause of prior crash: reinterpret_cast<Targetable*>(enemy) was wrong —
    // Targetable is a member (_targetable), not a base class. Fixed to &enemy->_targetable.

    // Accumulate game time
    // FIXME_ACCESSOR: Get actual frame delta-time from FTL game loop
    float dt = 1.0f / 60.0f; // placeholder: assume 60fps
    game_time_accumulator_ += dt;

    if (game_time_accumulator_ < config_.step_interval) {
        return;
    }
    game_time_accumulator_ -= config_.step_interval;

    doStep();
}

void Bridge::doStep() {
    fprintf(stderr, "[Bridge] doStep() enter\n");

    // Get game objects via Hyperspace Global singleton
    ShipManager* player = G_->GetShipManager(0);
    ShipManager* enemy = G_->GetShipManager(1);
    SpaceManager* space = nullptr; // B.2: access via G_->GetWorld()

    cached_enemy_ = enemy;
    fprintf(stderr, "[Bridge] player=%p enemy=%p cached=%p\n", (void*)player, (void*)enemy, (void*)cached_enemy_);

    // 1. Check episode end (backup — step() checks every frame too)
    if (!episode_done_) {
        EpisodeResult result;
        if (checkEpisodeDone(result)) {
            sendEpisodeDone(result);
            return;
        }
    }

    // 2. Serialize state
    fprintf(stderr, "[Bridge] Serializing state...\n");
    memset(state_buffer_, 0, sizeof(state_buffer_));
    serializeState(state_buffer_, player, enemy, space);
    fprintf(stderr, "[Bridge] State serialized (hull=%.0f)\n", state_buffer_[4]);

    // 3. Send STATE
    if (!send_message(pipe_, MsgType::STATE, state_buffer_, STATE_BUFFER_BYTES)) {
        handleDisconnect();
        return;
    }
    fprintf(stderr, "[Bridge] STATE sent, waiting for ACTION...\n");

    // 4. Receive ACTION (blocks until Python responds)
    MsgType msg_type;
    uint32_t payload_size;
    if (!recv_message(pipe_, msg_type, action_buffer_, ACTION_BUFFER_BYTES,
                      payload_size, config_.timeout_seconds * 1000)) {
        handleDisconnect();
        return;
    }

    if (msg_type != MsgType::ACTION) {
        fprintf(stderr, "[Bridge] Expected ACTION, got %d\n", static_cast<int>(msg_type));
        handleDisconnect();
        return;
    }

    fprintf(stderr, "[Bridge] ACTION received. Heads 0-11: %d %d %d %d | %d %d %d %d | %d %d %d %d\n",
            action_buffer_[0], action_buffer_[1], action_buffer_[2], action_buffer_[3],
            action_buffer_[4], action_buffer_[5], action_buffer_[6], action_buffer_[7],
            action_buffer_[8], action_buffer_[9], action_buffer_[10], action_buffer_[11]);

    // 5. Resolve persistent actions (option 0 = no_change → use previous)
    for (int i = 0; i < ACTION_HEAD_COUNT; i++) {
        if (action_buffer_[i] != 0) {
            persistent_actions_[i] = action_buffer_[i];
        }
        // For one-shot heads, action_buffer_[i] is used directly (0 = hold)
    }

    // 6. Apply actions
    fprintf(stderr, "[Bridge] Applying actions...\n");
    applyActions(action_buffer_, player, enemy);
    fprintf(stderr, "[Bridge] Actions applied OK\n");

    // Reset per-step flags
    fled_this_step_ = false;
    fprintf(stderr, "[Bridge] doStep() done\n");
}

void Bridge::handleReset() {
    // Game is already in combat-ready state (state machine ensured this)
    episode_done_ = false;
    fled_this_step_ = false;
    game_time_accumulator_ = 0.0f;
    cached_enemy_ = nullptr;
    memset(persistent_actions_, 0, sizeof(persistent_actions_));

    ShipManager* player = G_->GetShipManager(0);
    ShipManager* enemy = G_->GetShipManager(1);

    memset(state_buffer_, 0, sizeof(state_buffer_));
    serializeState(state_buffer_, player, enemy, nullptr);

    if (!send_message(pipe_, MsgType::RESET_ACK, state_buffer_, STATE_BUFFER_BYTES)) {
        handleDisconnect();
        return;
    }
    fprintf(stderr, "[Bridge] RESET_ACK sent, resuming stepping\n");
}

void Bridge::pollForReset() {
    // Called from CApp::OnLoop during WAITING_FOR_RESET phase.
    // Non-blocking check for Python's RESET message.
    reset_wait_frames_++;

    // Timeout: 60 seconds at ~60fps = 3600 frames
    if (reset_wait_frames_ > 3600) {
        fprintf(stderr, "[Bridge] WAITING_FOR_RESET timeout (60s). Disconnecting.\n");
        handleDisconnect();
        reset_phase_ = ResetPhase::NONE;
        return;
    }

    uint32_t avail = 0;
    if (!peek_pipe(pipe_, avail)) {
        // Pipe broken (client crashed)
        fprintf(stderr, "[Bridge] Pipe broken during WAITING_FOR_RESET\n");
        handleDisconnect();
        reset_phase_ = ResetPhase::NONE;
        return;
    }

    if (avail < MSG_HEADER_BYTES) return; // no message yet

    // Message available — read it (blocking call is instant since data is buffered)
    MsgType msg_type;
    uint32_t payload_size;
    if (!recv_message(pipe_, msg_type, nullptr, 0, payload_size, 1000)) {
        handleDisconnect();
        reset_phase_ = ResetPhase::NONE;
        return;
    }

    if (msg_type != MsgType::RESET) {
        fprintf(stderr, "[Bridge] Expected RESET during reset phase, got %d\n",
                static_cast<int>(msg_type));
        handleDisconnect();
        reset_phase_ = ResetPhase::NONE;
        return;
    }

    fprintf(stderr, "[Bridge] RESET received (waited %d frames). last_result=%d\n",
            reset_wait_frames_, static_cast<int>(last_result_));

    // NOTE: After setting phase here, the CApp::OnLoop hook reads resetPhase()
    // and sets auto_start_state accordingly (-2 for RESTARTING, 5 for FINDING).
    // This coupling is intentional — pollForReset is a Bridge method and should
    // not directly touch file-static hook variables.
    if (last_result_ == EpisodeResult::LOSS) {
        setResetPhase(ResetPhase::RESTARTING_GAME);  // resets frame counter
        fprintf(stderr, "[Bridge] LOSS → RESTARTING_GAME\n");
    } else {
        // WIN or FLED — game still running, just need next combat
        setResetPhase(ResetPhase::FINDING_COMBAT);  // resets frame counter
        fprintf(stderr, "[Bridge] WIN/FLED → FINDING_COMBAT\n");
    }
}

void Bridge::checkCombatReady() {
    // Called from CApp::OnLoop during FINDING_COMBAT phase.
    // When both player and live enemy exist, finalize the reset.
    reset_wait_frames_++;

    // Timeout: 30 seconds at ~60fps = 1800 frames
    if (reset_wait_frames_ > 1800) {
        fprintf(stderr, "[Bridge] FINDING_COMBAT timeout (30s). Forcing game restart.\n");
        // Force a full restart — setResetPhase resets frame counter.
        // The hook checks for RESTARTING_GAME and sets auto_start_state = -2.
        setResetPhase(ResetPhase::RESTARTING_GAME);
        return;
    }

    ShipManager* player = G_->GetShipManager(0);
    ShipManager* enemy = G_->GetShipManager(1);

    if (player && enemy && !player->bDestroyed && !enemy->bDestroyed && player->hostile_ship) {
        fprintf(stderr, "[Bridge] Combat ready! player=%p enemy=%p\n",
                (void*)player, (void*)enemy);
        handleReset();
        reset_phase_ = ResetPhase::NONE;
        reset_wait_frames_ = 0;
    }
}

void Bridge::sendEpisodeDone(EpisodeResult result) {
    if (episode_done_) return;  // idempotent — prevent double send
    episode_done_ = true;
    last_result_ = result;
    fprintf(stderr, "[Bridge] Sending EPISODE_DONE (result=%d)\n", static_cast<int>(result));

    uint8_t result_byte = static_cast<uint8_t>(result);
    if (!send_message(pipe_, MsgType::EPISODE_DONE, &result_byte, 1)) {
        handleDisconnect();
        return;
    }

    reset_phase_ = ResetPhase::WAITING_FOR_RESET;
    reset_wait_frames_ = 0;
    fprintf(stderr, "[Bridge] Entering WAITING_FOR_RESET\n");
    // Return immediately — no blocking, no disconnect
}

void Bridge::forceEpisodeDone(EpisodeResult result) {
    if (!connected_ || episode_done_) return;
    fprintf(stderr, "[Bridge] Force episode done from external hook (result=%d)\n",
            static_cast<int>(result));
    sendEpisodeDone(result);
}

void Bridge::handleDisconnect() {
    fprintf(stderr, "[Bridge] Disconnected. Waiting for reconnection...\n");
    connected_ = false;
    // Disconnect current client
    DisconnectNamedPipe(pipe_);

    // Wait for new connection
    if (wait_for_connection(pipe_, 0)) {
        connected_ = true;
        fprintf(stderr, "[Bridge] Reconnected\n");
        // Client must send RESET to re-synchronize
        MsgType msg_type;
        uint32_t payload_size;
        if (recv_message(pipe_, msg_type, nullptr, 0, payload_size,
                         config_.timeout_seconds * 1000)) {
            if (msg_type == MsgType::RESET) {
                handleReset();
            }
        }
    }
}

void Bridge::onRunStart(bool isNewGame) {
    fprintf(stderr, "[Bridge] Run started (new=%d)\n", isNewGame);
    game_time_accumulator_ = 0.0f;
}

void Bridge::onJumpLeave(int shipId) {
    if (shipId == 0) { // player ship
        fled_this_step_ = true;
    }
}

void Bridge::onEncounterStart() {
    ShipManager* enemy = G_->GetShipManager(1);
    computeBeamPaths(enemy);
}

// FIXME: Flagship phase transitions (phases 1→2→3) change the ship layout
// but may NOT fire GENERATOR_CREATE_SHIP_POST. Need to detect phase changes
// (e.g., by monitoring boss health thresholds or phase flags) and call
// computeBeamPaths() again. Add a check in doStep() or hook a phase-change
// event if Hyperspace exposes one.

} // namespace ftl_rl
