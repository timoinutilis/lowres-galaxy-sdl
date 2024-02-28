//
//  GameScene.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 21.02.24.
//

#include "GameScene.hpp"
#include <iostream>
#include "../Factories/BackgroundFactory.hpp"
#include "../Factories/SpriteFactory.hpp"
#include "../Factories/UIFactory.hpp"
#include "../Components/PlayerStatus.hpp"
#include "Config.hpp"

GameScene::GameScene(SDL_Renderer* renderer, SceneManager& sceneManager)
    : Scene(renderer, sceneManager)
    , playerControlSystem(*this)
    , localPlayerSystem(*this)
    , autoScrollSystem(*this)
    , moveSystem(*this)
    , alienControlSystem(*this)
    , shotCollisionSystem(*this)
    , playerCollisionSystem(*this)
    , animationSystem(*this)
{
    std::cout << "hello GameScene\n";
}

GameScene::~GameScene()
{
    std::cout << "bye GameScene\n";
}

entt::entity GameScene::getPlayerEntity()
{
    const auto view = registry.view<PlayerStatus>();
    return view.front();
}

bool GameScene::isPeace() const
{
    return peace > 0;
}

void GameScene::load()
{
    musicCache.load(MusicIdGame, "Audio/game.ogg");
    fontCache.load(FontIdDefault, getRenderer(), "Textures/font");
    spriteAtlasCache.load(SpriteAtlasIdSprites, getRenderer(), "Textures/sprites");
    spriteAtlasCache.load(SpriteAtlasIdBackground, getRenderer(), "Textures/background");
    
    BackgroundFactory::createLayer1(*this, 0.0);
    BackgroundFactory::createLayer1(*this, 256.0);
    BackgroundFactory::createLayer2(*this, 0.0);
    BackgroundFactory::createLayer2(*this, 256.0);
    BackgroundFactory::createLayer3(*this, 0.0);
    BackgroundFactory::createLayer3(*this, 256.0);
    
    SpriteFactory::createShip(*this, 32.0, 48.0);
}

void GameScene::unload()
{
}

void GameScene::onAppear()
{
    musicCache[MusicIdGame]->play();
}

void GameScene::onDisappear()
{
    musicCache[MusicIdGame]->halt();
}

void GameScene::update()
{
    // next level?
    if (/*LIVES>0 AND*/ tick % 1800 == 0)
    {
        ++level;
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
            switch (random.getInt(2))
            {
                case 0:
                    SpriteFactory::createSmallBlueAlien(*this);
                    break;
                case 1:
                    SpriteFactory::createSmallRedAlien(*this);
            }
        }
        
        // spawn big alien?
        int m2 = 5400 / (level + 2);
        if (tick % m2 == m2 / 2)
        {
            switch (random.getInt(2))
            {
                case 0:
                    SpriteFactory::createBigBlueAlien(*this);
                    break;
                case 1:
                    SpriteFactory::createBigRedAlien(*this);
            }
        }
    }
    
    // systems
    autoScrollSystem.update();
    localPlayerSystem.update();
    playerControlSystem.update();
    moveSystem.update();
    alienControlSystem.update();
    shotCollisionSystem.update();
    playerCollisionSystem.update();
    animationSystem.update();
    
    ++tick;
}
