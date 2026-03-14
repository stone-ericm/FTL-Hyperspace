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

// --- New game / load: reset bridge state ---
HOOK_METHOD(ShipManager, OnInit, (ShipBlueprint *bp, int shipLevel) -> int) {
    int result = super(bp, shipLevel);

    // Only trigger on player ship
    if (this == Global::GetInstance()->GetShipManager(0)) {
        ftl_rl::Bridge::onRunStart(true);
    }

    return result;
}

// --- Enemy ship created: compute beam paths ---
HOOK_METHOD(WorldManager, CreateShip, (ShipEvent *shipEvent, bool boss) -> CompleteShip *) {
    CompleteShip *ship = super(shipEvent, boss);
    ftl_rl::Bridge::onEncounterStart();
    return ship;
}

// --- Jump leave: detect flee during combat ---
HOOK_METHOD(ShipManager, JumpLeave, () -> void) {
    // If this is the player ship, notify bridge
    if (this == Global::GetInstance()->GetShipManager(0)) {
        ftl_rl::Bridge::onJumpLeave(0);
    }
    super();
}
