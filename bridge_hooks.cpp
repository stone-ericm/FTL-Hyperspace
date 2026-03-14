// bridge_hooks.cpp
// ZHL hook wrappers connecting FTL game events to the RL bridge.
// Thin shims — all logic lives in Bridge class methods.

#include "zhl.h"
#include "FTLGame.h"
#include "Global.h"
#include "bridge.h"

static bool bridge_initialized = false;

// --- Auto-start: navigate main menu → ship builder → start game ---
// Call Open() directly to bypass button state issues.
static int auto_start_state = 0;
static int auto_start_wait = 0;

HOOK_METHOD_PRIORITY(CApp, OnLoop, 100, () -> void) {
    super();

    if (auto_start_state >= 5) return;

    if (auto_start_state == 0 && menu.bOpen && !menu.shipBuilder.bOpen) {
        hs_log_file("Auto-start: opening ship builder directly\n");
        menu.shipBuilder.Open();
        auto_start_state = 1;
        auto_start_wait = 60;
    }
    else if (auto_start_state == 1) {
        if (menu.shipBuilder.bOpen) {
            hs_log_file("Auto-start: ship builder open, setting bDone\n");
            auto_start_state = 2;
            auto_start_wait = 30;
        } else if (--auto_start_wait <= 0) {
            hs_log_file("Auto-start: timeout, retrying\n");
            auto_start_state = 0;
        }
    }
    else if (auto_start_state == 2 && --auto_start_wait <= 0) {
        hs_log_file("Auto-start: setting bDone to start game\n");
        menu.shipBuilder.bDone = true;
        auto_start_state = 3;
        auto_start_wait = 120;
    }
    else if (auto_start_state == 3) {
        if (!menu.shipBuilder.bOpen) {
            hs_log_file("Auto-start: game started, dismissing event popup\n");
            auto_start_state = 4;
            auto_start_wait = 60; // wait ~1s for event popup to render
        } else if (--auto_start_wait <= 0) {
            hs_log_file("Auto-start: timeout, retrying\n");
            auto_start_state = 0;
        }
    }
    else if (auto_start_state == 4 && --auto_start_wait <= 0) {
        // Dismiss the initial event popup by pressing "1" (first choice)
        this->OnKeyDown(static_cast<SDLKey>(0x31)); // SDLK_1
        this->OnKeyUp(static_cast<SDLKey>(0x31));
        hs_log_file("Auto-start: sent '1' to dismiss event popup\n");
        auto_start_state = 5;
    }
}

// --- Main game loop: serialize state, send/recv, apply actions ---
// ShipManager::OnLoop fires every frame for each ship (player + enemy).
// Priority 50 = run before most Hyperspace hooks for clean game state.
HOOK_METHOD_PRIORITY(ShipManager, OnLoop, 50, () -> void) {
    super();

    // Only run bridge on player ship (id 0), not enemy
    if (this != Global::GetInstance()->GetShipManager(0)) return;

    // Lazy init: create pipe and wait for Python client on first tick
    if (!bridge_initialized) {
        ftl_rl::BridgeConfig config;
        ftl_rl::Bridge::init(config);
        bridge_initialized = true;
    }

    ftl_rl::Bridge::step();
}

// OnInit and CreateShip hooks disabled (need timing guards).
// JumpLeave re-enabled for flee detection (B.3).

HOOK_METHOD(ShipManager, JumpLeave, () -> void) {
    if (this == Global::GetInstance()->GetShipManager(0)) {
        ftl_rl::Bridge::onJumpLeave(0);
    }
    super();
}

// --- Fallback: detect player death even if OnLoop stops firing ---
// GameOver::OpenText fires exactly once when the game-over screen opens.
// If the bridge is still connected and hasn't sent EPISODE_DONE yet,
// it means OnLoop stopped before the per-frame check caught bDestroyed.
HOOK_METHOD(GameOver, OpenText, (const std::string& text) -> void) {
    super(text);
    if (ftl_rl::Bridge::isConnected() && !ftl_rl::Bridge::isEpisodeDone()) {
        ftl_rl::Bridge::forceEpisodeDone(ftl_rl::EpisodeResult::LOSS);
    }
}
