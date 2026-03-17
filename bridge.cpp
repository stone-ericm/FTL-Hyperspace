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
int Bridge::combat_confirm_count_ = 0;
float Bridge::state_buffer_[OBS_FIELD_COUNT] = {};
int32_t Bridge::action_buffer_[ACTION_HEAD_COUNT] = {};
int32_t Bridge::persistent_actions_[ACTION_HEAD_COUNT] = {};
std::array<std::array<int, BEAM_PATH_ROOMS>, BEAM_PATH_COUNT> Bridge::beam_paths_ = {};

// ============================================================================
// INITIALIZATION (phased, non-blocking)
// ============================================================================

void Bridge::initPipe(const BridgeConfig& config) {
    // Idempotent — only create pipe once
    if (pipe_ != INVALID_HANDLE_VALUE) return;

    // Redirect stderr to file for debugging
    freopen("C:\\Users\\stone\\ftl-rl\\bridge_log.txt", "w", stderr);
    setvbuf(stderr, nullptr, _IONBF, 0);

    config_ = config;

    char pipe_name[256];
    snprintf(pipe_name, sizeof(pipe_name), "\\\\.\\pipe\\ftl_rl_%d", config_.instance_id);

    fprintf(stderr, "[Bridge] Creating pipe: %s\n", pipe_name);
    pipe_ = create_pipe(pipe_name);
    if (pipe_ == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "[Bridge] FATAL: Could not create pipe\n");
        return;
    }
    fprintf(stderr, "[Bridge] Pipe created, waiting for combat confirmation...\n");
}

bool Bridge::waitForClient() {
    fprintf(stderr, "[Bridge] Waiting for Python client...\n");
    if (!wait_for_connection(pipe_, 0)) {
        fprintf(stderr, "[Bridge] Client connection failed\n");
        return false;
    }

    connected_ = true;
    fprintf(stderr, "[Bridge] Connected! Instance %d\n", config_.instance_id);

    // Wait for initial RESET from Python
    MsgType msg_type;
    uint32_t payload_size;
    if (!recv_message(pipe_, msg_type, nullptr, 0, payload_size,
                      config_.timeout_seconds * 1000)) {
        fprintf(stderr, "[Bridge] Failed to receive RESET\n");
        connected_ = false;
        return false;
    }
    if (msg_type != MsgType::RESET) {
        fprintf(stderr, "[Bridge] Expected RESET, got %d\n", static_cast<int>(msg_type));
        connected_ = false;
        return false;
    }

    fprintf(stderr, "[Bridge] RESET received, sending RESET_ACK\n");
    handleReset();
    return true;
}

bool Bridge::checkCombatConfirmed() {
    // Frame-skip: only evaluate every 10th call
    static int frame_skip = 0;
    if (++frame_skip < 10) return false;
    frame_skip = 0;

    ShipManager* player = G_->GetShipManager(0);
    ShipManager* enemy = G_->GetShipManager(1);

    // Game sets hostile_ship inconsistently — sometimes on player only,
    // sometimes on enemy only. Check EITHER side.
    bool ok = player && enemy
        && !player->bDestroyed && !enemy->bDestroyed
        && (player->hostile_ship || enemy->hostile_ship)
        && (player->current_target == enemy || enemy->current_target == player);

    // Log failed checks periodically to diagnose stuck combat search
    static int diag_counter = 0;
    if (!ok && player && enemy && ++diag_counter >= 30) {
        diag_counter = 0;
        fprintf(stderr, "[Combat] p_hostile=%d e_hostile=%d p_target=%d e_target=%d p_dead=%d e_dead=%d\n",
                player->hostile_ship, enemy->hostile_ship,
                player->current_target == enemy, enemy->current_target == player,
                player->bDestroyed, enemy->bDestroyed);
    }

    if (ok) {
        combat_confirm_count_++;
    } else {
        combat_confirm_count_ = 0;
    }

    if (combat_confirm_count_ >= 3) {
        fprintf(stderr, "[Bridge] Combat confirmed! (%d consecutive checks)\n",
                combat_confirm_count_);
        combat_confirm_count_ = 0;
        return true;
    }
    return false;
}

void Bridge::shutdown() {
    if (pipe_ != INVALID_HANDLE_VALUE) {
        close_pipe(pipe_);
        pipe_ = INVALID_HANDLE_VALUE;
    }
    connected_ = false;
    fprintf(stderr, "[Bridge] Shutdown\n");
}

// ============================================================================
// STEPPING
// ============================================================================

void Bridge::step() {
    if (!connected_ || reset_phase_ != ResetPhase::NONE) return;

    // Per-frame episode check: catch bDestroyed before OnLoop stops firing.
    if (!episode_done_) {
        EpisodeResult result;
        if (checkEpisodeDone(result)) {
            fprintf(stderr, "[Bridge] Episode end detected (result=%d)\n",
                    static_cast<int>(result));
            sendEpisodeDone(result);
            return;
        }
    }

    // Accumulate game time
    float dt = 1.0f / 60.0f; // placeholder: assume 60fps
    game_time_accumulator_ += dt;

    if (game_time_accumulator_ < config_.step_interval) {
        return;
    }
    game_time_accumulator_ -= config_.step_interval;

    doStep();
}

