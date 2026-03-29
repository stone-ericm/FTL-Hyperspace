// bridge/bridge.cpp
#include "bridge.h"
#include <cstdio>
#include <cstring>
#include <windows.h>

// Performance timing for doStep() phases
struct StepTimer {
    LARGE_INTEGER freq_, start_, lap_;
    double phases_[5] = {};  // serialize, send, wait, read_apply, total_overhead
    int count_ = 0;

    void init() { QueryPerformanceFrequency(&freq_); }

    void begin() {
        QueryPerformanceCounter(&start_);
        lap_ = start_;
    }

    void mark(int phase) {
        LARGE_INTEGER now;
        QueryPerformanceCounter(&now);
        phases_[phase] += (double)(now.QuadPart - lap_.QuadPart) / freq_.QuadPart * 1000.0;
        lap_ = now;
    }

    void end() {
        count_++;
        if (count_ % 100 == 0) {
            LARGE_INTEGER now;
            QueryPerformanceCounter(&now);
            double total = (double)(now.QuadPart - start_.QuadPart) / freq_.QuadPart * 1000.0;
            fprintf(stderr, "[Perf] steps=%d  serialize=%.1fms  send=%.1fms  wait=%.1fms  apply=%.1fms  total=%.1fms  steps/sec=%.1f\n",
                count_,
                phases_[0] / 100, phases_[1] / 100, phases_[2] / 100,
                phases_[3] / 100,
                (phases_[0]+phases_[1]+phases_[2]+phases_[3]) / 100,
                100000.0 / (phases_[0]+phases_[1]+phases_[2]+phases_[3]));
            for (int i = 0; i < 5; i++) phases_[i] = 0;
        }
    }
};
static StepTimer g_perf;
static bool g_perf_init = false;

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
int Bridge::event_key_cycle_ = 0;
int Bridge::event_cooldown_ = 0;
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

    // Read headless mode from flag file OR environment.
    // File-based flag is more reliable than env vars (Steam doesn't propagate them).
    {
        FILE* f = fopen("C:\\Users\\stone\\ftl-rl\\headless.flag", "r");
        if (f) { config_.headless = true; fclose(f); }
        const char* headless_env = getenv("FTL_BRIDGE_HEADLESS");
        if (headless_env && (strcmp(headless_env, "1") == 0)) {
            config_.headless = true;
        }
    }
    {
        FILE* f = fopen("C:\\Users\\stone\\ftl-rl\\ipc_mode.flag", "r");
        if (f) {
            char buf[32] = {};
            fgets(buf, sizeof(buf), f);
            fclose(f);
            // Trim newline
            for (int i = 0; buf[i]; i++) { if (buf[i] == '\n' || buf[i] == '\r') buf[i] = 0; }
            if (buf[0]) config_.ipc_mode = buf;
        }
        const char* ipc_env = getenv("FTL_BRIDGE_IPC");
        if (ipc_env) config_.ipc_mode = ipc_env;
    }
    fprintf(stderr, "[Bridge] headless=%d ipc_mode=%s\n", config_.headless, config_.ipc_mode.c_str());

    // Set game speed for training (uses CFPS::speedLevel)
    if (config_.speed_multiplier > 1.0f) {
        setSpeedMultiplier(config_.speed_multiplier);
    }

    // TODO: disable vsync to uncap frame rate (SDL_GL_SetSwapInterval not linkable)
    // For now, rely on high speedLevel + multi-step while loop to compensate.

    // Auto-assign instance_id: try pipe names 0..15 until one is available.
    // This allows multiple FTL instances to coexist without manual configuration.
    char pipe_name[256];
    {
        FILE* id_file = fopen("C:\\Users\\stone\\ftl-rl\\instance_id.flag", "r");
        if (id_file) {
            int id = 0;
            fscanf(id_file, "%d", &id);
            fclose(id_file);
            config_.instance_id = id;
            fprintf(stderr, "[Bridge] Instance ID from file: %d\n", id);
        }
    }
    snprintf(pipe_name, sizeof(pipe_name), "\\\\.\\pipe\\ftl_rl_%d", config_.instance_id);

    fprintf(stderr, "[Bridge] Creating pipe: %s (instance %d)\n", pipe_name, config_.instance_id);
    pipe_ = create_pipe(pipe_name);
    if (pipe_ == INVALID_HANDLE_VALUE) {
        // Pipe name taken — try auto-assign
        for (int id = 0; id < 16; id++) {
            snprintf(pipe_name, sizeof(pipe_name), "\\\\.\\pipe\\ftl_rl_%d", id);
            pipe_ = create_pipe(pipe_name);
            if (pipe_ != INVALID_HANDLE_VALUE) {
                config_.instance_id = id;
                fprintf(stderr, "[Bridge] Auto-assigned instance %d\n", id);
                break;
            }
        }
        if (pipe_ == INVALID_HANDLE_VALUE) {
            fprintf(stderr, "[Bridge] FATAL: No available pipe slots (0-15)\n");
            return;
        }
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

    // Accumulate game time using actual frame delta (accounts for speedLevel)
    CFPS* cfps = G_->GetCFPS();
    float dt = cfps ? cfps->SpeedFactor : (1.0f / 60.0f);
    // In headless mode, SpeedFactor can be large (speedLevel 100+ → dt > 1.0).
    // Only clamp obviously broken values.
    if (dt <= 0.0f || dt > 100.0f) dt = 1.0f / 60.0f;
    game_time_accumulator_ += dt;

    // Process all accumulated steps (allows multiple steps per frame
    // when speedLevel is high enough that dt > step_interval)
    {
        int steps_this_frame = 0;
        while (game_time_accumulator_ >= config_.step_interval) {
            game_time_accumulator_ -= config_.step_interval;
            doStep();
            steps_this_frame++;
            // Re-check episode state after each step
            if (!connected_ || reset_phase_ != ResetPhase::NONE) break;
        }
        static int diag_frames = 0;
        static int diag_total_steps = 0;
        diag_total_steps += steps_this_frame;
        if (++diag_frames % 60 == 0) {
            fprintf(stderr, "[Step] frames=%d dt=%.4f accum=%.4f steps_last_60frames=%d (%.1f/frame) speedLevel=%d\n",
                    diag_frames, dt, game_time_accumulator_, diag_total_steps,
                    diag_total_steps / 60.0f, cfps ? cfps->speedLevel : -1);
            diag_total_steps = 0;
        }
    }
}

