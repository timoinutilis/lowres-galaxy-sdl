//
//  MoveSystem.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 10.02.24.
//

#include "MoveSystem.hpp"
#include "entt.hpp"
#include "../Scenes/Scene.hpp"
#include "../Components/Position.hpp"
#include "../Components/MoveDirection.hpp"
#include "Config.hpp"

MoveSystem::MoveSystem(Scene& scene) noexcept
    : scene(scene)
{
}

void MoveSystem::update() const
{
    const auto view = scene.getRegistry().view<Position, MoveDirection>();
    for (auto entity : view)
    {
        auto& position = view.get<Position>(entity);
        auto& moveDirection = view.get<MoveDirection>(entity);
        
        position.x += moveDirection.x;
        position.y += moveDirection.y;
        
        if (position.x < -8.0 || position.x >= Config::screenWidth || position.y < -8.0 || position.y >= Config::screenHeight)
        {
            scene.getRegistry().destroy(entity);
        }
    }
}
