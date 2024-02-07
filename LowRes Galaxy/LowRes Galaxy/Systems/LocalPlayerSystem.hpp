//
//  LocalPlayerSystem.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#ifndef LocalPlayerSystem_hpp
#define LocalPlayerSystem_hpp

#include "entt.hpp"

class LocalPlayerSystem
{
private:
    entt::registry& registry;
    
public:
    LocalPlayerSystem(entt::registry& registry);
    void update();
};

#endif /* LocalPlayerSystem_hpp */
