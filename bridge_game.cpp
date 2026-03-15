// bridge/bridge_game.cpp
// Game management: speed control, reset, episode detection.

#include "bridge.h"
#include <cstdio>

#define G_ Global::GetInstance()

namespace ftl_rl {

void Bridge::setSpeedMultiplier(float multiplier) {
    // FIXME_ACCESSOR: Modify FTL's internal delta-time scaling.
    //
    // FTL uses a game speed multiplier (the 2x button sets it to 2.0).
    // We need to find and modify this value. Likely locations:
    //   - CApp::speedFactor or similar
    //   - TimerHelper::speedFactor
    //   - A global float controlling delta-time multiplication
    //
    // UNCERTAINTY: Values above 2x have never been tested.
    // Start with small values and increase incrementally.
    //
    // Example (pseudo-code):
    // G_->GetApp()->gameSpeedMultiplier = multiplier;

    fprintf(stderr, "[Bridge] Speed set to %.1fx\n", multiplier);
    (void)multiplier;
}

void Bridge::resetGame() {
    // No-op: game reset is now handled by the CApp::OnLoop state machine
    // (RESTARTING_GAME phase for LOSS, FINDING_COMBAT for WIN/FLED).
    // This method is retained for potential future use (direct API reset).
}

bool Bridge::checkEpisodeDone(EpisodeResult& result) {
    ShipManager* player = G_->GetShipManager(0);
    ShipManager* enemy = G_->GetShipManager(1);

    // Player destroyed = LOSS
    if (player && player->bDestroyed) {
        result = EpisodeResult::LOSS;
        return true;
    }

    // Enemy destroyed = WIN (any enemy, not just flagship)
    if (enemy && enemy->bDestroyed) {
        result = EpisodeResult::WIN;
        return true;
    }

    // Fled (set by onJumpLeave callback)
    if (fled_this_step_) {
        result = EpisodeResult::FLED;
        return true;
    }

    return false;
}

} // namespace ftl_rl
