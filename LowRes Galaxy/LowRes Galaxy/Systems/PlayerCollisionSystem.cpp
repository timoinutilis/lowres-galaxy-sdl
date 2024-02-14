//
//  PlayerCollisionSystem.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 14.02.24.
//

#include "PlayerCollisionSystem.hpp"
#include "entt.hpp"
#include "../Scene.hpp"
#include "../Components/PlayerStatus.hpp"
#include "../Components/Position.hpp"
#include "../Components/CollisionBox.hpp"
#include "../Components/EnemyShot.hpp"
#include "../Factories/SpriteFactory.hpp"

void PlayerCollisionSystem::update(Scene* scene)
{
    auto& registry = scene->getRegistry();
    const auto playersView = registry.view<PlayerStatus, CollisionBox, Position>();
    const auto collidersView = registry.view<CollisionBox, Position>();
    
    for (auto playerEntity : playersView)
    {
        auto& playerStatus = playersView.get<PlayerStatus>(playerEntity);
        
        if (playerStatus.shield > 0)
        {
            continue;
        }
        
        auto& playerPosition = playersView.get<Position>(playerEntity);
        auto& playerBox = playersView.get<CollisionBox>(playerEntity);

        for (auto colliderEntity : collidersView)
        {
            auto& colliderPosition = collidersView.get<Position>(colliderEntity);
            auto& colliderBox = collidersView.get<CollisionBox>(colliderEntity);
            
            if (CollisionBox::checkCollision(playerPosition, playerBox, colliderPosition, colliderBox))
            {
                SpriteFactory::createExplosion(scene, playerPosition.x, playerPosition.y);
                SpriteFactory::createExplosion(scene, playerPosition.x - 8.0 + scene->getRandom().getDouble() * 16.0, playerPosition.y - 8.0 + scene->getRandom().getDouble() * 16.0);
                SpriteFactory::createExplosion(scene, playerPosition.x - 8.0 + scene->getRandom().getDouble() * 16.0, playerPosition.y - 8.0 + scene->getRandom().getDouble() * 16.0);
                
                registry.destroy(playerEntity);
                
                if (registry.any_of<EnemyShot>(colliderEntity))
                {
                    registry.destroy(colliderEntity);
                }
                
                break;
            }
        }
    }
    
}
