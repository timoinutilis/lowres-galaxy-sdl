//
//  SpawnSystem.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 06.03.24.
//

#include "SpawnSystem.hpp"
#include "entt.hpp"
#include "../Scenes/Scene.hpp"
#include "../Components/SpawnArea.hpp"
#include "../Components/Position.hpp"

SpawnSystem::SpawnSystem(Scene& scene) noexcept
    : scene(scene)
{
}

void SpawnSystem::update() const
{
    const auto view = scene.getRegistry().view<SpawnArea, Position>();
    for (auto entity : view)
    {
        auto& spawnArea = view.get<SpawnArea>(entity);
        
        if (spawnArea.ticks <= 0)
        {
            auto& position = view.get<Position>(entity);
            
            double x = position.x + spawnArea.x + spawnArea.width * scene.getRandom().getDouble();
            double y = position.y + spawnArea.y + spawnArea.height * scene.getRandom().getDouble();
            spawnArea.spawnFunction(x, y);
            
            if (--spawnArea.count > 0)
            {
                spawnArea.ticks = spawnArea.delay;
            }
            else
            {
                scene.getRegistry().destroy(entity);
            }
        }
        
        --spawnArea.ticks;
    }
}
