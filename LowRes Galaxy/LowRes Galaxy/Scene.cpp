//
//  Scene.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 03.02.24.
//

#include "Scene.hpp"

Scene::Scene(SDL_Renderer* renderer)
    : renderer(renderer)
{
}

SDL_Renderer* Scene::getRenderer()
{
    return renderer;
}

entt::registry& Scene::getRegistry()
{
    return registry;
}

void Scene::load()
{
    spriteAtlas = new SpriteAtlas(renderer, "Textures/sprites");
    bgSpriteAtlas = new SpriteAtlas(renderer, "Textures/background");
    music = Mix_LoadMUS("Audio/title.ogg");
    
    BackgroundFactory::createLayer3(this, 0.0);
    BackgroundFactory::createLayer3(this, 256.0);
    
    SpriteFactory::createShip(this, 32.0, 48.0);
    SpriteFactory::createEnemy(this, 160.0 - 32.0, 48.0);
    
    BackgroundFactory::createLayer2(this, 0.0);
    BackgroundFactory::createLayer2(this, 256.0);
    BackgroundFactory::createLayer1(this, 0.0);
    BackgroundFactory::createLayer1(this, 256.0);
}

void Scene::unload()
{
    delete spriteAtlas;
    spriteAtlas = nullptr;
    
    delete bgSpriteAtlas;
    bgSpriteAtlas = nullptr;
    
    Mix_FreeMusic(music);
    music = nullptr;
}

void Scene::onAppear()
{
//    Mix_PlayMusic(music, -1);
}

void Scene::onDisappear()
{
//    Mix_HaltMusic();
}

void Scene::update()
{
    autoScrollSystem.update(this);
    localPlayerSystem.update(this);
    playerMoveSystem.update(this);
    moveSystem.update(this);
}

void Scene::render()
{
    spriteRenderer.render(this);
}