void Bridge::doStep() {
    static int step_count = 0;

    if (!g_perf_init) { g_perf.init(); g_perf_init = true; }
    g_perf.begin();

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

    // Phase 0: Serialize state
    memset(state_buffer_, 0, sizeof(state_buffer_));
    serializeState(state_buffer_, player, enemy, space);
    g_perf.mark(0);

    // Phase 1: Send STATE
    if (!send_message(pipe_, MsgType::STATE, state_buffer_, STATE_BUFFER_BYTES)) {
        handleDisconnect();
        return;
    }
    g_perf.mark(1);

    // Phase 2: Receive ACTION (blocks until Python responds)
    MsgType msg_type;
    uint32_t payload_size;
    if (!recv_message(pipe_, msg_type, action_buffer_, ACTION_BUFFER_BYTES,
                      payload_size, config_.timeout_seconds * 1000)) {
        handleDisconnect();
        return;
    }
    g_perf.mark(2);

    if (msg_type == MsgType::RESET) {
        // Python-side truncation (max_steps reached). Continue same combat —
        // navigating to a new beacon takes too long and blocks DummyVecEnv.
        fprintf(stderr, "[Bridge] RESET during step %d (truncation) → continue same combat\n",
                step_count);
        handleReset();  // Send RESET_ACK with current state, resume stepping
        return;
    }
    if (msg_type != MsgType::ACTION) {
        fprintf(stderr, "[Bridge] Expected ACTION, got %d\n", static_cast<int>(msg_type));
        handleDisconnect();
        return;
    }

    // Force weapons to 3 power bars — override agent's action BEFORE
    // applyActions so the budget deprioritization logic handles conflicts.
    // Action head 11 = power_weapons_target. Option 4 = level 3 (3 bars).
    // Weapons are highest priority in deprioritization order, so shields/
    // engines get reduced if total exceeds reactor capacity.
    action_buffer_[11] = 4;

    // Phase 3: Resolve persistent actions + apply
    for (int i = 0; i < ACTION_HEAD_COUNT; i++) {
        if (action_buffer_[i] != 0) {
            persistent_actions_[i] = action_buffer_[i];
        }
    }
    applyActions(action_buffer_, player, enemy);

    g_perf.mark(3);

    fled_this_step_ = false;
    step_count++;
    g_perf.end();

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

    armWeapons();  // Re-arm weapons for new episode

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

void Bridge::armWeapons() {
    ShipManager* player = G_->GetShipManager(0);
    ShipManager* enemy = G_->GetShipManager(1);

    if (!player || !player->weaponSystem) return;

    // Best-effort: add up to 3 power bars to weapons (SYS_WEAPONS = 3).
    // If reactor is full, extra IncreaseSystemPower calls are no-ops.
    for (int i = 0; i < 3; i++)
        player->IncreaseSystemPower(3);

    // Enable autofire on all powered weapons, target room 0
    if (enemy) {
        ShipGraph* enemyGraph = ShipGraph::GetShipInfo(enemy->iShipId);
        for (auto* wpn : player->weaponSystem->weapons) {
            if (wpn && wpn->powered) {
                wpn->SetCurrentShip(&enemy->_targetable);
                wpn->targetId = 0;
                wpn->targets.clear();
                if (enemyGraph) {
                    Pointf center = enemyGraph->GetRoomCenter(0);
                    wpn->targets.push_back(Pointf(center.x, center.y));
                }
                wpn->autoFiring = true;
            }
        }
    }

    fprintf(stderr, "[Bridge] armWeapons: weapons re-armed + autofire on\n");
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
