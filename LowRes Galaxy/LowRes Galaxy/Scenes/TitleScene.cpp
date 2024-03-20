//
//  TitleScene.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 21.02.24.
//

#include "TitleScene.hpp"
#include <iostream>
#include <sstream>
#include "../Highscores/HighscoreManager.hpp"
#include "../Factories/BackgroundFactory.hpp"
#include "../Factories/SpriteFactory.hpp"
#include "../Factories/UIFactory.hpp"
#include "GameScene.hpp"
#include "Config.hpp"

TitleScene::TitleScene(IOWrapper& ioWrapper, SceneManager& sceneManager, InputManager& inputManager) noexcept
    : Scene(ioWrapper, sceneManager, inputManager)
    , autoScrollSystem(*this)
    , autoDestroySystem(*this)
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::load()
{
    BackgroundFactory::createLayer1(*this, 0.0);
    BackgroundFactory::createLayer1(*this, 256.0);
    BackgroundFactory::createLayer2(*this, 0.0);
    BackgroundFactory::createLayer2(*this, 256.0);
    BackgroundFactory::createLayer3(*this, 0.0);
    BackgroundFactory::createLayer3(*this, 256.0);
    
    UIFactory::createImage(*this, SpriteAtlasIdSprites, "title", (Config::screenWidth - 94.0) * 0.5, 16.0);
    
    UIFactory::createScrollingLabel(*this, "A GAME BY TIMO KLOSS ... (C)2024 ... INUTILIS.COM ...", Config::screenWidth + 60.0, Config::screenHeight - 40.0);
}

void TitleScene::unload()
{
}

void TitleScene::onAppear()
{
    inputManager.getActionSink().connect<&TitleScene::onInputAction>(this);
    getMusicCache()[MusicIdTitle]->play();
}

void TitleScene::onDisappear()
{
    inputManager.getActionSink().disconnect(this);
    getMusicCache()[MusicIdTitle]->halt();
}

void TitleScene::update()
{
    if (tick % 240 == 0)
    {
        UIFactory::createMessage(*this, "PRESS FIRE TO START!");
    }
    else if (tick % 240 == 120)
    {
        auto& highscoreManager = entt::locator<HighscoreManager>::value();
        std::ostringstream oss;
        oss << "HIGHSCORE: " << std::to_string(highscoreManager.getHighscore());
        UIFactory::createMessage(*this, oss.str());
    }
    
    // systems
    autoScrollSystem.update();
    autoDestroySystem.update();
    
    dispatcher.update();
    
    ++tick;
}

void TitleScene::onInputAction(const InputAction action)
{
    if (action == InputAction::fire)
    {
        sceneManager.setNextScene(std::make_unique<GameScene>(getIOWrapper(), sceneManager, inputManager));
    }
}
