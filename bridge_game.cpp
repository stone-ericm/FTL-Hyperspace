// bridge/bridge_game.cpp
// Game management: speed control, reset, episode detection.

#include "bridge.h"
#include <cstdio>

#define G_ Global::GetInstance()

namespace ftl_rl {

void Bridge::setSpeedMultiplier(float multiplier) {
    CFPS* cfps = G_->GetCFPS();
    if (!cfps) {
        fprintf(stderr, "[Bridge] ERROR: CFPS not available, cannot set speed\n");
        return;
    }
    cfps->speedLevel = static_cast<int>(multiplier);
    fprintf(stderr, "[Bridge] Speed set to %dx (speedLevel=%d)\n",
            static_cast<int>(multiplier), cfps->speedLevel);
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
