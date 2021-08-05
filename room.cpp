//
// Created by pollini on 04/08/2021.
//

#include "room.h"


Corridor::Corridor(const raylib::Vector2 &mStart, const raylib::Vector2 &mEnd) {
    m_turnings.push_back(mStart);
    m_turnings.push_back(mEnd);
}


void Room::add_door(raylib::Vector2 door_position) {
    if(!is_on_wall(door_position)) return;
    m_doors.push_back({door_position});
}