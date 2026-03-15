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

// Cached enemy pointer — set by applyActions, read by applyWeaponFire.
// volatile: cross-compiler was optimizing away the read.
static volatile ShipManager* s_current_enemy = nullptr;

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
    // Get enemy from Bridge class member (set in doStep where GetShipManager(1) works)
    ShipManager* enemy = Bridge::cached_enemy_;
    fprintf(stderr, "[Weapon] W%d: Bridge::cached_enemy_=%p\n", weapon_idx, (void*)enemy);

    auto* wpnSys = player->weaponSystem;
    if (!wpnSys) {
        fprintf(stderr, "[Weapon] W%d: no weaponSystem\n", weapon_idx);
        return;
    }
    if (weapon_idx >= static_cast<int>(wpnSys->weapons.size())) {
        fprintf(stderr, "[Weapon] W%d: idx >= weapons.size(%d)\n", weapon_idx, (int)wpnSys->weapons.size());
        return;
    }
    auto* wpn = wpnSys->weapons[weapon_idx];
    if (!wpn) {
        fprintf(stderr, "[Weapon] W%d: weapon ptr is null\n", weapon_idx);
        return;
    }
    if (!wpn->powered) {
        fprintf(stderr, "[Weapon] W%d: not powered (action=%d)\n", weapon_idx, action);
        return;
    }

    fprintf(stderr, "[Weapon] W%d: powered, action=%d\n", weapon_idx, action);

    if (action == 41) {
        wpn->autoFiring = !wpn->autoFiring;
        return;
    }

    // action 1-40 = fire at enemy room (action - 1 = room_id)
    int target_room = action - 1;

    fprintf(stderr, "[Weapon] W%d: pre-null-check enemy=%p\n", weapon_idx, (void*)enemy);
    if (!enemy) {
        fprintf(stderr, "[Weapon] W%d: no enemy ship! (was %p at read)\n", weapon_idx, (void*)Bridge::cached_enemy_);
        return;
    }
    fprintf(stderr, "[Weapon] W%d: PASSED null check, enemy=%p\n", weapon_idx, (void*)enemy);

    // FIX: _targetable is a MEMBER of ShipManager, not a base class.
    fprintf(stderr, "[Weapon] W%d: setting currentShipTarget to &enemy->_targetable\n", weapon_idx);
    wpn->currentShipTarget = &enemy->_targetable;
    wpn->targetId = target_room;
    wpn->autoFiring = true;
    fprintf(stderr, "[Weapon] W%d: set targetId=%d, autoFiring=true\n", weapon_idx, target_room);

    // Compute target point from enemy room geometry
    // ShipGraph::ConvertToWorldPosition converts local→world coords.
    Pointf world = {0.0f, 0.0f};
    if (target_room < static_cast<int>(enemy->ship.vRoomList.size())) {
        auto* room = enemy->ship.vRoomList[target_room];
        if (room) {
            Pointf local;
            local.x = room->rect.x + room->rect.w / 2.0f;
            local.y = room->rect.y + room->rect.h / 2.0f;
            ShipGraph* graph = ShipGraph::GetShipInfo(enemy->iShipId);
            if (graph) {
                world = graph->ConvertToWorldPosition(local);
            }
        }
    }
    fprintf(stderr, "[Weapon] W%d: target point (%.1f, %.1f) room %d\n",
            weapon_idx, world.x, world.y, target_room);
    wpn->targets.clear();
    wpn->targets.push_back(world);

    // Fire directly when ready (mirrors CombatAI::UpdateWeapons approach)
    fprintf(stderr, "[Weapon] W%d: checking ReadyToFire (cooldown=%.1f/%.1f)...\n",
            weapon_idx, wpn->cooldown.first, wpn->cooldown.second);
    if (wpn->ReadyToFire()) {
        std::vector<Pointf> firePoints;
        firePoints.push_back(world);
        fprintf(stderr, "[Weapon] W%d: FIRE at room %d!\n", weapon_idx, target_room);
        wpn->Fire(firePoints, target_room);
        fprintf(stderr, "[Weapon] W%d: Fire() returned OK\n", weapon_idx);
    } else {
        fprintf(stderr, "[Weapon] weapon %d targeting room %d (not ready, cooldown=%.1f/%.1f)\n",
                weapon_idx, target_room, wpn->cooldown.first, wpn->cooldown.second);
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

// Observation spec slot → FTL SystemId mapping (same as bridge_state.cpp).
static constexpr int SLOT_TO_SYSID[] = {
    0, 1, 2, 3, 4, 5,  // shields, engines, oxygen, weapons, drones, medbay
    9, 10, 14, 15,      // teleporter, cloaking, mind_control, hacking
    6, 7, 8,            // piloting, sensors, doors
    12, 11,             // battery, artillery
};

void Bridge::allocatePower(const int32_t* power_targets, ShipManager* ship) {
    if (!ship) return;

    // Decode targets: action value 0 = no_change, N = power level (N-1)
    int current[15] = {};
    int max_levels[15] = {};
    int requested[15] = {};
    int zoltan_power[15] = {};  // free per-system power from Zoltan crew

    for (int i = 0; i < 15; i++) {
        int sysId = SLOT_TO_SYSID[i];
        ShipSystem* sys = ship->GetSystem(sysId);
        // Slot 5: medbay/clonebay fallback
        if (i == 5 && !sys) sys = ship->GetSystem(13); // SYS_CLONEBAY
        current[i] = sys ? sys->GetEffectivePower() : 0;
        max_levels[i] = sys ? sys->powerState.second : 0; // current upgrade level, not global cap
        zoltan_power[i] = 0; // TODO: derive from Zoltan crew

        int target_action = power_targets[i];
        if (target_action == 0) {
            requested[i] = current[i];
        } else {
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
            int reducible = std::max(0, requested[idx] - zoltan_power[idx]);
            int reduce = std::min(reducible, excess);
            requested[idx] -= reduce;
            excess -= reduce;
        }
    }

    // Apply power changes — use FTL system IDs, not observation slot indices
    for (int i = 0; i < 15; i++) {
        if (requested[i] != current[i]) {
            int sysId = SLOT_TO_SYSID[i];
            if (i == 5 && !ship->GetSystem(sysId))
                sysId = 13; // SYS_CLONEBAY fallback
            ShipSystem* targetSys = ship->GetSystem(sysId);
            if (!targetSys) {
                fprintf(stderr, "[Power] slot %d sysId %d: system nullptr, skipping\n", i, sysId);
                continue;
            }
            int diff = requested[i] - current[i];
            fprintf(stderr, "[Power] slot %d sysId %d: %d -> %d (diff %d)\n",
                    i, sysId, current[i], requested[i], diff);
            if (diff > 0) {
                for (int d = 0; d < diff; d++) {
                    fprintf(stderr, "[Power]   IncreaseSystemPower(%d) call %d\n", sysId, d);
                    ship->IncreaseSystemPower(sysId);
                }
            } else {
                for (int d = 0; d < -diff; d++) {
                    fprintf(stderr, "[Power]   ForceDecreaseSystemPower(%d) call %d\n", sysId, d);
                    ship->ForceDecreaseSystemPower(sysId);
                }
            }
            fprintf(stderr, "[Power] slot %d done\n", i);
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

    // Phase 1: Combat Core
    s_current_enemy = enemy;
    fprintf(stderr, "[Bridge] applyWeaponFire (s_current_enemy=%p)...\n", (void*)s_current_enemy);
    for (int i = 0; i < 4; i++) applyWeaponFire(i, actions[i], player);
    fprintf(stderr, "[Bridge] allocatePower...\n");
    // Beam paths (heads 4-7) are stored in persistent_actions_, used on fire
    allocatePower(actions + 8, player);  // heads 8-22
    fprintf(stderr, "[Bridge] applySystemActivations...\n");
    applySystemActivations(actions, player);
    fprintf(stderr, "[Bridge] applyDroneDeployment...\n");
    applyDroneDeployment(actions, player);

    // Phase 2: Crew & Doors
    fprintf(stderr, "[Bridge] applyCrewMovement...\n");
    applyCrewMovement(actions, persistent_actions_, player);
    fprintf(stderr, "[Bridge] applyVentSeal...\n");
    applyVentSeal(persistent_actions_, player);

    // Phase 3: Strategic
    fprintf(stderr, "[Bridge] applyStrategic...\n");
    applyStrategic(actions, player);
    fprintf(stderr, "[Bridge] applyActions done\n");
}

} // namespace ftl_rl
