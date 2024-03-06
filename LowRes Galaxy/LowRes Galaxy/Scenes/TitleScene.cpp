//
//  TitleScene.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 21.02.24.
//

#include "TitleScene.hpp"
#include <iostream>
#include "../Factories/BackgroundFactory.hpp"
#include "../Factories/SpriteFactory.hpp"
#include "../Factories/UIFactory.hpp"
#include "GameScene.hpp"
#include "Config.hpp"

TitleScene::TitleScene(SDL_Renderer* renderer, SceneManager& sceneManager, InputManager& inputManager)
    : Scene(renderer, sceneManager, inputManager)
    , autoScrollSystem(*this)
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::load()
{
    getMusicCache().load(MusicIdTitle, "Audio/title.ogg");
    getFontCache().load(FontIdDefault, getRenderer(), "Textures/font");
    getSpriteAtlasCache().load(SpriteAtlasIdSprites, getRenderer(), "Textures/sprites", true);
    getSpriteAtlasCache().load(SpriteAtlasIdBackground, getRenderer(), "Textures/background", false);
    
    BackgroundFactory::createLayer1(*this, 0.0);
    BackgroundFactory::createLayer1(*this, 256.0);
    BackgroundFactory::createLayer2(*this, 0.0);
    BackgroundFactory::createLayer2(*this, 256.0);
    BackgroundFactory::createLayer3(*this, 0.0);
    BackgroundFactory::createLayer3(*this, 256.0);
    
    UIFactory::createImage(*this, SpriteAtlasIdSprites, "title", (Config::screenWidth - 94.0) * 0.5, 16.0);
    
    UIFactory::createScrollingLabel(*this, "LOWRES GALAXY 2 BY INUTILIS SOFTWARE ...", Config::screenWidth, 88.0);
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
    // systems
    autoScrollSystem.update();
    
    dispatcher.update();
}

void TitleScene::onInputAction(const InputAction action)
{
    if (action == InputAction::fire)
    {
        sceneManager.setNextScene(std::make_unique<GameScene>(getRenderer(), sceneManager, inputManager));
    }
}
