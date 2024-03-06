//
//  PlayerCollisionSystem.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 06.03.24.
//

#include "PlayerCollisionSystem.hpp"
#include "entt.hpp"
#include "../Scenes/Scene.hpp"
#include "../Components/Position.hpp"
#include "../Components/CollisionBox.hpp"
#include "../Components/PlayerStatus.hpp"
#include "../Components/Shootable.hpp"
#include "../Events/HitEvent.hpp"

PlayerCollisionSystem::PlayerCollisionSystem(Scene& scene)
    : scene(scene)
{
}

void PlayerCollisionSystem::update() const
{
    auto& registry = scene.getRegistry();
    const auto playersView = registry.view<PlayerStatus, Position, CollisionBox>();
    const auto collidablesView = registry.view<Shootable, Position, CollisionBox>(); //TODO: replace Shootable with Collidable
    
    for (auto playerEntity : playersView)
    {
        auto& playerPosition = playersView.get<Position>(playerEntity);
        auto& playerBox = playersView.get<CollisionBox>(playerEntity);

        for (auto collidableEntity : collidablesView)
        {
            auto& collidablePosition = collidablesView.get<Position>(collidableEntity);
            auto& collidableBox = collidablesView.get<CollisionBox>(collidableEntity);
            
            if (CollisionBox::checkCollision(playerPosition, playerBox, collidablePosition, collidableBox))
            {
                scene.getDispatcher().trigger(HitEvent{playerEntity});
                break;
            }
        }
    }
}
