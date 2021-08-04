//
// Created by pollini on 04/08/2021.
//

#include "constants.h"

#include "item.h"

void Item::draw() const {
    DrawRectangle(m_position.x*TILE_SIZE,m_position.y*TILE_SIZE,TILE_SIZE,TILE_SIZE,m_color);
}
