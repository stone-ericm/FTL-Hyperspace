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
    handleReset();
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
    if (!connected_) return;

    // Per-frame episode check: catch bDestroyed before OnLoop stops firing.
    // doStep() only runs every step_interval seconds — too slow to catch
    // the narrow window between destruction and game-over screen transition.
    if (!episode_done_) {
        EpisodeResult result;
        if (checkEpisodeDone(result)) {
            fprintf(stderr, "[Bridge] Episode end detected in per-frame check (result=%d)\n",
                    static_cast<int>(result));
            sendEpisodeDone(result);
            return;
        }
    }

    // Per-frame: re-apply weapon targeting (FTL clears targetId each frame)
    {
        ShipManager* player = G_->GetShipManager(0);
        ShipManager* enemy = G_->GetShipManager(1);
        if (player && enemy && player->weaponSystem) {
            for (int i = 0; i < 4 && i < static_cast<int>(player->weaponSystem->weapons.size()); i++) {
                int action = persistent_actions_[i]; // last weapon target action
                if (action <= 0 || action > 40) continue;
                auto* wpn = player->weaponSystem->weapons[i];
                if (!wpn || !wpn->powered) continue;
                int target_room = action - 1;
                wpn->currentShipTarget = reinterpret_cast<Targetable*>(enemy);
                wpn->targetId = target_room;
                wpn->autoFiring = true;
                // fireWhenReady omitted — conflicts with autofire
                if (target_room < static_cast<int>(enemy->ship.vRoomList.size())) {
                    Pointf world = enemy->_targetable.GetRandomTargettingPoint(false);
                    wpn->targets.clear();
                    wpn->targets.push_back(world);
                }
            }
        }
    }

    // Accumulate game time (delta-time per frame)
    // FIXME_ACCESSOR: Get actual frame delta-time from FTL game loop
    // float dt = G_->GetInstance()->FIXME_frame_delta_time;
    float dt = 1.0f / 60.0f; // placeholder: assume 60fps
    game_time_accumulator_ += dt;

    // Check if step interval has elapsed
    if (game_time_accumulator_ < config_.step_interval) {
        return; // Not time for an agent step yet
    }
    game_time_accumulator_ -= config_.step_interval;

    doStep();
}

void Bridge::doStep() {
    // Get game objects via Hyperspace Global singleton
    ShipManager* player = G_->GetShipManager(0);
    ShipManager* enemy = G_->GetShipManager(1);
    SpaceManager* space = nullptr; // B.2: access via G_->GetWorld()

    // 1. Check episode end (backup — step() checks every frame too)
    if (!episode_done_) {
        EpisodeResult result;
        if (checkEpisodeDone(result)) {
            sendEpisodeDone(result);
            return;
        }
    }

    // 2. Serialize state
    memset(state_buffer_, 0, sizeof(state_buffer_));
    serializeState(state_buffer_, player, enemy, space);

    // 3. Send STATE
    if (!send_message(pipe_, MsgType::STATE, state_buffer_, STATE_BUFFER_BYTES)) {
        handleDisconnect();
        return;
    }

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

    // 5. Resolve persistent actions (option 0 = no_change → use previous)
    for (int i = 0; i < ACTION_HEAD_COUNT; i++) {
        if (action_buffer_[i] != 0) {
            persistent_actions_[i] = action_buffer_[i];
        }
        // For one-shot heads, action_buffer_[i] is used directly (0 = hold)
    }

    // 6. Apply actions
    applyActions(action_buffer_, player, enemy);

    // Reset per-step flags
    fled_this_step_ = false;
}

void Bridge::handleReset() {
    // Reset game state
    resetGame();
    episode_done_ = false;
    fled_this_step_ = false;
    game_time_accumulator_ = 0.0f;
    memset(persistent_actions_, 0, sizeof(persistent_actions_));

    // Serialize initial state
    ShipManager* player = G_->GetShipManager(0);
    ShipManager* enemy = G_->GetShipManager(1);
    SpaceManager* space = nullptr; // B.2: access via G_->GetWorld()

    memset(state_buffer_, 0, sizeof(state_buffer_));
    serializeState(state_buffer_, player, enemy, space);

    // Send RESET_ACK with initial state
    send_message(pipe_, MsgType::RESET_ACK, state_buffer_, STATE_BUFFER_BYTES);
}

void Bridge::sendEpisodeDone(EpisodeResult result) {
    episode_done_ = true;
    last_result_ = result;
    fprintf(stderr, "[Bridge] Sending EPISODE_DONE (result=%d)\n", static_cast<int>(result));

    uint8_t result_byte = static_cast<uint8_t>(result);
    if (!send_message(pipe_, MsgType::EPISODE_DONE, &result_byte, 1)) {
        handleDisconnect();
        return;
    }

    if (result == EpisodeResult::LOSS) {
        // Game is on death screen — resetGame() is not yet implemented,
        // so we can't start a new game. Stop stepping but keep pipe open
        // so the client can read the EPISODE_DONE message.
        // DisconnectNamedPipe would discard unread data (race condition).
        fprintf(stderr, "[Bridge] LOSS — stopping bridge (no auto-reset yet)\n");
        connected_ = false;
        return;
    }

    // FLED/WIN: game continues, wait for RESET and resume stepping
    MsgType msg_type;
    uint32_t payload_size;
    if (!recv_message(pipe_, msg_type, nullptr, 0, payload_size,
                      config_.timeout_seconds * 1000)) {
        handleDisconnect();
        return;
    }

    if (msg_type == MsgType::RESET) {
        handleReset();
    }
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
