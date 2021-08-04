
#include "game.hpp"

void Game::setup() {
    for (int i = 0; i < 50; ++i) {
        Map::getInstance().set_cell(GetRandomValue(1,COLS-1), GetRandomValue(1,ROWS-1),1);
    }

    for (int i = 0; i < 10; ++i) {

        m_items.push_back(new Item({static_cast<float>(GetRandomValue(1,COLS-1)), static_cast<float>(GetRandomValue(1,ROWS-1))}));
    }

}
