//
//  LivesChangedEvent.h
//  LowRes Galaxy
//
//  Created by Timo Kloss on 28.02.24.
//

#ifndef LivesChangedEvent_h
#define LivesChangedEvent_h

#include "entt.hpp"

struct LivesChangedEvent final
{
    entt::entity entity;
    int lives;
};

#endif /* LivesChangedEvent_h */
