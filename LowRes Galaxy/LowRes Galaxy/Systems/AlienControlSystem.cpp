//
//  AlienControlSystem.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 14.02.24.
//

#include "AlienControlSystem.hpp"
#include <cmath>
#include "entt.hpp"
#include "../Scenes/GameScene.hpp"
#include "../Components/Position.hpp"
#include "../Components/AlienStatus.hpp"
#include "../Components/PlayerStatus.hpp"
#include "../Factories/SpriteFactory.hpp"
#include "Config.hpp"

AlienControlSystem::AlienControlSystem(GameScene& scene)
    : scene(scene)
{
}

void AlienControlSystem::update() const
{
    const auto view = scene.getRegistry().view<Position, AlienStatus>();
    for (auto entity : view)
    {
        auto& position = view.get<Position>(entity);
        auto& status = view.get<AlienStatus>(entity);
        
        ++status.tick;
        
        position.x = Config::screenWidth - status.tick * status.speedX - std::sin(status.tick * 0.03) * 24.0;
        position.y = status.startY + std::sin(status.tick * status.speedY) * status.amplitude;
        
        if (!scene.isPeace() && position.x > 50.0 && status.tick % 120 == 30)
        {
            auto playerEntity = scene.getPlayerEntity();
            if (playerEntity != entt::null)
            {
                auto playerPosition = scene.getRegistry().get<Position>(playerEntity);
                SpriteFactory::createEnemyShot(scene, position.x + 4.0, position.y + 4.0, playerPosition.x + 6.0, playerPosition.y + 6.0);
            }
        }
        
        if (position.x < -32.0)
        {
            scene.getRegistry().destroy(entity);
        }
    }
}
