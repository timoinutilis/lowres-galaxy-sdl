//
//  PlayerShot.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 14.02.24.
//

#ifndef Shot_h
#define Shot_h

#include "entt.hpp"

struct PlayerShot final
{
    entt::entity player;
    int damage = 1;
};

#endif /* Shot_h */
