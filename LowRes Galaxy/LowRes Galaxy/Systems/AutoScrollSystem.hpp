//
//  AutoScrollSystem.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#ifndef AutoScrollSystem_hpp
#define AutoScrollSystem_hpp

#include "entt.hpp"

class AutoScrollSystem
{
private:
    entt::registry& registry;
    
public:
    AutoScrollSystem(entt::registry& registry);
    void update();
};

#endif /* AutoScrollSystem_hpp */
