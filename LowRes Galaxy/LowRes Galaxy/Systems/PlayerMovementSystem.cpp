//
//  PlayerMovementSystem.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#include "PlayerMovementSystem.hpp"
#include "entt.hpp"
#include "../Factories/SpriteFactory.hpp"
#include "../Scene.hpp"
#include "../Components/Position.hpp"
#include "../Components/PlayerMovement.hpp"

void PlayerMovementSystem::update(Scene* scene)
{
    const auto view = scene->getRegistry().view<Position, PlayerMovement>();
    for (auto entity : view) {
        auto& position = view.get<Position>(entity);
        auto& movement = view.get<PlayerMovement>(entity);
        
        position.x += movement.directionX;
        position.y += movement.directionY;
        
        if (position.x < 8)
        {
            position.x = 8;
        }
        if (position.x > 128)
        {
            position.x = 128;
        }
        if (position.y < 0)
        {
            position.y = 0;
        }
        if (position.y > 112)
        {
            position.y = 112;
        }
        
        if (movement.isShooting)
        {
            SpriteFactory::createShot(scene, position.x + 8.0, position.y + 11.0);
        }
    }
}
