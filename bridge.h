// bridge/bridge.h
#pragma once

#include "bridge_protocol.h"
#include <array>
#include <string>

#include "FTLGame.h"
#include "Global.h"

namespace ftl_rl {

// --- Configuration (from CLI args) ---
struct BridgeConfig {
    int instance_id = 0;
    float speed_multiplier = 1.0f;
    float step_interval = 1.0f;     // game seconds between agent steps
    int timeout_seconds = 30;
    std::string ship_blueprint = "kestrel_a";
    bool debug_json = false;        // output JSON instead of binary (dev only)
};

// --- Reset State Machine ---
enum class ResetPhase {
    NONE,               // Normal stepping
    WAITING_FOR_GAME,   // Auto-start running, no pipe yet
    WAITING_FOR_COMBAT, // Pipe created, waiting for strict combat confirmation
    WAITING_FOR_CLIENT, // Combat confirmed, waiting for Python to connect
    WAITING_FOR_RESET,  // EPISODE_DONE sent, polling for Python's RESET
    RESTARTING_GAME,    // LOSS: navigating game-over → menu → new game
};

// --- Beam Path Data ---
constexpr size_t BEAM_PATH_COUNT = 80;
constexpr size_t BEAM_PATH_ROOMS = 5;

// --- Bridge Singleton ---
class Bridge {
public:
    // Initialization — phased, called from CApp::OnLoop
    static void initPipe(const BridgeConfig& config);  // Create pipe (non-blocking)
    static bool waitForClient();                         // ConnectNamedPipe + RESET handshake
    static bool checkCombatConfirmed();                  // Strict combat check with consecutive gate
    static void shutdown();

    // Stepping — called from ShipManager::OnLoop
    static void step();

    // Lua hook callbacks
    static void onRunStart(bool isNewGame);
    static void onJumpLeave(int shipId);
    static void onEncounterStart();

    // Called from static helpers in bridge_actions.cpp
    static void allocatePower(const int32_t* power_targets, ShipManager* ship);
    static void applyVentCommand(int room_id, bool vent, ShipManager* ship);

    // For external hooks (GameOver) to query and trigger episode end
    static bool isConnected() { return connected_; }
    static bool isEpisodeDone() { return episode_done_; }
    static void forceEpisodeDone(EpisodeResult result);

    // Reset state machine — called from CApp::OnLoop hook
    static void pollForReset();
    static void handleReset();    // public: called from hook on reset path
    static ResetPhase resetPhase() { return reset_phase_; }
    static void setResetPhase(ResetPhase phase) { reset_phase_ = phase; reset_wait_frames_ = 0; }

    // Public state for hooks
    static ShipManager* cached_enemy_;
    static Pointf cached_enemy_world_pos_;
    static int combat_confirm_count_;

private:
    static void sendEpisodeDone(EpisodeResult result);
    static void doStep();
    static void handleDisconnect();

    // State serialization (bridge_state.cpp)
    static void serializeState(float* buffer, ShipManager* player, ShipManager* enemy,
                               SpaceManager* space);

    // Action application (bridge_actions.cpp)
    static void applyActions(const int32_t* actions, ShipManager* player, ShipManager* enemy);

    // Beam paths (bridge_paths.cpp)
    static void computeBeamPaths(ShipManager* enemy);

    // Game management (bridge_game.cpp)
    static void resetGame();
    static bool checkEpisodeDone(EpisodeResult& result);
    static void setSpeedMultiplier(float multiplier);

    // State
    static HANDLE pipe_;
    static BridgeConfig config_;
    static bool connected_;
    static bool episode_done_;
    static bool fled_this_step_;
    static EpisodeResult last_result_;
    static float game_time_accumulator_;
    static ResetPhase reset_phase_;
    static int reset_wait_frames_;

    // Buffers
    static float state_buffer_[OBS_FIELD_COUNT];
    static int32_t action_buffer_[ACTION_HEAD_COUNT];
    static int32_t persistent_actions_[ACTION_HEAD_COUNT];

    // Beam path cache
    static std::array<std::array<int, BEAM_PATH_ROOMS>, BEAM_PATH_COUNT> beam_paths_;
};

} // namespace ftl_rl
