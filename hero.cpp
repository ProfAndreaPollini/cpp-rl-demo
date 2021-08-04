

#include "raylib-cpp.hpp"

#include "hero.hpp"
#include "map.h"

void Hero::update() {
    raylib::Vector2 dx{};
    if (IsKeyPressed(KEY_W)) {
        dx.y -=1;
    }
    if (IsKeyPressed(KEY_S)) {
        dx.y +=1;
    }
    if (IsKeyPressed(KEY_A)) {
        dx.x -=1;
    }
    if (IsKeyPressed(KEY_D)) {
        dx.x +=1;
    }

    if(Vector2LengthSqr(dx) != 0) {
        auto desired_position = Vector2Add(m_position,dx);
        if (Map::getInstance().is_walkable(desired_position.x,desired_position.y)) {
            m_position = desired_position;
        }
    }
}
