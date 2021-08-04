
#pragma  once

#include <algorithm>

#include "hero.hpp"
#include "map.h"
#include "item.h"

class Game {
    Hero hero{{10,10}};
    std::vector<Item*> m_items{};




public:
    Game() =default;

    void setup();

    void update(){
        hero.update();

        std::remove_if(m_items.begin(),m_items.end(), [&](const Item* item){return item->m_position == hero.m_position;});

    }

    void draw() {
        Map::getInstance().draw();

        for (const auto& item: m_items) {
            item->draw();
        }

        hero.draw();

    }
};