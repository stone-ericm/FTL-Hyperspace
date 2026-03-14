// bridge/bridge_actions.cpp
#include "bridge.h"
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

namespace ftl_rl {

// ============================================================================
// ACTION HEAD INDEX LAYOUT (matches action spec YAML)
// ============================================================================
// Phase 1: Combat Core (33 heads)
//   [0-3]   weapon_0..3_fire_target  (42 options each)
//   [4-7]   weapon_0..3_beam_path    (81 options each)
//   [8-22]  power_0..14_target       (variable options)
//   [23]    cloak_activate           (2 options)
//   [24]    hack_target_system       (17 options)
//   [25]    mc_target_crew           (18 options)
//   [26]    teleport_command         (42 options)
//   [27]    battery_activate         (2 options)
//   [28]    ftl_command              (4 options)
//   [29-32] drone_0..3_deploy       (3 options each)
//
// Phase 2: Crew & Doors (48 heads)
//   [33-40] crew_0..7_destination    (82 options each)
//   [41-80] room_0..39_vent_command  (3 options each)
//
// Phase 3: Strategic (4 heads)
//   [81]    beacon_selection         (30 options)
//   [82]    event_choice             (7 options)
//   [83]    store_buy                (25 options)
//   [84]    store_sell               (12 options)

// ============================================================================
// WEAPON FIRE (heads 0-3)
// ============================================================================
static void applyWeaponFire(int weapon_idx, int32_t action, ShipManager* player) {
    if (action == 0) return; // hold

    auto* wpnSys = player->weaponSystem;
    if (!wpnSys || weapon_idx >= static_cast<int>(wpnSys->weapons.size())) return;
    auto* wpn = wpnSys->weapons[weapon_idx];
    if (!wpn || !wpn->powered) return;

    if (action == 41) {
        wpn->autoFiring = !wpn->autoFiring;
        return;
    }

    // action 1-40 = fire at enemy room (action - 1 = room_id)
    int target_room = action - 1;
    wpn->autoFiring = true;
    wpn->targetId = target_room;

    // Set target point from enemy room geometry
    ShipManager* enemy = Global::GetInstance()->GetShipManager(1);
    if (enemy && target_room < static_cast<int>(enemy->ship.vRoomList.size())) {
        Room* room = enemy->ship.vRoomList[target_room];
        if (room) {
            Pointf center;
            center.x = room->rect.x + room->rect.w / 2.0f;
            center.y = room->rect.y + room->rect.h / 2.0f;
            wpn->targets.clear();
            wpn->targets.push_back(center);
        }
    }
}

// ============================================================================
// BEAM PATH (heads 4-7) — persistent
// ============================================================================
static void applyBeamPath(int weapon_idx, int32_t action, int32_t* persistent) {
    // action 0 = no_change (use persistent value)
    // action 1-80 = set beam path index
    // Stored in persistent_actions_ for use when beam fires
    (void)weapon_idx;
    (void)action;
    (void)persistent;
    // Beam path selection is stored, not applied immediately.
    // When a beam weapon fires (via applyWeaponFire), the stored path index
    // is used to determine the beam trajectory.
}

// ============================================================================
// POWER ALLOCATION (heads 8-22)
// ============================================================================

// System index order matching action spec:
// 0=shields, 1=engines, 2=oxygen, 3=weapons, 4=drones, 5=medbay,
// 6=clonebay, 7=teleporter, 8=cloaking, 9=hacking, 10=mind_control,
// 11=artillery, 12=battery, 13=piloting, 14=sensors

// Default depriority order: sensors, piloting, oxygen, medbay, clonebay,
// drones, teleporter, mind_control, cloaking, engines, shields, weapons,
// artillery, battery, hacking
static constexpr int DEPRIORITY_ORDER[] = {
    14, 13, 2, 5, 6, 4, 7, 10, 8, 1, 0, 3, 11, 12, 9
};

void Bridge::allocatePower(const int32_t* power_targets, ShipManager* ship) {
    if (!ship) return;

    // Decode targets: action value 0 = no_change, N = power level (N-1)
    int current[15] = {};
    int max_levels[15] = {};
    int requested[15] = {};
    int zoltan_power[15] = {};  // free per-system power from Zoltan crew

    for (int i = 0; i < 15; i++) {
        // FIXME_ACCESSOR: Get current, max, and Zoltan power for system i
        // auto* sys = ship->GetSystemByIndex(i);
        // current[i] = sys ? sys->GetEffectivePower() : 0;
        // max_levels[i] = sys ? sys->GetMaxPower() : 0;
        // zoltan_power[i] = sys ? sys->GetZoltanPower() : 0;
        ShipSystem* sys = (i < static_cast<int>(ship->vSystemList.size()))
            ? ship->vSystemList[i] : nullptr;
        current[i] = sys ? sys->GetEffectivePower() : 0;
        max_levels[i] = sys ? sys->maxLevel : 0;
        zoltan_power[i] = 0; // TODO: derive from Zoltan crew

        int target_action = power_targets[i];
        if (target_action == 0) {
            // no_change
            requested[i] = current[i];
        } else {
            // action N = power level (N - 1)
            int desired = target_action - 1;
            requested[i] = std::min(desired, max_levels[i]);
            requested[i] = std::max(requested[i], 0);
        }
    }

    // Subtract Zoltan power (free, doesn't use reactor bars)
    int reactor_demand = 0;
    for (int i = 0; i < 15; i++) {
        reactor_demand += std::max(0, requested[i] - zoltan_power[i]);
    }

    PowerManager* pm = PowerManager::GetPowerManager(ship->iShipId);
    int reactor = pm ? pm->currentPower.second : 8;
    int battery = pm ? pm->batteryPower.first : 0;
    int effective_capacity = reactor + battery;

    if (reactor_demand > effective_capacity) {
        // Over budget: reduce by depriority order
        int excess = reactor_demand - effective_capacity;
        for (int idx : DEPRIORITY_ORDER) {
            if (excess <= 0) break;
            // Can only reduce reactor-sourced portion (not Zoltan power)
            int reducible = std::max(0, requested[idx] - zoltan_power[idx]);
            int reduce = std::min(reducible, excess);
            requested[idx] -= reduce;
            excess -= reduce;
        }
    }

    // Apply power changes
    for (int i = 0; i < 15; i++) {
        if (requested[i] != current[i]) {
            int diff = requested[i] - current[i];
            if (diff > 0) {
                for (int d = 0; d < diff; d++) ship->IncreaseSystemPower(i);
            } else {
                for (int d = 0; d < -diff; d++) ship->ForceDecreaseSystemPower(i);
            }
        }
    }
}

// ============================================================================
// SYSTEM ACTIVATIONS (heads 23-28)
// ============================================================================
static void applySystemActivations(const int32_t* actions, ShipManager* player) {
    // [23] cloak_activate: 0=no action, 1=activate
    if (actions[23] == 1) {
        // FIXME_ACCESSOR: player->cloakSystem->Activate();
    }

    // [24] hack_target_system: 0=no action, 1-15=target system, 16=activate
    if (actions[24] > 0 && actions[24] <= 15) {
        // FIXME_ACCESSOR: player->hackingSystem->SetTarget(actions[24] - 1);
    } else if (actions[24] == 16) {
        // FIXME_ACCESSOR: player->hackingSystem->Activate();
    }

    // [25] mc_target_crew: 0=no action, 1-16=target crew, 17=deactivate
    if (actions[25] > 0 && actions[25] <= 16) {
        // FIXME_ACCESSOR: player->mindSystem->SetTarget(actions[25] - 1);
    } else if (actions[25] == 17) {
        // FIXME_ACCESSOR: player->mindSystem->Deactivate();
    }

    // [26] teleport_command: 0=no action, 1-40=room, 41=recall
    if (actions[26] > 0 && actions[26] <= 40) {
        // FIXME_ACCESSOR: player->teleportSystem->InitiateTeleport(actions[26] - 1);
    } else if (actions[26] == 41) {
        // FIXME_ACCESSOR: player->teleportSystem->Recall();
    }

    // [27] battery_activate: 0=no action, 1=activate
    if (actions[27] == 1) {
        // FIXME_ACCESSOR: player->batterySystem->Activate();
    }

    // [28] ftl_command: 0=no action, 1=begin charge, 2=jump, 3=abort
    if (actions[28] == 1) {
        // FIXME_ACCESSOR: Begin FTL charge
    } else if (actions[28] == 2) {
        // FIXME_ACCESSOR: Execute FTL jump
    } else if (actions[28] == 3) {
        // FIXME_ACCESSOR: Abort FTL charge
    }
}

// ============================================================================
// DRONE DEPLOYMENT (heads 29-32)
// ============================================================================
static void applyDroneDeployment(const int32_t* actions, ShipManager* player) {
    for (int i = 0; i < 4; i++) {
        int action = actions[29 + i];
        if (action == 0) continue; // no_change

        // FIXME_ACCESSOR: Get drone from DroneSystem
        // auto* droneSys = player->droneSystem;
        // if (!droneSys || i >= droneSys->drones.size()) continue;
        // auto* drone = droneSys->drones[i];

        if (action == 1) {
            // Deploy (power + deploy)
            // FIXME_ACCESSOR: drone->SetPowered(true); drone->SetDeployed(true);
        } else if (action == 2) {
            // Depower
            // FIXME_ACCESSOR: drone->SetPowered(false);
        }
    }
}

// ============================================================================
// CREW MOVEMENT (heads 33-40) — persistent
// ============================================================================
static void applyCrewMovement(const int32_t* actions, const int32_t* persistent,
                               ShipManager* player) {
    for (int i = 0; i < 8; i++) {
        int action = persistent[33 + i]; // use persistent (0 = no_change already resolved)
        if (action == 0) continue;

        // FIXME_ACCESSOR: Get crew member
        // if (i >= player->vCrewList.size()) continue;
        // auto* crew = player->vCrewList[i];

        if (action >= 1 && action <= 40) {
            // Move to player room (action - 1)
            int room_id = action - 1;
            // FIXME_ACCESSOR: crew->MoveToRoom(room_id, -1, false);
            (void)room_id;
        } else if (action >= 41 && action <= 80) {
            // Move to enemy room (action - 41)
            int enemy_room = action - 41;
            // FIXME_ACCESSOR: crew->MoveToRoom(enemy_room, -1, true); // on enemy ship
            (void)enemy_room;
        } else if (action == 81) {
            // Return to teleporter
            // FIXME_ACCESSOR: Move crew to teleporter room
        }
    }
}

// ============================================================================
// VENT/SEAL DOORS (heads 41-80) — persistent
// ============================================================================

// Crew-aware BFS for vent pathfinding.
// See tests/test_bridge_algorithms.py::find_vent_path for reference implementation.
void Bridge::applyVentCommand(int room_id, bool vent, ShipManager* ship) {
    if (!ship) return;

    if (!vent) {
        // Seal: close all doors adjacent to this room
        // FIXME_ACCESSOR: iterate ship doors, close any connected to room_id
        return;
    }

    // Vent: BFS from room_id to nearest vacuum, avoiding friendly crew
    // FIXME_ACCESSOR: Build adjacency graph from ship rooms/doors
    // FIXME_ACCESSOR: Identify vacuum rooms (rooms with hull breaches or open airlocks)
    // FIXME_ACCESSOR: Count friendly crew per room

    // Use weighted BFS (same algorithm as Python prototype):
    // Edge cost = 1 + 100 * friendly_crew_in_neighbor
    // Find shortest path to vacuum room
    // Open doors along path, close branching doors

    // See tests/test_bridge_algorithms.py::find_vent_path for the complete algorithm.
    // Port that implementation here with game-specific accessors.
}

static void applyVentSeal(const int32_t* persistent, ShipManager* player) {
    // Two-pass: collect vent doors first, then process seals excluding vent doors.
    // Conflict resolution: vent takes priority over seal (spec requirement).

    // Pass 1: Process all vents, collect door IDs used by vent paths
    // (applyVentCommand stores opened doors in a per-step set)
    for (int i = 0; i < 40; i++) {
        int action = persistent[41 + i];
        if (action == 1) { // vent
            Bridge::applyVentCommand(i, true, player);
        }
    }

    // Pass 2: Process seals, excluding doors used by active vent paths
    for (int i = 0; i < 40; i++) {
        int action = persistent[41 + i];
        if (action == 2) { // seal
            Bridge::applyVentCommand(i, false, player);
            // Note: applyVentCommand(seal) must check against active vent doors
            // (see Python prototype find_seal_doors active_vent_doors parameter)
        }
    }
}

// ============================================================================
// STRATEGIC ACTIONS (heads 81-84)
// ============================================================================
static void applyStrategic(const int32_t* actions, ShipManager* player) {
    // [81] beacon_selection: 0=no action, 1-29=beacon index
    if (actions[81] > 0) {
        int beacon = actions[81] - 1;
        // FIXME_ACCESSOR: StarMap::SelectBeacon(beacon);
        (void)beacon;
    }

    // [82] event_choice: 0=no action, 1-6=choice index
    if (actions[82] > 0) {
        int choice = actions[82] - 1;
        // FIXME_ACCESSOR: ChoiceBox::SelectChoice(choice);
        (void)choice;
    }

    // [83] store_buy: 0=leave store, 1-24=buy slot
    if (actions[83] > 0) {
        int slot = actions[83]; // 1-indexed in action, map to store slot
        // FIXME_ACCESSOR: Store::Purchase(slot);
        (void)slot;
    }

    // [84] store_sell: 0=no action, 1-11=sell slot
    if (actions[84] > 0) {
        int slot = actions[84]; // 1-indexed in action
        // FIXME_ACCESSOR: Store::Sell(slot);
        (void)slot;
    }
}

// ============================================================================
// MAIN DISPATCH
// ============================================================================
void Bridge::applyActions(const int32_t* actions, ShipManager* player, ShipManager* enemy) {
    if (!player) return;
    (void)enemy; // enemy used for targeting validation

    // Phase 1: Combat Core
    for (int i = 0; i < 4; i++) applyWeaponFire(i, actions[i], player);
    // Beam paths (heads 4-7) are stored in persistent_actions_, used on fire
    allocatePower(actions + 8, player);  // heads 8-22
    applySystemActivations(actions, player);
    applyDroneDeployment(actions, player);

    // Phase 2: Crew & Doors
    applyCrewMovement(actions, persistent_actions_, player);
    applyVentSeal(persistent_actions_, player);

    // Phase 3: Strategic
    applyStrategic(actions, player);
}

} // namespace ftl_rl