void Bridge::doStep() {
    static int step_count = 0;

    ShipManager* player = G_->GetShipManager(0);
    ShipManager* enemy = G_->GetShipManager(1);
    SpaceManager* space = nullptr;

    cached_enemy_ = enemy;

    // Check episode end (backup)
    if (!episode_done_) {
        EpisodeResult result;
        if (checkEpisodeDone(result)) {
            sendEpisodeDone(result);
            return;
        }
    }

    // Serialize state
    memset(state_buffer_, 0, sizeof(state_buffer_));
    serializeState(state_buffer_, player, enemy, space);

    // Send STATE
    if (!send_message(pipe_, MsgType::STATE, state_buffer_, STATE_BUFFER_BYTES)) {
        handleDisconnect();
        return;
    }

    // Receive ACTION (blocks until Python responds)
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

    // Resolve persistent actions
    for (int i = 0; i < ACTION_HEAD_COUNT; i++) {
        if (action_buffer_[i] != 0) {
            persistent_actions_[i] = action_buffer_[i];
        }
    }

    // Apply actions
    applyActions(action_buffer_, player, enemy);

    fled_this_step_ = false;
    step_count++;

    if (step_count % 10 == 0) {
        fprintf(stderr, "[Bridge] step %d hull=%.0f enemy_hull=%.0f\n",
                step_count, state_buffer_[4], state_buffer_[5241]);
    }
}

// ============================================================================
// RESET STATE MACHINE
// ============================================================================

void Bridge::handleReset() {
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
    reset_wait_frames_++;

    // Timeout: 60 seconds
    if (reset_wait_frames_ > 3600) {
        fprintf(stderr, "[Bridge] WAITING_FOR_RESET timeout (60s). Disconnecting.\n");
        handleDisconnect();
        reset_phase_ = ResetPhase::NONE;
        return;
    }

    uint32_t avail = 0;
    if (!peek_pipe(pipe_, avail)) {
        fprintf(stderr, "[Bridge] Pipe broken during WAITING_FOR_RESET\n");
        handleDisconnect();
        reset_phase_ = ResetPhase::NONE;
        return;
    }

    if (avail < MSG_HEADER_BYTES) return;

    // Read message — use action_buffer_ as scratch space for stale ACTIONs
    MsgType msg_type;
    uint32_t payload_size;
    if (!recv_message(pipe_, msg_type, action_buffer_, ACTION_BUFFER_BYTES,
                      payload_size, 1000)) {
        handleDisconnect();
        reset_phase_ = ResetPhase::NONE;
        return;
    }

    // Discard stale ACTION messages (race: Python sent ACTION before
    // receiving EPISODE_DONE). Keep polling for RESET.
    if (msg_type == MsgType::ACTION) {
        fprintf(stderr, "[Bridge] Discarded stale ACTION during WAITING_FOR_RESET\n");
        return;  // will check again next frame
    }

    if (msg_type != MsgType::RESET) {
        fprintf(stderr, "[Bridge] Expected RESET, got %d\n", static_cast<int>(msg_type));
        handleDisconnect();
        reset_phase_ = ResetPhase::NONE;
        return;
    }

    fprintf(stderr, "[Bridge] RESET received (waited %d frames). last_result=%d\n",
            reset_wait_frames_, static_cast<int>(last_result_));

    if (last_result_ == EpisodeResult::LOSS) {
        setResetPhase(ResetPhase::RESTARTING_GAME);
        fprintf(stderr, "[Bridge] LOSS → RESTARTING_GAME\n");
    } else {
        setResetPhase(ResetPhase::WAITING_FOR_COMBAT);
        fprintf(stderr, "[Bridge] WIN/FLED → WAITING_FOR_COMBAT\n");
    }
}

void Bridge::sendEpisodeDone(EpisodeResult result) {
    if (episode_done_) return;
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
}

void Bridge::forceEpisodeDone(EpisodeResult result) {
    // Phase guard: only fire during active stepping (NONE).
    // Prevents desync if player dies during init phases.
    if (!connected_ || episode_done_ || reset_phase_ != ResetPhase::NONE) return;
    fprintf(stderr, "[Bridge] Force episode done from external hook (result=%d)\n",
            static_cast<int>(result));
    sendEpisodeDone(result);
}

void Bridge::handleDisconnect() {
    fprintf(stderr, "[Bridge] Disconnected. Waiting for reconnection...\n");
    connected_ = false;
    DisconnectNamedPipe(pipe_);

    // Wait for new connection (blocking — acknowledged future fix)
    if (wait_for_connection(pipe_, 0)) {
        connected_ = true;
        fprintf(stderr, "[Bridge] Reconnected\n");
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

// ============================================================================
// HOOK CALLBACKS
// ============================================================================

void Bridge::onRunStart(bool isNewGame) {
    fprintf(stderr, "[Bridge] Run started (new=%d)\n", isNewGame);
    game_time_accumulator_ = 0.0f;
}

void Bridge::onJumpLeave(int shipId) {
    if (shipId == 0) {
        fled_this_step_ = true;
    }
}

void Bridge::onEncounterStart() {
    ShipManager* enemy = G_->GetShipManager(1);
    computeBeamPaths(enemy);
}

} // namespace ftl_rl
