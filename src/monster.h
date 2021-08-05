//
// Created by pollini on 05/08/2021.
//

#ifndef CPP_RL_DEMO_MONSTER_H
#define CPP_RL_DEMO_MONSTER_H


#include "../entity.hpp"

enum struct MonsterState {
    SLEEPING,
    PATROL,
    ALARM
};

struct Monster : public Entity {
    MonsterState state{MonsterState::SLEEPING};

    Monster(const raylib::Vector2& position): Entity(position){}

    void update();

    void draw() const override;
};


#endif //CPP_RL_DEMO_MONSTER_H
