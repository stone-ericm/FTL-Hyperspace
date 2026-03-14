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

// --- Beam Path Data ---
constexpr size_t BEAM_PATH_COUNT = 80;
constexpr size_t BEAM_PATH_ROOMS = 5;

// --- Bridge Singleton ---
class Bridge {
public:
    // Initialization — called once at game startup
    static void init(const BridgeConfig& config);
    static void shutdown();

    // Lua hook callbacks
    static void step();                     // ON_TICK → check interval, step if due
    static void onRunStart(bool isNewGame); // on_init callback
    static void onJumpLeave(int shipId);    // JUMP_LEAVE → fled detection
    static void onEncounterStart();         // GENERATOR_CREATE_SHIP_POST → beam paths

    // Called from static helpers in bridge_actions.cpp
    static void allocatePower(const int32_t* power_targets, ShipManager* ship);
    static void applyVentCommand(int room_id, bool vent, ShipManager* ship);

private:
    // Core loop
    static void doStep();                   // serialize → send → recv → apply
    static void handleReset();              // recv RESET → reset game → send RESET_ACK
    static void handleDisconnect();         // cleanup on pipe error

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

    // Buffers
    static float state_buffer_[OBS_FIELD_COUNT];
    static int32_t action_buffer_[ACTION_HEAD_COUNT];
    static int32_t persistent_actions_[ACTION_HEAD_COUNT]; // last non-zero per head

    // Beam path cache
    static std::array<std::array<int, BEAM_PATH_ROOMS>, BEAM_PATH_COUNT> beam_paths_;
};

} // namespace ftl_rl
