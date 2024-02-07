//
//  PlayerMovementSystem.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#include "PlayerMovementSystem.hpp"
#include "../Components/Position.hpp"
#include "../Components/PlayerMovement.hpp"

PlayerMovementSystem::PlayerMovementSystem(entt::registry& registry)
    : registry(registry)
{
}

void PlayerMovementSystem::update()
{
    const auto view = registry.view<Position, PlayerMovement>();
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
    }
}
