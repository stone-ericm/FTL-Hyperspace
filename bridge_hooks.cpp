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

// Diagnostic frame counter for RESTARTING_GAME phase
static int restart_diag_frames = 0;
// Post-restart cooldown: extra delay before first CreateLocation after LOSS recovery
static int post_restart_cooldown = 0;

// OnRender skip freezes game time (SpeedFactor stops advancing).
// Rendering is required for CFPS timing to work correctly.
// HOOK_METHOD(CApp, OnRender, () -> void) {}

HOOK_METHOD_PRIORITY(CApp, OnLoop, 100, () -> void) {
    // Unpause before super() — game skips ShipManager updates when paused.
    // BUT: during game-over dismiss (auto_start_state == -2), let the game
    // stay paused so the death animation and game-over screen can appear naturally.
    if (gui && auto_start_state != -2) {
        gui->bPaused = false;
        gui->bAutoPaused = false;
    }

    // Force the game to think it has input focus. Without this,
    // CommandGui::OnLoop skips ship updates when FTL isn't foreground.
    this->OnInputFocus();

    super();

    using ftl_rl::Bridge;
    using ftl_rl::ResetPhase;
    using ftl_rl::EpisodeResult;

    // Call step() from CApp::OnLoop (after super()) because ShipManager::OnLoop
    // doesn't fire reliably when FTL lacks OS-level focus. CApp::OnLoop always fires.
    if (Bridge::isConnected() && Bridge::resetPhase() == ResetPhase::NONE) {
        Bridge::step();
    }

    // --- Per-step combat maintenance (only during active stepping) ---
    if (gui && Bridge::isConnected() && Bridge::resetPhase() == ResetPhase::NONE) {
        // Keep unpaused
        gui->bPaused = false;
        gui->bAutoPaused = false;

        ShipManager* playerCheck = Global::GetInstance()->GetShipManager(0);
        ShipManager* enemyCheck = Global::GetInstance()->GetShipManager(1);

        // Ensure CombatControl has the enemy ship
        if (enemyCheck && !enemyCheck->bDestroyed && gui->combatControl.enemyShips.empty()) {
            WorldManager* w = Global::GetInstance() ? Global::GetInstance()->GetWorld() : nullptr;
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
            config.speed_multiplier = 10;  // 10x speed (step() from CApp::OnLoop)
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
        restart_diag_frames++;
        if (!restart_entry_done) {
            restart_entry_done = true;
            restart_diag_frames = 0;
            auto_start_state = -2;
            auto_start_wait = 60;
            dismiss_attempt = 0;
            // Diagnostic: log all accessible pointers at entry
            Global* g = Global::GetInstance();
            ShipManager* p = g ? g->GetShipManager(0) : nullptr;
            ShipManager* e = g ? g->GetShipManager(1) : nullptr;
            WorldManager* w = g ? g->GetWorld() : nullptr;
            fprintf(stderr, "[Reset] RESTARTING_GAME entry → state -2  gui=%p Global=%p player=%p enemy=%p world=%p menu.bOpen=%d\n",
                    (void*)gui, (void*)g, (void*)p, (void*)e, (void*)w, menu.bOpen);
        }
        // Periodic diagnostic during restart
        if (restart_diag_frames % 60 == 0 && restart_diag_frames > 0) {
            fprintf(stderr, "[Reset] RESTARTING_GAME frame=%d auto_state=%d auto_wait=%d dismiss=%d menu=%d\n",
                    restart_diag_frames, auto_start_state, auto_start_wait, dismiss_attempt, menu.bOpen);
        }
        if (auto_start_state >= 5) {
            fprintf(stderr, "[Reset] RESTARTING_GAME → WAITING_FOR_COMBAT (took %d frames)\n", restart_diag_frames);
            restart_entry_done = false;
            restart_diag_frames = 0;
            Bridge::setResetPhase(ResetPhase::WAITING_FOR_COMBAT);
            wfc_timeout_frames = 0;
            // After LOSS recovery, the new game needs time to fully initialize
            // before TravelToLocation is safe. Give it 600 frames (~10s at 60fps).
            post_restart_cooldown = 600;
            fprintf(stderr, "[Reset] post_restart_cooldown set to 600 frames\n");
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
                fprintf(stderr, "[Reset] state -2 waiting (%d frames left) menu=%d gui=%p\n",
                        auto_start_wait, menu.bOpen, (void*)gui);
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

        // Null-guard: gui must exist before touching gameOverScreen
        if (!gui) {
            fprintf(stderr, "[Reset] WARN: gui is NULL in state -2, attempt=%d — skipping dismiss\n", dismiss_attempt);
            dismiss_attempt++;
            auto_start_wait = 10;
            if (dismiss_attempt > 60) {
                fprintf(stderr, "[Reset] game-over dismiss failed (gui NULL) after 60 attempts → state 0\n");
                auto_start_state = 0;
                dismiss_attempt = 0;
            }
            return;
        }

        // Dismiss game-over screen
        {
            bool goOpen = gui->gameOverScreen.bOpen;
            bool gameover_flag = gui->gameover;
            fprintf(stderr, "[Reset] dismiss attempt=%d goOpen=%d gameover=%d gui=%p bOpen=%d bShowStats=%d bShowingCredits=%d alreadyWon=%d\n",
                    dismiss_attempt, goOpen, gameover_flag, (void*)gui,
                    gui->gameOverScreen.bOpen, gui->gameOverScreen.bShowStats,
                    gui->gameOverScreen.bShowingCredits, gui->alreadyWon);

            if (goOpen || gameover_flag) {
                fprintf(stderr, "[Reset] clearing game-over state...\n");
                gui->gameOverScreen.bOpen = false;
                fprintf(stderr, "[Reset]   bOpen = false OK\n");
                gui->gameOverScreen.bShowStats = false;
                fprintf(stderr, "[Reset]   bShowStats = false OK\n");
                gui->gameOverScreen.bShowingCredits = false;
                fprintf(stderr, "[Reset]   bShowingCredits = false OK\n");
                gui->gameover = false;
                fprintf(stderr, "[Reset]   gameover = false OK\n");
                gui->alreadyWon = false;
                fprintf(stderr, "[Reset]   alreadyWon = false OK\n");
                fprintf(stderr, "[Reset] calling menu.Open()...\n");
                menu.Open();
                fprintf(stderr, "[Reset] menu.Open() returned OK → menu.bOpen=%d\n", menu.bOpen);
            }
            // else: wait passively for death animation (~210 frames)
        }

        dismiss_attempt++;
        auto_start_wait = 10;

        if (dismiss_attempt > 60) {
            fprintf(stderr, "[Reset] game-over dismiss failed after 60 attempts → forcing menu.Open() → state 0\n");
            // Force menu open since game-over screen never appeared.
            // Clear any lingering game-over state just in case.
            if (gui) {
                gui->gameOverScreen.bOpen = false;
                gui->gameover = false;
            }
            menu.Open();
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
        fprintf(stderr, "[Auto] state 4: pressing key '1' to dismiss event\n");
        this->OnKeyDown(static_cast<SDLKey>(0x31)); // SDLK_1
        this->OnKeyUp(static_cast<SDLKey>(0x31));
        fprintf(stderr, "[Auto] state 4: dismissed event → state 5\n");
        auto_start_state = 5;
        auto_start_wait = 3;
    }
    else if (auto_start_state == 5) {
        if (--auto_start_wait > 0) return;
        auto_start_wait = 3;

        Global* g = Global::GetInstance();
        if (!g) {
            fprintf(stderr, "[Auto] state 5: WARN Global is NULL, waiting\n");
            return;
        }
        ShipManager* enemy = g->GetShipManager(1);

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
        ShipManager* player_check = g->GetShipManager(0);
        if (enemy && !enemy->bDestroyed && player_check && player_check->hostile_ship) return;

        // If FTL charged, jump to next beacon
        ShipManager* player = g->GetShipManager(0);
        {
            static int jump_diag = 0;
            if (player && ++jump_diag >= 300) {
                jump_diag = 0;
                fprintf(stderr, "[Nav] jump_timer=%.1f/%.1f paused=%d choiceBox=%d fuel=%d\n",
                        player->jump_timer.first, player->jump_timer.second,
                        gui ? gui->bPaused : -1,
                        gui ? gui->choiceBoxOpen : -1,
                        player->fuel_count);
            }
        }
        // Post-restart cooldown: wait for game to fully initialize after LOSS recovery
        if (post_restart_cooldown > 0) {
            post_restart_cooldown--;
            if (post_restart_cooldown % 60 == 0) {
                fprintf(stderr, "[Auto] post_restart_cooldown=%d\n", post_restart_cooldown);
            }
            return;
        }

        if (player && player->jump_timer.first >= player->jump_timer.second
            && player->jump_timer.second > 0) {
            // Null-guard world before accessing starMap
            WorldManager* w = g->GetWorld();
            if (!w) {
                fprintf(stderr, "[Auto] state 5: WARN world is NULL, cannot jump\n");
                return;
            }
            StarMap& starMap = w->starMap;
            if (!starMap.currentLoc) {
                fprintf(stderr, "[Auto] state 5: WARN starMap.currentLoc is NULL\n");
                return;
            }
            if (starMap.currentLoc->connectedLocations.empty()) {
                fprintf(stderr, "[Auto] state 5: WARN no connected locations\n");
                return;
            }
            int num_connected = starMap.currentLoc->connectedLocations.size();
            int idx = rand() % num_connected;
            Location* target = starMap.currentLoc->connectedLocations[idx];
            if (!target) {
                fprintf(stderr, "[Auto] state 5: WARN target location is NULL (idx=%d/%d)\n", idx, num_connected);
                return;
            }
            if (player->fuel_count > 0) {
                player->fuel_count--;
            }
            fprintf(stderr, "[Auto] calling TravelToLocation on target=%p starMap=%p connected=%d\n",
                    (void*)target, (void*)&starMap, num_connected);
            starMap.TravelToLocation(target);
            fprintf(stderr, "[Auto] TravelToLocation returned OK\n");
            player->jump_timer.first = 0.0f;
            fprintf(stderr, "[Auto] jumped to beacon (fuel=%d)\n", player->fuel_count);
            // After jumping, wait longer to let the event system fully process
            // the new location (load events, resolve encounters, etc.)
            auto_start_wait = 180;  // ~3s at 60fps (was 60)
        }
    }
}

// --- Prevent focus-loss from stopping game updates ---
// altpause=0 in settings.ini prevents visual pause.
// This hook prevents the engine from entering "unfocused" state
// which skips ship updates (ShipManager::OnLoop stops firing).
HOOK_METHOD(CApp, OnInputBlur, () -> void) {
    // Don't call super() — skip the engine's unfocus handling
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
