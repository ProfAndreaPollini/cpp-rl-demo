//
// Created by pollini on 04/08/2021.
//

#ifndef CPP_RL_DEMO_MAP_H
#define CPP_RL_DEMO_MAP_H

#include "constants.h"

#include <array>

class Map {
    std::array<std::array<int, COLS>,ROWS> m_grid{};

    Map() {}
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
