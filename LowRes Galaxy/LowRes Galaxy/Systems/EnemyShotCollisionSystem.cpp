//
//  EnemyShotCollisionSystem.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 14.02.24.
//

#include "EnemyShotCollisionSystem.hpp"
#include "entt.hpp"
#include "../Scenes/Scene.hpp"
#include "../Components/PlayerStatus.hpp"
#include "../Components/Position.hpp"
#include "../Components/CollisionBox.hpp"
#include "../Components/EnemyShot.hpp"
#include "../Events/HitEvent.hpp"
#include "../Factories/SpriteFactory.hpp"

EnemyShotCollisionSystem::EnemyShotCollisionSystem(Scene& scene)
    : scene(scene)
{
}

void EnemyShotCollisionSystem::update() const
{
    auto& registry = scene.getRegistry();
    const auto shotsView = registry.view<EnemyShot, Position, CollisionBox>();
    const auto playersView = registry.view<PlayerStatus, Position, CollisionBox>();
    
    for (auto shotEntity : shotsView)
    {
        auto& shotPosition = shotsView.get<Position>(shotEntity);
        auto& shotBox = shotsView.get<CollisionBox>(shotEntity);

        for (auto playerEntity : playersView)
        {
            auto& playerStatus = playersView.get<PlayerStatus>(playerEntity);
            
            if (playerStatus.hide == 0 && playerStatus.lives > 0) //TODO: uncouple from playerStatus, maybe disable CollisionBox
            {
                auto& playerPosition = playersView.get<Position>(playerEntity);
                auto& playerBox = playersView.get<CollisionBox>(playerEntity);
                
                if (CollisionBox::checkCollision(shotPosition, shotBox, playerPosition, playerBox))
                {
                    scene.getDispatcher().trigger(HitEvent{playerEntity});
                    registry.destroy(shotEntity);
                    break;
                }
            }
        }
    }
}
