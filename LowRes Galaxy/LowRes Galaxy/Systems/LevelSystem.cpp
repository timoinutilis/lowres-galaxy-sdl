//
//  LevelSystem.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 28.02.24.
//

#include "LevelSystem.hpp"
#include "../Scenes/Scene.hpp"
#include "../Events/LevelChangedEvent.hpp"
#include "../Factories/SpriteFactory.hpp"
#include "Config.hpp"

LevelSystem::LevelSystem(Scene& scene)
    : scene(scene)
{
}

bool LevelSystem::isPeace() const
{
    return peace > 0;
}

void LevelSystem::connectEvents()
{
    scene.getDispatcher().sink<LivesChangedEvent>().connect<&LevelSystem::onLivesChanged>(*this);
}

void LevelSystem::disconnectEvents()
{
    scene.getDispatcher().sink<LivesChangedEvent>().disconnect(this);
}

void LevelSystem::update()
{
    // next level?
    if (canLevelUp && tick % 1800 == 0)
    {
        ++level;
        scene.getDispatcher().enqueue<LevelChangedEvent>(level);
    }
    
    // spawn enemies
    if (peace > 0)
    {
        // do not spawn enemies
        --peace;
    }
    else
    {
        // spawn small alien?
        int m1 = 480 / (level + 3);
        if (tick % m1 == 0)
        {
            switch (scene.getRandom().getInt(2))
            {
                case 0:
                    SpriteFactory::createSmallBlueAlien(scene);
                    break;
                case 1:
                    SpriteFactory::createSmallRedAlien(scene);
            }
        }
        
        // spawn big alien?
        int m2 = 5400 / (level + 2);
        if (tick % m2 == m2 / 2)
        {
            switch (scene.getRandom().getInt(2))
            {
                case 0:
                    SpriteFactory::createBigBlueAlien(scene);
                    break;
                case 1:
                    SpriteFactory::createBigRedAlien(scene);
            }
        }
    }
    
    ++tick;
}

void LevelSystem::onLivesChanged(const LivesChangedEvent& event)
{
    if (event.lives > 0)
    {
        peace = Config::peace;
    }
    else
    {
        canLevelUp = false;
    }
}
