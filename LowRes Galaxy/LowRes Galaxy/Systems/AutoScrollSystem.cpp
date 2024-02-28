//
//  AutoScrollSystem.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#include "AutoScrollSystem.hpp"
#include "entt.hpp"
#include "../Scenes/Scene.hpp"
#include "../Components/Position.hpp"
#include "../Components/AutoScroll.hpp"

AutoScrollSystem::AutoScrollSystem(Scene& scene)
    : scene(scene)
{
}

void AutoScrollSystem::update() const
{
    const auto view = scene.getRegistry().view<Position, AutoScroll>();
    for (auto entity : view)
    {
        auto& position = view.get<Position>(entity);
        auto& autoScroll = view.get<AutoScroll>(entity);
        
        position.x -= autoScroll.speed;
        
        if (position.x < autoScroll.minX)
        {
            position.x += (autoScroll.maxX - autoScroll.minX);
        }
    }
}
