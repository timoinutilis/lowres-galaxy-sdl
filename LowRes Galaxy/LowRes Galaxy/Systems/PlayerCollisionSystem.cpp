//
//  PlayerCollisionSystem.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 14.02.24.
//

#include "PlayerCollisionSystem.hpp"
#include "entt.hpp"
#include "../Scenes/Scene.hpp"
#include "../Components/PlayerStatus.hpp"
#include "../Components/Position.hpp"
#include "../Components/CollisionBox.hpp"
#include "../Components/EnemyShot.hpp"
#include "../Factories/SpriteFactory.hpp"

void PlayerCollisionSystem::update(Scene& scene)
{
    auto& registry = scene.getRegistry();
    const auto playersView = registry.view<PlayerStatus, CollisionBox, Position>();
    const auto collidersView = registry.view<CollisionBox, Position>();
    
    for (auto playerEntity : playersView)
    {
        auto& playerStatus = playersView.get<PlayerStatus>(playerEntity);
        
        if (playerStatus.shield > 0 || playerStatus.lives == 0)
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
                explode(scene, playerStatus, playerPosition);
                
                if (registry.any_of<EnemyShot>(colliderEntity))
                {
                    registry.destroy(colliderEntity);
                }
                
                break;
            }
        }
    }
    
}

void PlayerCollisionSystem::explode(Scene& scene, PlayerStatus& status, Position& position)
{
    --status.lives;
    
    SpriteFactory::createExplosion(scene, position.x, position.y);
    SpriteFactory::createExplosion(scene, position.x - 8.0 + scene.getRandom().getDouble() * 16.0, position.y - 8.0 + scene.getRandom().getDouble() * 16.0);
    SpriteFactory::createExplosion(scene, position.x - 8.0 + scene.getRandom().getDouble() * 16.0, position.y - 8.0 + scene.getRandom().getDouble() * 16.0);
    
    if (status.lives > 0)
    {
        status.hide = 120;
        status.shield = 120;
    }
}
