//
// Created by pollini on 05/08/2021.
//

#ifndef CPP_RL_DEMO_GEO_UTILS_H
#define CPP_RL_DEMO_GEO_UTILS_H

#include <vector>

#include "raylib-cpp.hpp"

struct geo_utils {
    static std::vector<raylib::Vector2> get_point_line_path(const raylib::Vector2& from, const raylib::Vector2& to);
    static std::vector<raylib::Vector2> get_point_segments_path(const raylib::Vector2& from, const raylib::Vector2& to,int max_turns = 2);
};


#endif //CPP_RL_DEMO_GEO_UTILS_H
