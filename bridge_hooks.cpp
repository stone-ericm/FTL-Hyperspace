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
static int dismiss_attempt = 0;  // game-over dismiss retry counter (reset on RESTARTING_GAME entry)

HOOK_METHOD_PRIORITY(CApp, OnLoop, 100, () -> void) {
    super();

    using ftl_rl::Bridge;
    using ftl_rl::ResetPhase;
    using ftl_rl::EpisodeResult;

    // Log CombatControl positions for weapon targeting debug
    if (gui && Bridge::isConnected() && Bridge::resetPhase() == ResetPhase::NONE) {
        fprintf(stderr, "[CombatCtrl] playerShipPos=(%d,%d) position=(%d,%d) targetPos=(%d,%d) boxPos=(%d,%d) enemyShips=%d\n",
                gui->combatControl.playerShipPosition.x, gui->combatControl.playerShipPosition.y,
                gui->combatControl.position.x, gui->combatControl.position.y,
                gui->combatControl.targetPosition.x, gui->combatControl.targetPosition.y,
                gui->combatControl.boxPosition.x, gui->combatControl.boxPosition.y,
                (int)gui->combatControl.enemyShips.size());
    }

    // --- Reset state machine (runs when reset_phase_ != NONE) ---

    if (Bridge::resetPhase() == ResetPhase::WAITING_FOR_RESET) {
        Bridge::pollForReset();
        // After pollForReset, phase may have changed. Set auto_start_state accordingly.
        if (Bridge::resetPhase() == ResetPhase::RESTARTING_GAME) {
            auto_start_state = -2;
            auto_start_wait = 60;  // wait for game-over screen to stabilize
        } else if (Bridge::resetPhase() == ResetPhase::FINDING_COMBAT) {
            auto_start_state = 5;  // re-enable auto-nav
            auto_start_wait = 3;
        }
        return;  // don't run auto-start during WAITING_FOR_RESET
    }

    if (Bridge::resetPhase() == ResetPhase::RESTARTING_GAME) {
        // Ensure auto_start_state is set for game-over dismiss.
        // This handles both entry from WAITING_FOR_RESET (above) and
        // fallback from checkCombatReady() timeout.
        if (auto_start_state > 0 || auto_start_state < -2) {
            auto_start_state = -2;
            auto_start_wait = 60;
            dismiss_attempt = 0;
        }
        // Transition: once auto-start reaches state 5, game is running
        if (auto_start_state >= 5) {
            fprintf(stderr, "[Reset] RESTARTING_GAME → FINDING_COMBAT (auto_start_state=%d)\n",
                    auto_start_state);
            Bridge::setResetPhase(ResetPhase::FINDING_COMBAT);
        }
        // Fall through to auto-start states below (including -2)
    }

    if (Bridge::resetPhase() == ResetPhase::FINDING_COMBAT) {
        Bridge::checkCombatReady();
        // Fall through to auto-start state 5 for beacon jumping
    }

    // --- Auto-start state machine (states -2 through 5) ---
    // During NONE phase with auto_start_state > 5, auto-start is done
    if (auto_start_state > 5 && Bridge::resetPhase() == ResetPhase::NONE) return;

    // State -2: Dismiss game-over screen
    // dismiss_attempt is file-static (not function-static) so it can be
    // reset by the RESTARTING_GAME entry block above.
    if (auto_start_state == -2) {
        if (--auto_start_wait > 0) return;

        // Check if menu already appeared (game-over auto-dismissed or key worked)
        if (menu.bOpen) {
            hs_log_file("Reset: menu open, transitioning to state 0\n");
            auto_start_state = 0;
            dismiss_attempt = 0;
            return;
        }

        // Send dismiss key — try Space first, then Enter, then Escape
        SDLKey key;
        if (dismiss_attempt < 3) {
            key = static_cast<SDLKey>(0x20);  // Space
        } else if (dismiss_attempt < 6) {
            key = static_cast<SDLKey>(0x0D);  // Enter/Return
        } else {
            key = static_cast<SDLKey>(0x1B);  // Escape
        }
        this->OnKeyDown(key);
        this->OnKeyUp(key);
        hs_log_file("Reset: dismiss game-over (attempt %d, key=0x%02X)\n",
                    dismiss_attempt, static_cast<int>(key));
        dismiss_attempt++;
        auto_start_wait = 30;  // wait ~0.5s between attempts

        if (dismiss_attempt > 12) {
            // 12 attempts failed — something unexpected. Log and retry.
            hs_log_file("Reset: game-over dismiss failed after 12 attempts, retrying\n");
            dismiss_attempt = 0;
        }
        return;
    }

    // Note: state -1 removed — state -2 transitions directly to 0 when menu detected.

    // States 0-5: Existing auto-start (unchanged)
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
            auto_start_wait = 60;
        } else if (--auto_start_wait <= 0) {
            hs_log_file("Auto-start: timeout, retrying\n");
            auto_start_state = 0;
        }
    }
    else if (auto_start_state == 4 && --auto_start_wait <= 0) {
        this->OnKeyDown(static_cast<SDLKey>(0x31)); // SDLK_1
        this->OnKeyUp(static_cast<SDLKey>(0x31));
        hs_log_file("Auto-start: sent '1' to dismiss event popup\n");
        auto_start_state = 5;
        auto_start_wait = 3;
    }
    else if (auto_start_state == 5) {
        if (--auto_start_wait > 0) return;
        auto_start_wait = 3;

        ShipManager* enemy = Global::GetInstance()->GetShipManager(1);

        // Dismiss UI overlays
        if (gui) {
            if (gui->choiceBoxOpen) {
                static int key_cycle = 0;
                int keys[] = {0x34, 0x33, 0x32, 0x31}; // 4, 3, 2, 1
                SDLKey key = static_cast<SDLKey>(keys[key_cycle % 4]);
                this->OnKeyDown(key);
                this->OnKeyUp(key);
                key_cycle++;
            } else if (gui->equipScreen.bStoreMode) {
                this->OnKeyDown(static_cast<SDLKey>(0x1B)); // Escape
                this->OnKeyUp(static_cast<SDLKey>(0x1B));
            }
        }

        if (enemy && !enemy->bDestroyed) return; // in live combat — bridge handles weapon control

        // If FTL is charged and no combat, teleport to next beacon
        ShipManager* player = Global::GetInstance()->GetShipManager(0);
        if (player && player->jump_timer.first >= player->jump_timer.second
            && player->jump_timer.second > 0) {
            StarMap& starMap = world->starMap;
            if (starMap.currentLoc &&
                !starMap.currentLoc->connectedLocations.empty()) {
                int idx = rand() % starMap.currentLoc->connectedLocations.size();
                Location* target = starMap.currentLoc->connectedLocations[idx];
                if (player->fuel_count > 0) {
                    player->fuel_count--;
                }
                starMap.currentLoc = target;
                world->CreateLocation(target);
                player->jump_timer.first = 0.0f;

                ShipManager* newEnemy = Global::GetInstance()->GetShipManager(1);
                if (newEnemy) {
                    player->current_target = newEnemy;
                    player->hostile_ship = true;
                    newEnemy->current_target = player;
                    newEnemy->hostile_ship = true;

                    if (gui && gui->combatControl.enemyShips.empty()) {
                        WorldManager* w = Global::GetInstance()->GetWorld();
                        CompleteShip* enemyCS = w && w->playerShip
                            ? w->playerShip->enemyShip : nullptr;
                        if (enemyCS) {
                            hs_log_file("Auto-nav: calling AddEnemyShip for CombatControl\n");
                            gui->AddEnemyShip(enemyCS);
                        }
                    }
                }
                if (gui) {
                    gui->bPaused = false;
                    gui->bAutoPaused = false;
                }
                auto_start_wait = 60;
            }
        }
    }
}

// --- Cache enemy worldPosition post-render ---
// ShipGraph::worldPosition is set during the render pass, not during OnLoop.
// Cache it here so applyWeaponFire (which runs during OnLoop) has valid coords.
HOOK_METHOD(CApp, OnRender, () -> void) {
    super();

    ShipManager* enemyMgr = Global::GetInstance()->GetShipManager(1);
    if (enemyMgr) {
        ShipGraph* eg = ShipGraph::GetShipInfo(enemyMgr->iShipId);
        if (eg && (eg->worldPosition.x != -1.0f || eg->worldPosition.y != -1.0f)) {
            ftl_rl::Bridge::cached_enemy_world_pos_ = eg->worldPosition;
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
