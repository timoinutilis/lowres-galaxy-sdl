//
//  AddScoreEvent.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 28.02.24.
//

#ifndef AddScoreEvent_h
#define AddScoreEvent_h

#include "entt.hpp"

struct AddScoreEvent final
{
    entt::entity entity;
    int points;
};

#endif /* AddScoreEvent_h */
