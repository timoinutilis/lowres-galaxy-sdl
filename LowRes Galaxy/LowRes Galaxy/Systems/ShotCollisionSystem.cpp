//
//  ShotCollisionSystem.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 14.02.24.
//

#include "ShotCollisionSystem.hpp"
#include "entt.hpp"
#include "../Scene.hpp"
#include "../Components/Position.hpp"
#include "../Components/Shootable.hpp"
#include "../Components/Shot.hpp"
#include "../Factories/SpriteFactory.hpp"

void ShotCollisionSystem::update(Scene* scene)
{
    auto& registry = scene->getRegistry();
    const auto shotsView = registry.view<Position, Shot>();
    const auto shootablesView = registry.view<Position, Shootable>();
    
    for (auto shotEntity : shotsView)
    {
        auto& shotPosition = shotsView.get<Position>(shotEntity);

        for (auto shootableEntity : shootablesView)
        {
            auto& shootablePosition = shootablesView.get<Position>(shootableEntity);
            
            if (shotPosition.isNear(shootablePosition, 8.0))
            {
                auto& shot = shotsView.get<Shot>(shotEntity);
                auto& shootable = shootablesView.get<Shootable>(shootableEntity);
                
                shootable.hits -= shot.damage;
                if (shootable.hits <= 0)
                {
                    SpriteFactory::createExplosion(scene, shootablePosition.x, shootablePosition.y);
                    registry.destroy(shootableEntity);
                }
                
                registry.destroy(shotEntity);
                break;
            }
        }
    }
    
}
