//
// Created by pollini on 04/08/2021.
//

#ifndef CPP_RL_DEMO_MAP_H
#define CPP_RL_DEMO_MAP_H

#include "constants.h"
#include "room.h"
#include "src/geo_utils.h"

#include <array>
#include <vector>

class Map {
    std::array<std::array<int, COLS>,ROWS> m_grid{};
    std::vector<Room> m_rooms{};



    Map() {
//        m_rooms.push_back({{10,10},10,20});
//        m_rooms[0].add_door({15,10});
//
//        m_rooms.push_back({{30,30},5,5});

        for (int y = 0; y < ROWS; ++y) {
            for (int x = 0; x < COLS; ++x) {
                set_cell(x,y,1);
            }
        }
        generate();
    }

    void generate_rooms(int n_rooms);
    void connect_rooms();

    void generate() {
        generate_rooms(5);
        connect_rooms();


        for (const auto& room: m_rooms) {
//            auto end_pos = room.m_end();
//            for (int x = room.m_origin.x; x <= end_pos.x; ++x) {
//                set_cell(x,room.m_origin.y,3);
//                set_cell(x,end_pos.y,3);
//            }
//            for (int y = room.m_origin.y+1; y <= end_pos.y-1; ++y) {
//                set_cell(room.m_origin.x,y,3);
//                set_cell(end_pos.x,y,3);
//            }

            for (int y = room.m_origin.y; y < room.m_end().y; ++y) {
                for (int x = room.m_origin.x; x < room.m_end().x; ++x) {
                    set_cell(x,y,0);
                }
            }

//            set_cell(room.center().x,room.center().y,2);

//            for (const auto&door:room.m_doors) {
//                set_cell(door.m_position.x,door.m_position.y,2);
//            }
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
    int count_rooms() const { return m_rooms.size();}

    const Room& room(int i) const {return m_rooms.at(i);}

};


#endif //CPP_RL_DEMO_MAP_H
