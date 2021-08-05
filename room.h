//
// Created by pollini on 04/08/2021.
//

#ifndef CPP_RL_DEMO_ROOM_H
#define CPP_RL_DEMO_ROOM_H

#include <vector>

#include "raylib-cpp.hpp"

class Door;

class Room {
public:
    raylib::Vector2 m_origin;
    int m_width;
    int m_height;
    std::vector<Door> m_doors{};


    Room(raylib::Vector2 origin,int width, int height) : m_origin(origin),m_width(width), m_height(height){}

//    // Returns true if this overlaps with other
//    pub fn intersect(&self, other:&Rect) -> bool {
//        self.x1 <= other.x2 && self.x2 >= other.x1 && self.y1 <= other.y2 && self.y2 >= other.y1
//    }

    raylib::Vector2 m_end() const { return Vector2Add(m_origin,{static_cast<float>(m_width),static_cast<float>(m_height)});}

    bool intersect(Room& other) { return m_origin.x <= other.m_origin.x + other.m_width && m_origin.x+m_width >= other.m_origin.x &&
    m_origin.y <= other.m_origin.y + other.m_height && m_origin.y + m_height >= other.m_origin.y;}

    raylib::Vector2 center() const { return {(m_origin.x + 0.5f*m_width), m_origin.y + 0.5f * m_height};}

    bool is_on_wall(raylib::Vector2& point) const {
        return ((point.x == m_origin.x || point.x == m_end().x)  && ( point.y - m_origin.y < m_height && point.y - m_origin.y>=0) ||
        (point.y == m_origin.y || point.y == m_end().y) &&(point.x - m_origin.x < m_width && point.x - m_origin.x>=0)
        );
    }

    void add_door(raylib::Vector2 door_position);

};

struct Door {


    bool is_open = false;
    raylib::Vector2 m_position;

    Door( raylib::Vector2& position) : m_position(position){}

};


struct Corridor {
    std::vector<raylib::Vector2> m_turnings{};

    Corridor(const raylib::Vector2 &mStart, const raylib::Vector2 &mEnd);
    void add_horizonal_segment(const raylib::Vector2 &turning) {

    }
};

#endif //CPP_RL_DEMO_ROOM_H
