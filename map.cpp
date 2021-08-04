//
// Created by pollini on 04/08/2021.
//

#include "raylib-cpp.hpp"
#include "map.h"

void Map::draw() const {
    for (int y = 0; y < ROWS; ++y) {
        for (int x = 0; x < COLS; ++x) {
            if (m_grid[y][x] >0) {
                DrawCircle((x+0.5)* TILE_SIZE,(y+0.5)*TILE_SIZE,TILE_SIZE/2,GREEN);
            }
        }
    }
}

void Map::set_cell(int x, int y, int value){
    m_grid[y][x] = value;
}

bool Map::is_walkable(int x, int y ) const  {
    return m_grid[y][x]  == 0;
}
