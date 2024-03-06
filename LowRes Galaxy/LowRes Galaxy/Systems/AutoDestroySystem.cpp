//
//  AutoDestroySystem.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 06.03.24.
//

#include "AutoDestroySystem.hpp"
#include "entt.hpp"
#include "../Scenes/Scene.hpp"
#include "../Components/AutoDestroy.hpp"

AutoDestroySystem::AutoDestroySystem(Scene& scene)
    : scene(scene)
{
}

void AutoDestroySystem::update() const
{
    const auto view = scene.getRegistry().view<AutoDestroy>();
    for (auto entity : view)
    {
        auto& autoDestroy = view.get<AutoDestroy>(entity);
        
        if (autoDestroy.ticks > 0)
        {
            --autoDestroy.ticks;
        }
        else
        {
            scene.getRegistry().destroy(entity);
        }
    }
}
