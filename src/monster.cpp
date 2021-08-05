//
// Created by pollini on 05/08/2021.
//

#include "raylib-cpp.hpp"
#include "fmt/core.h"


#include "../constants.h"
#include "monster.h"
#include "../game.hpp"

void Monster::draw() const {
    Color color = DARKBLUE;
    switch (state) {
        case MonsterState::SLEEPING:
            color= DARKBLUE;
            break;

        case MonsterState::PATROL:
            color= BEIGE;
            break;
        case MonsterState::ALARM:
            break;
    }
    DrawRectangle((m_position.x)* TILE_SIZE,(m_position.y)*TILE_SIZE,TILE_SIZE,TILE_SIZE,color);
}

void Monster::update() {
//    fmt::print("Monster::update()");
    Game::getInstance().set_state(GameState::HERO_MOVING);
    if (Game::getInstance().distancesq_from_player(m_position)< 10) {
        state = MonsterState::PATROL;
    }

    if (state == MonsterState::SLEEPING) {

    }

    if (state == MonsterState::PATROL) {
        auto dx  = Vector2Subtract(Game::getInstance().hero.m_position,m_position);


        raylib::Vector2 movement{};
        if (dx.x > 0)
            movement.x = 1;
        else if (dx.x < 0)
            movement.x = -1;

        if (dx.y > 0)
            movement.y = 1;
        else if (dx.y < 0)
            movement.y = -1;

        if (Vector2LengthSqr(movement)) {
            if (GetRandomValue(0,10) > 5) {
                auto desired_pos_x = Vector2Add(m_position,{movement.x,0});
                if (Map::getInstance().is_walkable(desired_pos_x.x, desired_pos_x.y)) {
                    m_position = Vector2Add(m_position,{movement.x,0});
                }

                auto desired_pos_y = Vector2Add(m_position,{0,movement.y});
                if (Map::getInstance().is_walkable(desired_pos_y.x, desired_pos_y.y)) {
                    m_position = Vector2Add(m_position,{0,movement.y});
                }
            }
        }
    }
}
