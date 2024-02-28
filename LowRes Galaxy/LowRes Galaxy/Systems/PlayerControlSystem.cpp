//
//  PlayerControlSystem.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#include "PlayerControlSystem.hpp"
#include <iostream>
#include "entt.hpp"
#include "../Factories/SpriteFactory.hpp"
#include "../Scenes/Scene.hpp"
#include "../Components/Position.hpp"
#include "../Components/PlayerInput.hpp"
#include "../Components/PlayerStatus.hpp"
#include "../Components/Sprite.hpp"
#include "../Events/AddScoreEvent.hpp"
#include "../Events/ScoreChangedEvent.hpp"
#include "../Events/HitEvent.hpp"
#include "../Events/LivesChangedEvent.hpp"
#include "Config.hpp"

PlayerControlSystem::PlayerControlSystem(Scene& scene)
    : scene(scene)
{
}

void PlayerControlSystem::connectEvents() const
{
    scene.getDispatcher().sink<AddScoreEvent>().connect<&PlayerControlSystem::onAddScore>(*this);
    scene.getDispatcher().sink<HitEvent>().connect<&PlayerControlSystem::onHit>(*this);
}

void PlayerControlSystem::disconnectEvents() const
{
    scene.getDispatcher().sink<AddScoreEvent>().disconnect(this);
    scene.getDispatcher().sink<HitEvent>().disconnect(this);
}

void PlayerControlSystem::update() const
{
    const auto view = scene.getRegistry().view<PlayerStatus, PlayerInput, Position, Sprite>();
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
        if (position.x > Config::screenWidth - 32)
        {
            position.x = Config::screenWidth - 32;
        }
        if (position.y < 0)
        {
            position.y = 0;
        }
        if (position.y > Config::screenHeight - 16)
        {
            position.y = Config::screenHeight - 16;
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
                SpriteFactory::createShot(scene, entity, position.x + 8.0, position.y + 11.0);
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

void PlayerControlSystem::onAddScore(const AddScoreEvent& event) const
{
    std::cout << "PlayerControlSystem::onAddScore " << event.points << "\n";
    auto& status = scene.getRegistry().get<PlayerStatus>(event.entity);
    status.score += event.points;
    scene.getDispatcher().enqueue<ScoreChangedEvent>(event.entity, status.score);
}

void PlayerControlSystem::onHit(const HitEvent& event) const
{
    std::cout << "PlayerControlSystem::onHit\n";
    auto& status = scene.getRegistry().get<PlayerStatus>(event.entity);
    
    if (status.shield == 0 && status.lives > 0)
    {
        --status.lives;
        
        auto& position = scene.getRegistry().get<Position>(event.entity);
        
        SpriteFactory::createExplosion(scene, position.x, position.y);
        SpriteFactory::createExplosion(scene, position.x - 8.0 + scene.getRandom().getDouble() * 16.0, position.y - 8.0 + scene.getRandom().getDouble() * 16.0);
        SpriteFactory::createExplosion(scene, position.x - 8.0 + scene.getRandom().getDouble() * 16.0, position.y - 8.0 + scene.getRandom().getDouble() * 16.0);
        
        if (status.lives > 0)
        {
            status.hide = Config::hide;
            status.shield = Config::shield;
        }
        
        scene.getDispatcher().enqueue<LivesChangedEvent>(event.entity, status.lives);
    }
}
