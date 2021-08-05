//
// Created by pollini on 04/08/2021.
//

#ifndef CPP_RL_DEMO_MAP_H
#define CPP_RL_DEMO_MAP_H

#include "constants.h"
#include "room.h"

#include <array>
#include <vector>

class Map {
    std::array<std::array<int, COLS>,ROWS> m_grid{};
    std::vector<Room> m_rooms{};

    Map() {
        m_rooms.push_back({{10,10},10,20});
        m_rooms[0].add_door({15,10});
        generate();
    }

    void generate() {
        for (const auto& room: m_rooms) {
            auto end_pos = room.m_end();
            for (int x = room.m_origin.x; x <= end_pos.x; ++x) {
                set_cell(x,room.m_origin.y,1);
                set_cell(x,end_pos.y,1);
            }
            for (int y = room.m_origin.y+1; y <= end_pos.y-1; ++y) {
                set_cell(room.m_origin.x,y,1);
                set_cell(end_pos.x,y,1);
            }

            for (const auto&door:room.m_doors) {
                set_cell(door.m_position.x,door.m_position.y,2);
            }
        }
    }

public:
    static Map& getInstance()
    {
        static Map    instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }
    Map(Map const&)               = delete;
    void operator=(Map const&)  = delete;

    void set_cell(int x, int y, int value);

    void draw() const;

    bool is_walkable(int x, int y ) const;

};


#endif //CPP_RL_DEMO_MAP_H
