// bridge_state.cpp — State serialization (game objects → float32 buffer)
// Fills the observation vector from live Hyperspace game state.
// Sections follow CANONICAL ORDER from observation spec YAML.

#include "bridge.h"
#include <cstring>
#include <cstdio>

#define G_ Global::GetInstance()

namespace ftl_rl {

void Bridge::serializeState(float* buf, ShipManager* player,
                            ShipManager* enemy, SpaceManager* space) {
    (void)space; // SpaceManager access via G_->GetWorld() where needed
    memset(buf, 0, STATE_BUFFER_BYTES); // zero-fill, then overwrite known fields
    if (!player) return;

    size_t idx = 0;
    PowerManager* powerMan = PowerManager::GetPowerManager(player->iShipId);

    // --- player_resources (4 fields) ---
    buf[idx++] = static_cast<float>(player->currentScrap);
    buf[idx++] = static_cast<float>(player->fuel_count);
    buf[idx++] = static_cast<float>(player->weaponSystem ? player->weaponSystem->missile_count : 0);
    buf[idx++] = static_cast<float>(player->droneSystem ? player->droneSystem->drone_count : 0);

    // --- player_ship (25 fields) ---
    buf[idx++] = static_cast<float>(player->ship.hullIntegrity.first);  // hull_current
    buf[idx++] = static_cast<float>(player->ship.hullIntegrity.second); // hull_max
    if (player->shieldSystem) {
        buf[idx++] = static_cast<float>(player->shieldSystem->shields.power.first); // shield_layers
        buf[idx++] = static_cast<float>(player->shieldSystem->shields.charger);     // shield_charge
        buf[idx++] = static_cast<float>(player->shieldSystem->chargeTime);          // shield_charge_time_base
        buf[idx++] = static_cast<float>(player->shieldSystem->shields_shutdown);    // shields_shutdown
        buf[idx++] = static_cast<float>(player->shieldSystem->bExcessChargeHack);   // shield_excess_charge_hack
        buf[idx++] = static_cast<float>(player->shieldSystem->shields.power.super.first);  // super_shield_hp
        buf[idx++] = static_cast<float>(player->shieldSystem->shields.power.super.second); // super_shield_max
        buf[idx++] = static_cast<float>(player->shieldSystem->shields.superTimer);  // super_shield_timer
    } else {
        idx += 8;
    }
    buf[idx++] = static_cast<float>(player->GetDodgeFactor()); // evade_chance_raw (best available)
    buf[idx++] = static_cast<float>(player->GetDodgeFactor()); // effective_evade_chance
    buf[idx++] = static_cast<float>(player->failedDodgeCounter);
    if (powerMan) {
        buf[idx++] = static_cast<float>(powerMan->currentPower.second);  // reactor_total
        buf[idx++] = static_cast<float>(powerMan->currentPower.first);   // reactor_used
        buf[idx++] = static_cast<float>(powerMan->currentPower.second - powerMan->currentPower.first); // reactor_free
        buf[idx++] = static_cast<float>(powerMan->iTempPowerLoss);
        buf[idx++] = static_cast<float>(powerMan->iTempPowerCap);
        buf[idx++] = static_cast<float>(powerMan->over_powered);
    } else {
        idx += 6;
    }
    if (player->oxygenSystem) {
        // fTotalOxygen is a 0-1 ratio; spec expects 0-100 percentage
        buf[idx++] = player->oxygenSystem->fTotalOxygen * 100.0f;
        buf[idx++] = static_cast<float>(player->oxygenSystem->bLeakingO2);
    } else {
        idx += 2;
    }
    buf[idx++] = 0.0f; // game_phase — TODO: derive from WorldManager
    // has_boarders_on_enemy: check if any player crew is on enemy ship
    {
        int boarders = 0;
        for (size_t c = 0; c < player->vCrewList.size(); c++) {
            if (player->vCrewList[c] && player->vCrewList[c]->currentShipId == 1)
                boarders++;
        }
        buf[idx++] = static_cast<float>(boarders > 0 ? 1 : 0);
    }
    // artillery_charge_progress + artillery_cooldown_base
    if (!player->artillerySystems.empty() && player->artillerySystems[0]) {
        // Artillery inherits from ShipSystem — no direct charge progress
        buf[idx++] = 0.0f; // TODO: artillery charge ratio
        buf[idx++] = 0.0f; // TODO: artillery cooldown base
    } else {
        idx += 2;
    }

    // --- systems (15 slots × 12 fields = 180) ---
    // Observation spec slot → FTL SystemId mapping.
    // Slots 0-5 match, 6+ diverge (FTL puts pilot/sensors/doors at 6-8).
    // Slot 5 is medbay_or_clonebay: try medbay first, fall back to clonebay.
    static constexpr int SLOT_TO_SYSID[] = {
        0, 1, 2, 3, 4, 5,  // shields, engines, oxygen, weapons, drones, medbay
        9, 10, 14, 15,      // teleporter, cloaking, mind_control, hacking
        6, 7, 8,            // piloting, sensors, doors
        12, 11,             // battery, artillery
    };
    for (int i = 0; i < 15; i++) {
        ShipSystem* sys = player->GetSystem(SLOT_TO_SYSID[i]);
        // Slot 5: medbay/clonebay — ships have one or the other
        if (i == 5 && !sys) sys = player->GetSystem(13); // SYS_CLONEBAY
        if (!sys) { idx += 12; continue; }
        buf[idx++] = static_cast<float>(sys->powerState.first);   // power_allocated
        buf[idx++] = static_cast<float>(sys->maxLevel);           // max_level
        // physical_damage = max_health - current_health (healthState.first is health remaining)
        buf[idx++] = static_cast<float>(sys->healthState.second - sys->healthState.first);
        buf[idx++] = static_cast<float>(sys->iLockCount);         // ion_damage
        buf[idx++] = static_cast<float>(sys->lockTimer.currTime); // ion_timer
        buf[idx++] = static_cast<float>(sys->GetEffectivePower()); // effective_power
        buf[idx++] = static_cast<float>(sys->iHackEffect);        // is_hacked
        // hack_duration_remaining — from ship's hacking system if targeting this system
        if (player->hackingSystem && player->hackingSystem->currentSystem == sys) {
            buf[idx++] = static_cast<float>(player->hackingSystem->effectTimer.first);
        } else {
            buf[idx++] = 0.0f;
        }
        buf[idx++] = static_cast<float>(sys->fRepairOverTime);    // repair_progress
        buf[idx++] = static_cast<float>(sys->iActiveManned);      // active_manned_level
        buf[idx++] = 0.0f; // zoltan_power_contribution — TODO: derive from crew
        buf[idx++] = 1.0f; // system_present
    }
    // medbay_clonebay_type_flag
    buf[idx++] = static_cast<float>(player->cloneSystem ? 1 : 0);

    // --- cloaking (5 fields) ---
    if (player->cloakSystem) {
        buf[idx++] = static_cast<float>(player->cloakSystem->bTurnedOn);
        buf[idx++] = static_cast<float>(player->cloakSystem->timer.currTime);
        buf[idx++] = static_cast<float>(player->cloakSystem->timer.currGoal);
        buf[idx++] = 0.0f; // cloak_cooldown_remaining — TODO
        buf[idx++] = 0.0f; // cloak_weapons_fired_during — TODO
    } else {
        idx += 5;
    }

    // --- hacking (12 fields) ---
    if (player->hackingSystem) {
        buf[idx++] = static_cast<float>(!player->hackingSystem->bArmed && player->hackingSystem->drone.deployed); // hacking_drone_launched
        buf[idx++] = 0.0f; // hacking_drone_in_transit — TODO
        buf[idx++] = static_cast<float>(player->hackingSystem->drone.arrived);
        buf[idx++] = 0.0f; // hacking_drone_position_x — TODO: needs SpaceDrone cast
        buf[idx++] = 0.0f; // hacking_drone_position_y
        buf[idx++] = static_cast<float>(player->hackingSystem->bArmed);
        buf[idx++] = static_cast<float>(player->hackingSystem->bCanHack);
        buf[idx++] = static_cast<float>(player->hackingSystem->bBlocked);
        buf[idx++] = static_cast<float>(player->hackingSystem->currentSystem
            ? player->hackingSystem->currentSystem->iSystemType : -1);
        buf[idx++] = static_cast<float>(player->hackingSystem->bHacking);
        buf[idx++] = static_cast<float>(player->hackingSystem->effectTimer.first);
        buf[idx++] = static_cast<float>(player->hackingSystem->effectTimer.second);
    } else {
        idx += 12;
    }

    // --- mind_control (6 fields) ---
    if (player->mindSystem) {
        buf[idx++] = static_cast<float>(player->mindSystem->controlTimer.first > 0.0f ? 1 : 0);
        buf[idx++] = static_cast<float>(player->mindSystem->controlTimer.first);
        buf[idx++] = static_cast<float>(player->mindSystem->controlTimer.second);
        buf[idx++] = static_cast<float>(player->mindSystem->iArmed);
        buf[idx++] = static_cast<float>(player->mindSystem->bCanUse);
        buf[idx++] = static_cast<float>(player->mindSystem->bSuperShields);
    } else {
        idx += 6;
    }

    // --- teleporter (6 fields) ---
    if (player->teleportSystem) {
        buf[idx++] = static_cast<float>(player->teleportSystem->chargeLevel);
        buf[idx++] = static_cast<float>(player->teleportSystem->bCanSend);
        buf[idx++] = static_cast<float>(player->teleportSystem->bCanReceive);
        buf[idx++] = static_cast<float>(player->teleportSystem->bSuperShields);
        buf[idx++] = static_cast<float>(player->teleportSystem->iArmed);
        buf[idx++] = static_cast<float>(player->teleportSystem->iPreparedCrew);
    } else {
        idx += 6;
    }

    // --- battery (5 fields) ---
    if (player->batterySystem) {
        buf[idx++] = static_cast<float>(player->batterySystem->bTurnedOn);
        buf[idx++] = static_cast<float>(player->batterySystem->timer.currTime);
        buf[idx++] = 0.0f; // battery_power_provided — TODO
        buf[idx++] = 0.0f; // battery_cooldown_remaining — TODO
        buf[idx++] = 0.0f; // battery_uses_remaining — TODO
    } else {
        idx += 5;
    }

    // --- weapons (4 slots × 34 fields = 136) ---
    for (int i = 0; i < 4; i++) {
        ProjectileFactory* wpn = (player->weaponSystem &&
            i < static_cast<int>(player->weaponSystem->weapons.size()))
            ? player->weaponSystem->weapons[i] : nullptr;
        if (!wpn) { idx += 34; continue; }
        buf[idx++] = 1.0f; // weapon_present
        buf[idx++] = static_cast<float>(wpn->blueprint->type);
        buf[idx++] = 0.0f; // subtype — TODO
        buf[idx++] = static_cast<float>(wpn->blueprint->power);
        // charge_progress as ratio
        buf[idx++] = (wpn->cooldown.second > 0.0f)
            ? (wpn->cooldown.first / wpn->cooldown.second) : 0.0f;
        buf[idx++] = static_cast<float>(wpn->chargeLevel);
        buf[idx++] = static_cast<float>(wpn->goalChargeLevel);
        buf[idx++] = static_cast<float>(wpn->boostLevel);
        buf[idx++] = static_cast<float>(wpn->powered);
        buf[idx++] = 0.0f; // retained_charge — TODO
        buf[idx++] = static_cast<float>(wpn->blueprint->cooldown);
        buf[idx++] = static_cast<float>(wpn->cooldownModifier);
        buf[idx++] = static_cast<float>(wpn->blueprint->damage.iDamage);
        buf[idx++] = static_cast<float>(wpn->blueprint->shots);
        buf[idx++] = static_cast<float>(wpn->blueprint->damage.fireChance);
        buf[idx++] = static_cast<float>(wpn->blueprint->damage.breachChance);
        buf[idx++] = static_cast<float>(wpn->blueprint->damage.iIonDamage);
        buf[idx++] = static_cast<float>(wpn->blueprint->damage.iSystemDamage);
        buf[idx++] = static_cast<float>(wpn->blueprint->damage.iPersDamage);
        buf[idx++] = static_cast<float>(wpn->blueprint->damage.iShieldPiercing);
        buf[idx++] = static_cast<float>(wpn->blueprint->damage.bHullBuster);
        buf[idx++] = static_cast<float>(wpn->blueprint->damage.stunChance);
        buf[idx++] = static_cast<float>(wpn->blueprint->damage.iStun);
        buf[idx++] = static_cast<float>(wpn->blueprint->damage.bLockdown);
        buf[idx++] = static_cast<float>(wpn->autoFiring);
        buf[idx++] = static_cast<float>(wpn->targetId); // target_room
        buf[idx++] = static_cast<float>(wpn->blueprint->missiles); // costs_missile
        buf[idx++] = static_cast<float>(wpn->iAmmo);
        buf[idx++] = static_cast<float>(wpn->blueprint->drone_targetable);
        buf[idx++] = static_cast<float>(wpn->isArtillery);
        buf[idx++] = static_cast<float>(wpn->subCooldown.first);
        buf[idx++] = static_cast<float>(wpn->subCooldown.second);
        buf[idx++] = static_cast<float>(wpn->currentEntryAngle); // beam_entry_angle
        buf[idx++] = static_cast<float>(wpn->blueprint->length); // beam_length
    }

    // --- crew (32 slots × 42 fields = 1344) ---
    for (int i = 0; i < 32; i++) {
        CrewMember* crew = (i < static_cast<int>(player->vCrewList.size()))
            ? player->vCrewList[i] : nullptr;
        if (!crew || crew->bDead) { idx += 42; continue; }
        buf[idx++] = 1.0f; // slot_occupied
        buf[idx++] = crew->health.first;
        buf[idx++] = crew->health.second;
        buf[idx++] = static_cast<float>(crew->healthBoost);
        buf[idx++] = static_cast<float>(crew->iRoomId);
        buf[idx++] = 0.0f; // target_room — TODO: derive from path
        buf[idx++] = static_cast<float>(crew->currentShipId);
        buf[idx++] = 0.0f; // species enum — TODO: string→int mapping
        buf[idx++] = 0.0f; // provides_room_power — TODO
        buf[idx++] = 0.0f; // move_speed — TODO
        buf[idx++] = 0.0f; // repair_speed — TODO
        buf[idx++] = 0.0f; // damage_multiplier — race-specific, not on CrewBlueprint
        buf[idx++] = 0.0f; // can_suffocate — race-specific
        buf[idx++] = 0.0f; // can_burn — race-specific
        buf[idx++] = 0.0f; // is_telepathic — race-specific
        buf[idx++] = 0.0f; // can_phase_through_doors — race-specific
        buf[idx++] = 0.0f; // resists_mind_control — race-specific
        buf[idx++] = static_cast<float>(crew->bActiveManning);
        buf[idx++] = static_cast<float>(crew->iManningId);
        buf[idx++] = 0.0f; // is_repairing — TODO: check member name
        buf[idx++] = static_cast<float>(crew->bFighting);
        buf[idx++] = static_cast<float>(crew->intruder);
        buf[idx++] = static_cast<float>(crew->bDead);
        // skills — TODO: find correct member path
        buf[idx++] = 0.0f; buf[idx++] = 0.0f; buf[idx++] = 0.0f;
        buf[idx++] = 0.0f; buf[idx++] = 0.0f; buf[idx++] = 0.0f;
        buf[idx++] = 0.0f; // is_stunned — TODO: check member
        buf[idx++] = static_cast<float>(crew->fStunTime);
        buf[idx++] = static_cast<float>(crew->bFrozen);
        buf[idx++] = 0.0f; // frozen_timer — TODO
        buf[idx++] = static_cast<float>(crew->bMindControlled);
        buf[idx++] = 0.0f; // mind_control_duration — TODO
        buf[idx++] = 0.0f; // is_suffocating — TODO: derive from room O2
        buf[idx++] = static_cast<float>(crew->iOnFire);
        buf[idx++] = 0.0f; // melee_target_id — TODO: crewTarget is a pointer
        buf[idx++] = static_cast<float>(crew->clone_ready);
        buf[idx++] = static_cast<float>(crew->fCloneDying);
        buf[idx++] = static_cast<float>(crew->fMindDamageBoost);
        buf[idx++] = 0.0f; // lockdown_ability_cooldown — TODO
    }

    // --- rooms (40 slots × 11 fields = 440) ---
    for (int i = 0; i < 40; i++) {
        Room* room = (i < static_cast<int>(player->ship.vRoomList.size()))
            ? player->ship.vRoomList[i] : nullptr;
        if (!room) { idx += 11; continue; }
        buf[idx++] = 1.0f; // room_active
        buf[idx++] = (player->oxygenSystem &&
            i < static_cast<int>(player->oxygenSystem->oxygenLevels.size()))
            ? player->oxygenSystem->oxygenLevels[i] : 100.0f;
        buf[idx++] = static_cast<float>(room->iFireCount);
        buf[idx++] = 0.0f; // fire_avg_death_timer — TODO
        buf[idx++] = 0.0f; // fire_avg_spread_timer — TODO
        buf[idx++] = 0.0f; // breach_count — TODO
        // system_id: find which system occupies this room
        {
            ShipSystem* roomSys = player->GetSystemInRoom(i);
            buf[idx++] = static_cast<float>(roomSys ? roomSys->iSystemType : -1);
        }
        buf[idx++] = 0.0f; // lockdown_active — no direct Room member
        buf[idx++] = 0.0f; // lockdown_timer — TODO
        buf[idx++] = static_cast<float>((room->rect.w / 35) * (room->rect.h / 35)); // room_size
        buf[idx++] = static_cast<float>(room->bStunning);
    }

    // --- enemy_room_positions (20 slots × 4 fields = 80) ---
    for (int i = 0; i < 20; i++) {
        Room* room = (enemy && i < static_cast<int>(enemy->ship.vRoomList.size()))
            ? enemy->ship.vRoomList[i] : nullptr;
        if (!room) { idx += 4; continue; }
        buf[idx++] = static_cast<float>(room->rect.x);
        buf[idx++] = static_cast<float>(room->rect.y);
        buf[idx++] = static_cast<float>(room->rect.w);
        buf[idx++] = static_cast<float>(room->rect.h);
    }

    // --- doors (60 slots × 9 fields = 540) ---
    for (int i = 0; i < 60; i++) {
        Door* door = (i < static_cast<int>(player->ship.vDoorList.size()))
            ? player->ship.vDoorList[i] : nullptr;
        if (!door) { idx += 9; continue; }
        buf[idx++] = 1.0f; // door_active
        buf[idx++] = static_cast<float>(door->health);
        buf[idx++] = static_cast<float>(door->baseHealth);
        buf[idx++] = static_cast<float>(door->bOpen);
        buf[idx++] = static_cast<float>(door->forcedOpen.running);
        buf[idx++] = static_cast<float>(door->bIoned);
        buf[idx++] = static_cast<float>(door->iRoom1);
        buf[idx++] = static_cast<float>(door->iRoom2);
        buf[idx++] = static_cast<float>(door->lockedDown.running);
    }

    // --- ship_topology (800 fields) ---
    idx += 800; // TODO: room adjacency matrix

    // --- drones (8 slots × 10 fields = 80) ---
    for (int i = 0; i < 8; i++) {
        Drone* drone = (player->droneSystem &&
            i < static_cast<int>(player->droneSystem->drones.size()))
            ? player->droneSystem->drones[i] : nullptr;
        if (!drone) { idx += 10; continue; }
        buf[idx++] = 1.0f; // drone_present
        buf[idx++] = static_cast<float>(drone->blueprint->power);
        buf[idx++] = static_cast<float>(drone->blueprint->type);
        buf[idx++] = 0.0f; // position_x — needs SpaceDrone cast
        buf[idx++] = 0.0f; // position_y
        buf[idx++] = 0.0f; // target_id
        buf[idx++] = 0.0f; // weapon_cooldown
        buf[idx++] = static_cast<float>(drone->bDead);
        buf[idx++] = 0.0f; // is_ion_disrupted
        buf[idx++] = 0.0f; // ion_stun_timer
    }

    // --- augments (3 slots × 3 + 11 extra = 20 fields) ---
    idx += 20; // TODO: iterate player augment map

    // --- environmental (17 fields) ---
    idx += 17; // TODO: needs SpaceManager access

    // --- combat_meta (27 fields) ---
    buf[idx++] = 0.0f; // combat_time_elapsed — TODO
    buf[idx++] = 0.0f; // enemy_fleeing — TODO: ShipAI access
    buf[idx++] = 0.0f; // enemy_escape_timer
    buf[idx++] = 0.0f; // enemy_ftl_charge_progress
    buf[idx++] = 0.0f; // enemy_surrender_threshold
    buf[idx++] = static_cast<float>(enemy ? enemy->bAutomated : 0);
    buf[idx++] = static_cast<float>(enemy ? enemy->bInvincible : 0);
    idx += 8; // surrender_offer fields — TODO: event system
    buf[idx++] = static_cast<float>(player->jump_timer.first);  // ftl_charge_current
    buf[idx++] = static_cast<float>(player->jump_timer.second); // ftl_charge_max
    buf[idx++] = 0.0f; // sector_number — TODO: StarMap
    buf[idx++] = 0.0f; // sector_type
    buf[idx++] = 0.0f; // difficulty — TODO
    buf[idx++] = 0.0f; // boss_fight
    buf[idx++] = 0.0f; // boss_phase
    buf[idx++] = 0.0f; // boss_next_phase
    buf[idx++] = 0.0f; // boss_power_surge_timer
    buf[idx++] = 0.0f; // boss_power_surge_goal
    buf[idx++] = 0.0f; // boss_power_surge_count
    buf[idx++] = 0.0f; // boss_death_began

    // --- projectiles (16 slots × 13 fields = 208) ---
    idx += 208; // TODO: needs SpaceManager projectile iteration

    // --- sensor_masking (23 fields) ---
    idx += 23; // TODO

    // --- strategic (1279 fields) ---
    idx += 1279; // TODO: WorldManager/StarMap

    // --- clone_bay (3 fields) ---
    if (player->cloneSystem) {
        buf[idx++] = 0.0f; // clone_in_progress — TODO
        buf[idx++] = 0.0f; // clone_progress — TODO
        buf[idx++] = 0.0f; // clone_death_timer — TODO
    } else {
        idx += 3;
    }

    // --- enemy_ship (152 fields) ---
    idx += 152; // TODO: mirror player serialization for enemy

    // --- beam_path_lookup (80 paths × 5 rooms = 400 fields) ---
    for (int p = 0; p < static_cast<int>(BEAM_PATH_COUNT); p++) {
        for (int r = 0; r < static_cast<int>(BEAM_PATH_ROOMS); r++) {
            buf[idx++] = static_cast<float>(beam_paths_[p][r]);
        }
    }

    // Verify field count matches spec
    if (idx != OBS_FIELD_COUNT) {
        fprintf(stderr, "[Bridge] WARNING: idx=%zu, expected=%zu\n", idx, OBS_FIELD_COUNT);
    }
}

} // namespace ftl_rl
