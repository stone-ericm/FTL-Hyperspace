// bridge/bridge_paths.cpp
// Beam path precomputation from enemy ship geometry.
// See tests/test_bridge_algorithms.py::compute_beam_paths for reference.

#include "bridge.h"
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

namespace ftl_rl {

// Liang-Barsky line-rectangle intersection test.
// Same algorithm as Python prototype in tests/test_bridge_algorithms.py
static bool lineIntersectsRect(float x1, float y1, float x2, float y2,
                                float rx, float ry, float rw, float rh) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    float p[4] = {-dx, dx, -dy, dy};
    float q[4] = {x1 - rx, (rx + rw) - x1, y1 - ry, (ry + rh) - y1};
    float t_enter = 0.0f, t_exit = 1.0f;

    for (int i = 0; i < 4; i++) {
        if (std::abs(p[i]) < 1e-10f) {
            if (q[i] < 0) return false;
        } else {
            float t = q[i] / p[i];
            if (p[i] < 0) t_enter = std::max(t_enter, t);
            else           t_exit  = std::min(t_exit, t);
            if (t_enter > t_exit) return false;
        }
    }
    return t_enter <= t_exit;
}

void Bridge::computeBeamPaths(ShipManager* enemy) {
    // Clear existing paths
    for (auto& path : beam_paths_) path.fill(-1);

    if (!enemy) return;

    // FIXME_ACCESSOR: Get enemy ship room layout
    // const auto& rooms = enemy->ship.rooms; // vector of Room*
    // Get ship bounding box from ShipGraph
    // float ship_x = enemy->ship.shipGraph.shipBox.x;
    // float ship_y = enemy->ship.shipGraph.shipBox.y;
    // float ship_w = enemy->ship.shipGraph.shipBox.w;
    // float ship_h = enemy->ship.shipGraph.shipBox.h;

    // Placeholder values — replace with actual game data
    float ship_x = 0, ship_y = 0, ship_w = 200, ship_h = 100;
    float beam_length = 200.0f;

    struct RoomInfo { int id; float x, y, w, h; };
    std::vector<RoomInfo> rooms;
    // FIXME_ACCESSOR: populate rooms from enemy ship layout

    // Generate candidate beams (same logic as Python prototype)
    constexpr int NUM_ANGLES = 20;
    int num_positions = std::max(1, static_cast<int>(BEAM_PATH_COUNT) / NUM_ANGLES);

    // FIXME_ACCESSOR: Get room IDs containing key systems (shields, weapons, engines, piloting)
    std::set<int> system_room_ids;

    struct Candidate {
        int room_count;
        int system_count;  // rooms hitting key systems
        std::vector<int> room_ids;
        // Sort: more rooms first, then more system rooms
        bool operator<(const Candidate& o) const {
            if (room_count != o.room_count) return room_count > o.room_count;
            return system_count > o.system_count;
        }
    };
    std::vector<Candidate> candidates;

    for (int pos_i = 0; pos_i < num_positions; pos_i++) {
        float frac = (pos_i + 0.5f) / num_positions;
        float start_x = ship_x - 10.0f;
        float start_y = ship_y + ship_h * frac;

        for (int ang_i = 0; ang_i < NUM_ANGLES; ang_i++) {
            float angle = (-60.0f + 120.0f * (ang_i + 0.5f) / NUM_ANGLES) * 3.14159f / 180.0f;
            float end_x = start_x + beam_length * cosf(angle);
            float end_y = start_y + beam_length * sinf(angle);

            std::vector<int> hit;
            for (const auto& room : rooms) {
                if (lineIntersectsRect(start_x, start_y, end_x, end_y,
                                       room.x, room.y, room.w, room.h)) {
                    hit.push_back(room.id);
                }
            }
            if (!hit.empty()) {
                int sys_count = 0;
                for (int rid : hit) {
                    if (system_room_ids.count(rid)) sys_count++;
                }
                candidates.push_back({static_cast<int>(hit.size()), sys_count, hit});
            }
        }
    }

    // Sort by room count (descending) and deduplicate
    std::sort(candidates.begin(), candidates.end());
    std::set<std::vector<int>> seen;
    int path_idx = 0;

    for (const auto& c : candidates) {
        if (path_idx >= static_cast<int>(BEAM_PATH_COUNT)) break;
        auto sorted_rooms = c.room_ids;
        std::sort(sorted_rooms.begin(), sorted_rooms.end());
        if (seen.insert(sorted_rooms).second) {
            for (int r = 0; r < static_cast<int>(BEAM_PATH_ROOMS) && r < static_cast<int>(c.room_ids.size()); r++) {
                beam_paths_[path_idx][r] = c.room_ids[r];
            }
            path_idx++;
        }
    }
}

} // namespace ftl_rl
