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

TitleScene::TitleScene(SDL_Renderer* renderer, SceneManager& sceneManager)
    : Scene(renderer, sceneManager)
{
    std::cout << "hello TitleScene\n";
}

TitleScene::~TitleScene()
{
    std::cout << "bye TitleScene\n";
}

void TitleScene::load()
{
    musicCache.load(MusicIdTitle, "Audio/title.ogg");
    fontCache.load(FontIdDefault, getRenderer(), "Textures/font");
    spriteAtlasCache.load(SpriteAtlasIdSprites, getRenderer(), "Textures/sprites");
    spriteAtlasCache.load(SpriteAtlasIdBackground, getRenderer(), "Textures/background");
    
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
    musicCache[MusicIdTitle]->play();
}

void TitleScene::onDisappear()
{
    musicCache[MusicIdTitle]->halt();
}

void TitleScene::update()
{
    const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
    
    if (keyboardState[SDL_SCANCODE_SPACE])
    {
        sceneManager.setNextScene(std::make_unique<GameScene>(getRenderer(), sceneManager));
    }
    
    // systems
    autoScrollSystem.update(*this);
}
