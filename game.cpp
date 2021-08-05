
#include "game.hpp"



void Game::setup() {
//    for (int i = 0; i < 50; ++i) {
//        Map::getInstance().set_cell(GetRandomValue(1,COLS-1), GetRandomValue(1,ROWS-1),1);
//    }
//
    for (int i = 0; i < 10; ++i) {

        m_items.push_back(new Item({static_cast<float>(GetRandomValue(1,COLS-1)), static_cast<float>(GetRandomValue(1,ROWS-1))}));
    }

    int monsters_to_be_created = 3;



    for (int i = 0; i < monsters_to_be_created; ++i) {
        auto room = Map::getInstance().room(GetRandomValue(0,Map::getInstance().count_rooms()-1));
        m_monsters.push_back(new Monster{room.center()});
    }
    hero.m_position = Map::getInstance().room(0).center();

}
