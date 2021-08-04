
#pragma once

#include "raylib-cpp.hpp"

class Entity {
public:
    raylib::Vector2 m_position;

    Entity(raylib::Vector2 position): m_position(position){}

    virtual void draw() const = 0;
};

