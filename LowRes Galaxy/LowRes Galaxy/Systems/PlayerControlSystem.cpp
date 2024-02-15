//
//  PlayerControlSystem.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#include "PlayerControlSystem.hpp"
#include "entt.hpp"
#include "../Factories/SpriteFactory.hpp"
#include "../Scenes/Scene.hpp"
#include "../Components/Position.hpp"
#include "../Components/PlayerInput.hpp"
#include "../Components/PlayerStatus.hpp"
#include "../Components/Sprite.hpp"

void PlayerControlSystem::update(Scene* scene)
{
    const auto view = scene->getRegistry().view<PlayerStatus, PlayerInput, Position, Sprite>();
    for (auto entity : view)
    {
        auto& status = view.get<PlayerStatus>(entity);
        auto& sprite = view.get<Sprite>(entity);
        
        if (status.lives == 0)
        {
            sprite.isHidden = true;
            continue;
        }
        
        if (status.hide > 0)
        {
            sprite.isHidden = true;
            --status.hide;
            continue;
        }
        
        auto& input = view.get<PlayerInput>(entity);
        auto& position = view.get<Position>(entity);
        
        position.x += input.directionX;
        position.y += input.directionY;
        
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
        
        // shield
        if (status.shield > 0)
        {
            sprite.isHidden = (status.shield % 4 < 2);
            --status.shield;
        }
        else
        {
            sprite.isHidden = false;
        }
        
        --status.shootDelay;
        if (input.isShooting)
        {
            if (status.shootDelay <= 0) {
                SpriteFactory::createShot(scene, position.x + 8.0, position.y + 11.0);
                ++status.heat;
                if (status.heat >= 5)
                {
                    status.shootDelay = 30;
                    status.heat = 0;
                }
                else
                {
                    status.shootDelay = 8;
                }
            }
        }
        else
        {
            status.heat = 0;
        }
    }
}
