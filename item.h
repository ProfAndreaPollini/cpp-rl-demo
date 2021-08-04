//
// Created by pollini on 04/08/2021.
//

#ifndef CPP_RL_DEMO_ITEM_H
#define CPP_RL_DEMO_ITEM_H


#include "entity.hpp"



class Item : public Entity {
    raylib::Color m_color;
public:
    Item(raylib::Vector2 position): Entity(position){}
    void draw() const override;
};


#endif //CPP_RL_DEMO_ITEM_H
