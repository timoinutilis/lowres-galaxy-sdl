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
#include "../Components/CollisionBox.hpp"
#include "../Factories/SpriteFactory.hpp"

void ShotCollisionSystem::update(Scene* scene)
{
    auto& registry = scene->getRegistry();
    const auto shotsView = registry.view<Shot, Position, CollisionBox>();
    const auto shootablesView = registry.view<Shootable, Position, CollisionBox>();
    
    for (auto shotEntity : shotsView)
    {
        auto& shotPosition = shotsView.get<Position>(shotEntity);
        auto& shotBox = shotsView.get<CollisionBox>(shotEntity);

        for (auto shootableEntity : shootablesView)
        {
            auto& shootablePosition = shootablesView.get<Position>(shootableEntity);
            auto& shootableBox = shootablesView.get<CollisionBox>(shootableEntity);
            
            if (CollisionBox::checkCollision(shotPosition, shotBox, shootablePosition, shootableBox))
            {
                auto& shot = shotsView.get<Shot>(shotEntity);
                auto& shootable = shootablesView.get<Shootable>(shootableEntity);
                
                shootable.hits -= shot.damage;
                if (shootable.hits <= 0)
                {
                    SpriteFactory::createExplosion(scene, shootablePosition.x + (shootableBox.minX + shootableBox.maxX) * 0.5 - 8.0, shootablePosition.y + (shootableBox.minY + shootableBox.maxY) * 0.5 - 8.0);
                    registry.destroy(shootableEntity);
                }
                
                registry.destroy(shotEntity);
                break;
            }
        }
    }
    
}
