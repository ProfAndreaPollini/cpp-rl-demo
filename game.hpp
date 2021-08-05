
#pragma  once

#include <algorithm>

#include "hero.hpp"
#include "map.h"
#include "item.h"
#include "src/monster.h"

#include "raylib-cpp.hpp"

enum class GameState {
    HERO_MOVING,
    MONSTERS_MOVING
};

class Game {
    std::vector<Item*> m_items{};
    std::vector<Monster*> m_monsters{};
    GameState m_game_state{GameState::HERO_MOVING};

    Game() =default;

public:
    static Game& getInstance()
    {
        static Game    instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }
    Game(Game const&)               = delete;
    void operator=(Game const&)  = delete;

    void set_state(GameState state) {m_game_state=state; }

    void setup();

    void update(){
        if (m_game_state == GameState::HERO_MOVING) {
            hero.update();
        } else if (m_game_state == GameState::MONSTERS_MOVING) {
            std::for_each(m_monsters.begin(),  m_monsters.end(),[](Monster* monster){monster->update();});
        }

        std::remove_if(m_items.begin(),m_items.end(), [&](const Item* item){return item->m_position == hero.m_position;});

    }

    float distancesq_from_player(const raylib::Vector2& pos) {
        return Vector2LengthSqr(Vector2Subtract(hero.m_position,pos));
    }

    void draw() {
        Map::getInstance().draw();

        for (const auto& item: m_items) {
            item->draw();
        }

        for (const auto& monster: m_monsters) {
            monster->draw();
        }

        hero.draw();

    }

    Hero hero{{10,10}};
};