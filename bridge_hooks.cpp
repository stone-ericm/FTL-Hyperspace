// bridge_hooks.cpp
// ZHL hook wrappers connecting FTL game events to the RL bridge.
// Thin shims — all logic lives in Bridge class methods.

#include "zhl.h"
#include "FTLGame.h"
#include "Global.h"
#include "bridge.h"

static bool bridge_initialized = false;

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

// B.1: OnInit, CreateShip, and JumpLeave hooks disabled.
// OnInit fires during ship selection (not just game start), which
// triggers handleReset() at the wrong time. These hooks need careful
// timing guards before enabling — deferred to B.2/B.3.
