

#pragma once

#include "raylib-cpp.hpp"

#include "constants.h"
#include "entity.hpp"

class Hero: public Entity {

    raylib::Color m_color;
    std::vector<Entity*> m_inventory{};

    public:
    Hero(raylib::Vector2 position) : Entity(position), m_color(RED) {
    }

    void update();

    void draw() const  {
        DrawRectangle(m_position.x*TILE_SIZE,m_position.y*TILE_SIZE,TILE_SIZE,TILE_SIZE,m_color);
    }


};