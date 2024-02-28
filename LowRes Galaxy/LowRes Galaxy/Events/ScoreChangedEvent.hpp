//
//  ScoreChangedEvent.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 28.02.24.
//

#ifndef ScoreChangedEvent_h
#define ScoreChangedEvent_h

struct ScoreChangedEvent final
{
    entt::entity entity;
    int score;
};

#endif /* ScoreChangedEvent_h */
