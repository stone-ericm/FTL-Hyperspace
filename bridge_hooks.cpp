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

    if (auto_start_state > 5) return; // 5 = auto-nav active, 6 = done

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
        auto_start_wait = 3; // short wait (CApp::OnLoop fires ~1/sec during bridge stepping)
    }
    else if (auto_start_state == 5) {
        // Auto-navigate: dismiss event popups and jump to next beacon
        if (--auto_start_wait > 0) return; // debounce between actions
        auto_start_wait = 3; // check every ~3 steps

        ShipManager* enemy = Global::GetInstance()->GetShipManager(1);
        // Diagnostic: log once to see why jump isn't happening
        static bool nav_logged = false;
        ShipManager* player_dbg = Global::GetInstance()->GetShipManager(0);
        if (!nav_logged && player_dbg) {
            FILE* lf = fopen("C:\\Users\\stone\\ftl-rl\\autonav_log.txt", "w");
            if (lf) {
                fprintf(lf, "enemy=%s jump=%.0f/%.0f fuel=%d connectedLocs=%d\n",
                    enemy ? "YES" : "no",
                    player_dbg->jump_timer.first, player_dbg->jump_timer.second,
                    player_dbg->fuel_count,
                    (int)(world->starMap.currentLoc ?
                        world->starMap.currentLoc->connectedLocations.size() : -1));
                fclose(lf);
            }
            nav_logged = true;
        }
        if (enemy) return; // in combat — let the bridge handle it

        // Not in combat: try to dismiss any event popup
        this->OnKeyDown(static_cast<SDLKey>(0x31)); // SDLK_1
        this->OnKeyUp(static_cast<SDLKey>(0x31));

        // If FTL is charged and no combat, teleport to next beacon
        ShipManager* player = Global::GetInstance()->GetShipManager(0);
        if (player && player->jump_timer.first >= player->jump_timer.second
            && player->jump_timer.second > 0) {
            StarMap& starMap = world->starMap;
            if (starMap.currentLoc &&
                !starMap.currentLoc->connectedLocations.empty()) {
                // Pick a random connected beacon
                int idx = rand() % starMap.currentLoc->connectedLocations.size();
                Location* target = starMap.currentLoc->connectedLocations[idx];
                // Consume fuel
                if (player->fuel_count > 0) {
                    player->fuel_count--;
                }
                // Teleport: change current location and start the new beacon
                starMap.currentLoc = target;
                world->CreateLocation(target);
                // Reset FTL charge
                player->jump_timer.first = 0.0f;
                auto_start_wait = 60; // wait before next jump attempt
            }
        }
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
