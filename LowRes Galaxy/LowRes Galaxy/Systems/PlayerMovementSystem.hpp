//
//  PlayerMovementSystem.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#ifndef PlayerMoveSystem_hpp
#define PlayerMoveSystem_hpp

#include "entt.hpp"

class PlayerMovementSystem
{
private:
    entt::registry& registry;
    
public:
    PlayerMovementSystem(entt::registry& registry);
    void update();
};

#endif /* PlayerMoveSystem_hpp */
