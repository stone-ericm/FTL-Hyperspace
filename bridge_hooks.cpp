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
static int dismiss_attempt = 0;  // game-over dismiss retry counter
static bool restart_entry_done = false;  // one-shot flag for RESTARTING_GAME entry

HOOK_METHOD_PRIORITY(CApp, OnLoop, 100, () -> void) {
    super();

    using ftl_rl::Bridge;
    using ftl_rl::ResetPhase;
    using ftl_rl::EpisodeResult;

    // Per-step combat maintenance (only during active stepping, reset_phase == NONE)
    if (gui && Bridge::isConnected() && Bridge::resetPhase() == ResetPhase::NONE) {
        ShipManager* playerCheck = Global::GetInstance()->GetShipManager(0);
        ShipManager* enemyCheck = Global::GetInstance()->GetShipManager(1);

        // Ensure CombatControl has the enemy ship — required for autoFiring weapon targeting.
        if (enemyCheck && !enemyCheck->bDestroyed && gui->combatControl.enemyShips.empty()) {
            WorldManager* w = Global::GetInstance()->GetWorld();
            CompleteShip* enemyCS = w && w->playerShip
                ? w->playerShip->enemyShip : nullptr;
            if (enemyCS) {
                gui->AddEnemyShip(enemyCS);
            }
        }

        // Non-combat beacon escape: if enemy exists but hostile_ship is false,
        // this is a non-combat event outcome. Jump away immediately.
        if (playerCheck && enemyCheck && !enemyCheck->bDestroyed
            && !playerCheck->hostile_ship && playerCheck->fuel_count > 0) {
            StarMap& starMap = world->starMap;
            if (starMap.currentLoc && !starMap.currentLoc->connectedLocations.empty()) {
                int idx = rand() % starMap.currentLoc->connectedLocations.size();
                Location* target = starMap.currentLoc->connectedLocations[idx];
                playerCheck->fuel_count--;
                starMap.currentLoc = target;
                world->CreateLocation(target);
                playerCheck->jump_timer.first = 0.0f;
                fprintf(stderr, "[Bridge] Non-combat beacon — jumping away (fuel=%d)\n",
                        playerCheck->fuel_count);

                // Set up combat if enemy spawned
                ShipManager* newEnemy = Global::GetInstance()->GetShipManager(1);
                if (newEnemy) {
                    playerCheck->current_target = newEnemy;
                    playerCheck->hostile_ship = true;
                    newEnemy->current_target = playerCheck;
                    newEnemy->hostile_ship = true;
                }
                if (gui) {
                    gui->bPaused = false;
                    gui->bAutoPaused = false;
                }
            }
        }
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
        // One-shot entry: force state -2 to start game-over dismiss sequence.
        // This fires once per RESTARTING_GAME entry, then states -2→0→1→...→5 progress.
        if (!restart_entry_done) {
            restart_entry_done = true;
            auto_start_state = -2;
            auto_start_wait = 60;
            dismiss_attempt = 0;
            fprintf(stderr, "[Reset] RESTARTING_GAME entry → state -2\n");
        }
        // Transition: once auto-start reaches state 5, game is running
        if (auto_start_state >= 5) {
            fprintf(stderr, "[Reset] RESTARTING_GAME → FINDING_COMBAT (auto_start_state=%d)\n",
                    auto_start_state);
            restart_entry_done = false;
            Bridge::setResetPhase(ResetPhase::FINDING_COMBAT);
        }
        // Fall through to auto-start states below (including -2)
    } else {
        restart_entry_done = false;
    }

    if (Bridge::resetPhase() == ResetPhase::FINDING_COMBAT) {
        // Enable auto-nav ONLY if the initial auto-start already completed.
        if (auto_start_state > 5) {
            auto_start_state = 5;
            auto_start_wait = 3;
        }
        // Keep game unpaused so FTL drive charges and auto-nav can jump.
        // The initial event popup pauses the game; state 4 dismissed it
        // but doesn't unpause.
        if (gui) {
            gui->bPaused = false;
            gui->bAutoPaused = false;
        }
        Bridge::checkCombatReady();
        // If checkCombatReady succeeded, phase is now NONE → ensure combat is
        // fully initiated. The auto-nav jump code does this after CreateLocation,
        // but checkCombatReady may find combat without a jump (e.g., first beacon).
        if (Bridge::resetPhase() == ResetPhase::NONE) {
            ShipManager* p = Global::GetInstance()->GetShipManager(0);
            ShipManager* e = Global::GetInstance()->GetShipManager(1);
            if (p && e) {
                p->current_target = e;
                p->hostile_ship = true;
                e->current_target = p;
                e->hostile_ship = true;
            }
            if (gui) {
                if (gui->combatControl.enemyShips.empty()) {
                    WorldManager* w = Global::GetInstance()->GetWorld();
                    CompleteShip* ecs = w && w->playerShip
                        ? w->playerShip->enemyShip : nullptr;
                    if (ecs) gui->AddEnemyShip(ecs);
                }
                gui->bPaused = false;
                gui->bAutoPaused = false;
            }
            fprintf(stderr, "[Bridge] Combat initiated — targets set, unpaused\n");
        }
        // Fall through to auto-start state 5 for beacon jumping
    }

    // --- Auto-start state machine (states -2 through 5) ---
    // During NONE phase with auto_start_state > 5, auto-start is done
    if (auto_start_state > 5 && Bridge::resetPhase() == ResetPhase::NONE) return;

    // State -2: Dismiss game-over screen
    // dismiss_attempt is file-static (not function-static) so it can be
    // reset by the RESTARTING_GAME entry block above.
    if (auto_start_state == -2) {
        if (--auto_start_wait > 0) {
            if (auto_start_wait % 10 == 0) {
                fprintf(stderr, "[Reset] state -2 waiting (%d frames left) menu=%d\n",
                        auto_start_wait, menu.bOpen);
            }
            return;
        }

        // Check if menu already appeared
        if (menu.bOpen) {
            fprintf(stderr, "[Reset] menu detected! transitioning to state 0\n");
            auto_start_state = 0;
            dismiss_attempt = 0;
            return;
        }

        // Dismiss game-over screen. Try multiple approaches:
        // 1. FocusWindow::Close() + command to trigger "Main Menu"
        // 2. Keyboard input (Enter, Escape) for intermediate screens
        {
            bool goOpen = gui && gui->gameOverScreen.bOpen;
            fprintf(stderr, "[Reset] dismiss attempt=%d goOpen=%d\n", dismiss_attempt, goOpen);

            if (goOpen) {
                auto& go = gui->gameOverScreen;
                // Force-close game-over and transition to menu.
                // Normal button clicks don't work from our hook context.
                go.bOpen = false;
                go.bShowStats = false;
                menu.bOpen = true;
                fprintf(stderr, "[Reset] force-closed game-over, opened menu\n");
            } else {
                // No game-over FocusWindow — send Enter + Escape to
                // dismiss intermediate screens
                this->OnKeyDown(static_cast<SDLKey>(0x0D));
                this->OnKeyUp(static_cast<SDLKey>(0x0D));
                this->OnKeyDown(static_cast<SDLKey>(0x1B));
                this->OnKeyUp(static_cast<SDLKey>(0x1B));
            }
        }

        dismiss_attempt++;
        auto_start_wait = 10;

        if (dismiss_attempt > 30) {
            fprintf(stderr, "[Reset] game-over dismiss failed after 30 attempts, "
                    "falling back to menu start\n");
            // Give up on dismiss, assume we can reach menu.
            // Jump to state 0 which waits for menu.bOpen.
            auto_start_state = 0;
            dismiss_attempt = 0;
        }
        return;
    }

    // Note: state -1 removed — state -2 transitions directly to 0 when menu detected.

    // States 0-5: Auto-start menu→game sequence
    // Debug: log state every 60 frames during reset phases
    {
        static int dbg_counter = 0;
        if (++dbg_counter >= 60 && Bridge::resetPhase() != ResetPhase::NONE) {
            dbg_counter = 0;
            fprintf(stderr, "[Auto] tick: state=%d wait=%d phase=%d menu=%d builder=%d\n",
                    auto_start_state, auto_start_wait,
                    static_cast<int>(Bridge::resetPhase()),
                    menu.bOpen, menu.shipBuilder.bOpen);
        }
    }
    if (auto_start_state == 0 && menu.bOpen && !menu.shipBuilder.bOpen) {
        fprintf(stderr, "[Auto] state 0: opening ship builder\n");
        menu.shipBuilder.Open();
        auto_start_state = 1;
        auto_start_wait = 60;
    }
    else if (auto_start_state == 1) {
        if (menu.shipBuilder.bOpen) {
            fprintf(stderr, "[Auto] state 1: ship builder open → state 2 (wait 30)\n");
            auto_start_state = 2;
            auto_start_wait = 30;
        } else if (--auto_start_wait <= 0) {
            fprintf(stderr, "[Auto] state 1: timeout, retrying\n");
            auto_start_state = 0;
        }
    }
    else if (auto_start_state == 2 && --auto_start_wait <= 0) {
        fprintf(stderr, "[Auto] state 2: setting bDone to start game\n");
        menu.shipBuilder.bDone = true;
        auto_start_state = 3;
        auto_start_wait = 120;
    }
    else if (auto_start_state == 3) {
        if (!menu.shipBuilder.bOpen) {
            fprintf(stderr, "[Auto] state 3: game started → state 4 (dismiss popup)\n");
            auto_start_state = 4;
            auto_start_wait = 60;
        } else if (--auto_start_wait <= 0) {
            fprintf(stderr, "[Auto] state 3: timeout, retrying from state 0\n");
            auto_start_state = 0;
        }
    }
    else if (auto_start_state == 4 && --auto_start_wait <= 0) {
        this->OnKeyDown(static_cast<SDLKey>(0x31)); // SDLK_1
        this->OnKeyUp(static_cast<SDLKey>(0x31));
        fprintf(stderr, "[Auto] state 4: sent '1' to dismiss event popup → state 5\n");
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

        // Only stop jumping if we're actually IN combat (hostile_ship = true).
        // Some events have an enemy present but no combat (peaceful event outcome).
        ShipManager* player_check = Global::GetInstance()->GetShipManager(0);
        if (enemy && !enemy->bDestroyed && player_check && player_check->hostile_ship) return;

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
