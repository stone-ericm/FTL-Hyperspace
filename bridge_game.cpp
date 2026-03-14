// bridge/bridge_game.cpp
// Game management: speed control, reset, episode detection.

#include "bridge.h"
#include <cstdio>

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
    // FIXME_ACCESSOR: Programmatically start a new game.
    //
    // This must replicate what happens when the player clicks:
    //   Main Menu → New Game → Select Ship → Start
    //
    // Likely approach:
    //   1. G_->GetApp()->NewGame(config_.ship_blueprint);
    //   or
    //   1. ScoreKeeper::Reset()
    //   2. WorldManager::StartNewGame(shipBlueprint)
    //   3. Wait for first beacon to load
    //
    // UNCERTAINTY: FTL was not designed for thousands of resets.
    // Memory leaks or stale state are possible. If detected,
    // the fallback is process restart every N episodes (handled
    // by Python in Plan 3).

    fprintf(stderr, "[Bridge] Resetting game with ship: %s\n", config_.ship_blueprint.c_str());
}

bool Bridge::checkEpisodeDone(EpisodeResult& result) {
    // FIXME_ACCESSOR: Check game-over conditions.

    // Player destroyed
    // if (player->bDestroyed) {
    //     result = EpisodeResult::LOSS;
    //     return true;
    // }

    // Enemy destroyed (flagship boss in sector 8)
    // if (enemy && enemy->bDestroyed) {
    //     // Check if this is the final boss
    //     // if (worldManager->sector == 8 && FIXME_is_flagship) {
    //     //     result = EpisodeResult::WIN;
    //     //     return true;
    //     // }
    // }

    // Fled (set by onJumpLeave callback)
    if (fled_this_step_) {
        result = EpisodeResult::FLED;
        return true;
    }

    return false;
}

} // namespace ftl_rl
