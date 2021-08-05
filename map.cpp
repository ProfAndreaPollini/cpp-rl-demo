//
// Created by pollini on 04/08/2021.
//

#include "raylib-cpp.hpp"
#include "map.h"

#include <algorithm>
#include <fmt/core.h>

void Map::draw() const {
    for (int y = 0; y < ROWS; ++y) {
        for (int x = 0; x < COLS; ++x) {
            int tile_id = m_grid[y][x];
            if (tile_id ==1) {
                DrawRectangle((x)* TILE_SIZE,(y)*TILE_SIZE,TILE_SIZE,TILE_SIZE,DARKGRAY);
            } else if (tile_id==2) {
//                DrawCircle((x+0.5)* TILE_SIZE,(y+0.5)*TILE_SIZE,TILE_SIZE/2,ORANGE);
DrawRectangle((x)* TILE_SIZE,(y)*TILE_SIZE,TILE_SIZE,TILE_SIZE,ORANGE);
            } else if (tile_id==3) {
                DrawRectangle((x)* TILE_SIZE,(y)*TILE_SIZE,TILE_SIZE,TILE_SIZE,BROWN);
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


void Map::generate_rooms(int n_rooms) {
    auto MIN_ROOM_W = 6;
    auto MAX_ROOM_W  = 12;
    auto attempts_left = 100;

    while (attempts_left>0 && m_rooms.size() <= n_rooms) {
        auto w = GetRandomValue(MIN_ROOM_W,MAX_ROOM_W);
        auto h = GetRandomValue(MIN_ROOM_W,MAX_ROOM_W);
        auto x = GetRandomValue(0,COLS-w-1);
        auto y = GetRandomValue(0,ROWS-h-1);

        Room candidate_room{{static_cast<float>(x),static_cast<float>(y)},w,h};

        if (std::none_of(m_rooms.begin(),  m_rooms.end(),
                         [&candidate_room](const auto& room) -> bool{ return candidate_room.intersect(room);})) {

            m_rooms.push_back(candidate_room);
            for (int y = candidate_room.m_origin.y; y < candidate_room.m_end().y; ++y) {
                for (int x = candidate_room.m_origin.x; x < candidate_room.m_end().x; ++x) {
                    set_cell(x,y,0);
                }
            }
        }
        attempts_left--;
    }
}

void Map::connect_rooms() {
    if(m_rooms.size()==0) return;



    for (int i = 0; i < m_rooms.size()-1; ++i) {
        auto& connect_from = m_rooms[i];
        auto& connect_to = m_rooms[i+1];

        fmt::print("connecting ({},{}) to ({},{})",connect_from.center().x,connect_from.center().y,connect_to.center().x,connect_to.center().y);
        auto points = geo_utils::get_point_segments_path(connect_from.center(), connect_to.center());

        for (const auto& point :points) {


//            if (connect_from.is_on_wall(point)) {
//                connect_from.add_door({point});
//            }
//            if (i ==m_rooms.size()-2) {
//                if (connect_to.is_on_wall(point)) {
//                    connect_to.add_door({point});
//                }
//            }
            set_cell(point.x,point.y,0);
        }


    }
}