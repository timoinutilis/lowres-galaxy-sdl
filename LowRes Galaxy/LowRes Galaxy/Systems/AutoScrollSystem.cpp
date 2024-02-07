//
//  AutoScrollSystem.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#include "AutoScrollSystem.hpp"
#include "../Components/Position.hpp"
#include "../Components/AutoScroll.hpp"

AutoScrollSystem::AutoScrollSystem(entt::registry& registry)
    : registry(registry)
{
}

void AutoScrollSystem::update()
{
    const auto view = registry.view<Position, AutoScroll>();
    for (auto entity : view) {
        auto& position = view.get<Position>(entity);
        auto& autoScroll = view.get<AutoScroll>(entity);
        
        position.x -= autoScroll.speed;
        
        if (position.x < -autoScroll.width)
        {
            position.x += 2 * autoScroll.width;
        }
    }
}
