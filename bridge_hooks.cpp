// bridge_hooks.cpp
// ZHL hook wrappers connecting FTL game events to the RL bridge.
// Thin shims — all logic lives in Bridge class methods.

#include "zhl.h"
#include "FTLGame.h"
#include "Global.h"
#include "bridge.h"

// --- Auto-start: navigate main menu → ship builder → start game ---
static bool bridge_started = false;     // true after first CApp::OnLoop
static int auto_start_state = 0;
static int auto_start_wait = 0;
static int dismiss_attempt = 0;
static bool restart_entry_done = false;
static int wfc_timeout_frames = 0;      // WAITING_FOR_COMBAT timeout counter
static int wfc_timeout_cycles = 0;      // consecutive timeout cycles (max 3)

HOOK_METHOD_PRIORITY(CApp, OnLoop, 100, () -> void) {
    super();

    using ftl_rl::Bridge;
    using ftl_rl::ResetPhase;
    using ftl_rl::EpisodeResult;

    // --- Per-step combat maintenance (only during active stepping) ---
    if (gui && Bridge::isConnected() && Bridge::resetPhase() == ResetPhase::NONE) {

        ShipManager* playerCheck = Global::GetInstance()->GetShipManager(0);
        ShipManager* enemyCheck = Global::GetInstance()->GetShipManager(1);

        // Ensure CombatControl has the enemy ship
        if (enemyCheck && !enemyCheck->bDestroyed && gui->combatControl.enemyShips.empty()) {
            WorldManager* w = Global::GetInstance()->GetWorld();
            CompleteShip* enemyCS = w && w->playerShip
                ? w->playerShip->enemyShip : nullptr;
            if (enemyCS) {
                gui->AddEnemyShip(enemyCS);
            }
        }

        // Non-combat beacon escape removed from NONE phase.
        // CreateLocation during active stepping crashes the game.
        // Auto-nav in state 5 handles beacon jumping during WAITING_FOR_COMBAT.
    }

    // =================================================================
    // PHASE HANDLERS (new non-blocking init)
    // =================================================================

    // --- First frame: enter WAITING_FOR_GAME ---
    if (!bridge_started) {
        bridge_started = true;
        Bridge::setResetPhase(ResetPhase::WAITING_FOR_GAME);
        fprintf(stderr, "[Bridge] Entering WAITING_FOR_GAME\n");
    }

    // --- WAITING_FOR_GAME: let auto-start run freely ---
    if (Bridge::resetPhase() == ResetPhase::WAITING_FOR_GAME) {
        if (auto_start_state >= 5) {
            ftl_rl::BridgeConfig config;
            Bridge::initPipe(config);
            Bridge::setResetPhase(ResetPhase::WAITING_FOR_COMBAT);
            wfc_timeout_frames = 0;
            fprintf(stderr, "[Bridge] Auto-start done → WAITING_FOR_COMBAT\n");
        }
        goto auto_start;
    }

    // --- WAITING_FOR_COMBAT: strict combat confirmation ---
    if (Bridge::resetPhase() == ResetPhase::WAITING_FOR_COMBAT) {
        // Keep game unpaused so FTL drive charges for auto-nav
        if (gui) {
            gui->bPaused = false;
            gui->bAutoPaused = false;
        }

        // Enable auto-nav if needed
        if (auto_start_state > 5) {
            auto_start_state = 5;
            auto_start_wait = 3;
        }

        // Timeout: 120s at 60fps = 7200 frames
        wfc_timeout_frames++;
        if (wfc_timeout_frames > 7200) {
            fprintf(stderr, "[Bridge] WAITING_FOR_COMBAT timeout (120s)\n");
            wfc_timeout_frames = 0;
            wfc_timeout_cycles++;
            if (wfc_timeout_cycles >= 3) {
                fprintf(stderr, "[Bridge] 3 timeout cycles — giving up\n");
                wfc_timeout_cycles = 0;
            }
            Bridge::setResetPhase(ResetPhase::RESTARTING_GAME);
            goto auto_start;
        }

        if (Bridge::checkCombatConfirmed()) {
            wfc_timeout_frames = 0;
            wfc_timeout_cycles = 0;
            if (Bridge::isConnected()) {
                // Reset path — client already connected, send RESET_ACK
                Bridge::handleReset();
                Bridge::setResetPhase(ResetPhase::NONE);
                auto_start_state = 6;  // disable auto-nav during stepping
                fprintf(stderr, "[Bridge] Combat confirmed (reset) → stepping\n");
            } else {
                // Init path — need client connection
                Bridge::setResetPhase(ResetPhase::WAITING_FOR_CLIENT);
                auto_start_state = 6;  // disable auto-nav during stepping
                fprintf(stderr, "[Bridge] Combat confirmed → WAITING_FOR_CLIENT\n");
            }
        }
        goto auto_start;
    }

    // --- WAITING_FOR_CLIENT: block until Python connects ---
    if (Bridge::resetPhase() == ResetPhase::WAITING_FOR_CLIENT) {
        if (Bridge::waitForClient()) {
            Bridge::setResetPhase(ResetPhase::NONE);
            fprintf(stderr, "[Bridge] Client connected → stepping\n");
        } else {
            fprintf(stderr, "[Bridge] Client connection failed\n");
        }
        return;
    }

    // --- WAITING_FOR_RESET: poll for Python's RESET ---
    if (Bridge::resetPhase() == ResetPhase::WAITING_FOR_RESET) {
        Bridge::pollForReset();
        if (Bridge::resetPhase() == ResetPhase::RESTARTING_GAME) {
            auto_start_state = -2;
            auto_start_wait = 60;
        } else if (Bridge::resetPhase() == ResetPhase::WAITING_FOR_COMBAT) {
            auto_start_state = 5;
            auto_start_wait = 3;
            wfc_timeout_frames = 0;
        }
        return;
    }

    // --- RESTARTING_GAME: game-over dismiss → menu → new game ---
    if (Bridge::resetPhase() == ResetPhase::RESTARTING_GAME) {
        if (!restart_entry_done) {
            restart_entry_done = true;
            auto_start_state = -2;
            auto_start_wait = 60;
            dismiss_attempt = 0;
            fprintf(stderr, "[Reset] RESTARTING_GAME entry → state -2\n");
        }
        if (auto_start_state >= 5) {
            fprintf(stderr, "[Reset] RESTARTING_GAME → WAITING_FOR_COMBAT\n");
            restart_entry_done = false;
            Bridge::setResetPhase(ResetPhase::WAITING_FOR_COMBAT);
            wfc_timeout_frames = 0;
        }
        // Fall through to auto-start states
    } else {
        restart_entry_done = false;
    }

    // =================================================================
    // AUTO-START STATE MACHINE (states -2 through 5)
    // =================================================================
auto_start:

    // During NONE phase with auto_start_state > 5, auto-start is done
    if (auto_start_state > 5 && Bridge::resetPhase() == ResetPhase::NONE) return;

    // State -2: Dismiss game-over screen
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
            fprintf(stderr, "[Reset] menu detected! → state 0\n");
            auto_start_state = 0;
            dismiss_attempt = 0;
            return;
        }

        // Dismiss game-over screen
        {
            bool goOpen = gui && gui->gameOverScreen.bOpen;
            fprintf(stderr, "[Reset] dismiss attempt=%d goOpen=%d goPtr=%p gui=%p gameover=%d\n",
                    dismiss_attempt, goOpen, (void*)&gui->gameOverScreen, (void*)gui,
                    gui ? gui->gameover : -1);

            bool gameover_flag = gui && gui->gameover;
            if (goOpen || gameover_flag) {
                auto& go = gui->gameOverScreen;
                go.bOpen = false;
                go.bShowStats = false;
                go.bShowingCredits = false;
                gui->gameover = false;
                gui->alreadyWon = false;
                menu.Open();
                fprintf(stderr, "[Reset] game-over cleared → menu\n");
            }
            // else: wait passively for death animation (~210 frames)
        }

        dismiss_attempt++;
        auto_start_wait = 10;

        if (dismiss_attempt > 60) {
            fprintf(stderr, "[Reset] game-over dismiss failed after 60 attempts → state 0\n");
            auto_start_state = 0;
            dismiss_attempt = 0;
        }
        return;
    }

    // Debug: log state every 60 frames during non-NONE phases
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

    // States 0-5: Auto-start menu → game sequence
    if (auto_start_state == 0 && menu.bOpen && !menu.shipBuilder.bOpen) {
        fprintf(stderr, "[Auto] state 0: opening ship builder\n");
        menu.shipBuilder.Open();
        auto_start_state = 1;
        auto_start_wait = 60;
    }
    else if (auto_start_state == 1) {
        if (menu.shipBuilder.bOpen) {
            fprintf(stderr, "[Auto] state 1: ship builder open → state 2\n");
            auto_start_state = 2;
            auto_start_wait = 30;
        } else if (--auto_start_wait <= 0) {
            fprintf(stderr, "[Auto] state 1: timeout, retrying\n");
            auto_start_state = 0;
        }
    }
    else if (auto_start_state == 2 && --auto_start_wait <= 0) {
        fprintf(stderr, "[Auto] state 2: setting bDone\n");
        menu.shipBuilder.bDone = true;
        auto_start_state = 3;
        auto_start_wait = 120;
    }
    else if (auto_start_state == 3) {
        if (!menu.shipBuilder.bOpen) {
            fprintf(stderr, "[Auto] state 3: game started → state 4\n");
            auto_start_state = 4;
            auto_start_wait = 60;
        } else if (--auto_start_wait <= 0) {
            fprintf(stderr, "[Auto] state 3: timeout, retrying\n");
            auto_start_state = 0;
        }
    }
    else if (auto_start_state == 4 && --auto_start_wait <= 0) {
        this->OnKeyDown(static_cast<SDLKey>(0x31)); // SDLK_1
        this->OnKeyUp(static_cast<SDLKey>(0x31));
        fprintf(stderr, "[Auto] state 4: dismissed event → state 5\n");
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
                // Press '1' — usually "attack/engage" in FTL events.
                static int key_cycle = 0;
                int keys[] = {0x31, 0x31, 0x32, 0x33}; // 1, 1, 2, 3
                SDLKey key = static_cast<SDLKey>(keys[key_cycle % 4]);
                this->OnKeyDown(key);
                this->OnKeyUp(key);
                key_cycle++;
                // Wait 120 frames (~2s) for event to resolve + combat to start
                // before resuming jump checks. Without this, we jump away
                // before hostile_ship gets set.
                auto_start_wait = 120;
            } else if (gui->equipScreen.bStoreMode) {
                this->OnKeyDown(static_cast<SDLKey>(0x1B)); // Escape
                this->OnKeyUp(static_cast<SDLKey>(0x1B));
            }
        }

        // In combat? Stop jumping.
        ShipManager* player_check = Global::GetInstance()->GetShipManager(0);
        if (enemy && !enemy->bDestroyed && player_check && player_check->hostile_ship) return;

        // If FTL charged, jump to next beacon
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
                fprintf(stderr, "[Auto] jumped to beacon (fuel=%d)\n", player->fuel_count);
                // Don't manually set hostile_ship/current_target/AddEnemyShip.
                // Let the game's event system handle combat initiation after
                // the event choice is dismissed (keys 4,3,2,1 above).
                // Our combat confirmation check will detect when the game
                // actually starts combat.
                auto_start_wait = 60;
            }
        }
    }
}

// --- ShipManager::OnLoop: just step, no init ---
HOOK_METHOD_PRIORITY(ShipManager, OnLoop, 50, () -> void) {
    super();
    if (this != Global::GetInstance()->GetShipManager(0)) return;
    ftl_rl::Bridge::step();
}

// --- JumpLeave: flee detection ---
HOOK_METHOD(ShipManager, JumpLeave, () -> void) {
    if (this == Global::GetInstance()->GetShipManager(0)) {
        ftl_rl::Bridge::onJumpLeave(0);
    }
    super();
}

// --- GameOver::OpenText: fallback loss detection ---
HOOK_METHOD(GameOver, OpenText, (const std::string& text) -> void) {
    super(text);
    if (ftl_rl::Bridge::isConnected() && !ftl_rl::Bridge::isEpisodeDone()) {
        ftl_rl::Bridge::forceEpisodeDone(ftl_rl::EpisodeResult::LOSS);
    }
}
