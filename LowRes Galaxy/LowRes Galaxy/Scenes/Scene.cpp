//
//  Scene.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 03.02.24.
//

#include "Scene.hpp"
#include <iostream>
#include "../Components/PlayerStatus.hpp"

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

Random& Scene::getRandom()
{
    return random;
}

entt::entity Scene::getPlayerEntity()
{
    const auto view = registry.view<PlayerStatus>();
    return view.front();
}

bool Scene::isPeace()
{
    return peace > 0;
}

void Scene::load()
{
    font = new Font(renderer, "Textures/font");
    spriteAtlas = new SpriteAtlas(renderer, "Textures/sprites");
    bgSpriteAtlas = new SpriteAtlas(renderer, "Textures/background");
    music = Mix_LoadMUS("Audio/title.ogg");
    
    BackgroundFactory::createLayer1(this, 0.0);
    BackgroundFactory::createLayer1(this, 256.0);
    BackgroundFactory::createLayer2(this, 0.0);
    BackgroundFactory::createLayer2(this, 256.0);
    BackgroundFactory::createLayer3(this, 0.0);
    BackgroundFactory::createLayer3(this, 256.0);
    
    SpriteFactory::createShip(this, 32.0, 48.0);
}

void Scene::unload()
{
    delete font;
    font = nullptr;
    
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
                    SpriteFactory::createSmallBlueAlien(this);
                    break;
                case 1:
                    SpriteFactory::createSmallRedAlien(this);
            }
        }
        
        // spawn big alien?
        int m2 = 5400 / (level + 2);
        if (tick % m2 == m2 / 2)
        {
            switch (random.getInt(2))
            {
                case 0:
                    SpriteFactory::createBigBlueAlien(this);
                    break;
                case 1:
                    SpriteFactory::createBigRedAlien(this);
            }
        }
    }
    
    // systems
    autoScrollSystem.update(this);
    localPlayerSystem.update(this);
    playerControlSystem.update(this);
    moveSystem.update(this);
    alienControlSystem.update(this);
    shotCollisionSystem.update(this);
    playerCollisionSystem.update(this);
    animationSystem.update(this);
    
    ++tick;
}

void Scene::render()
{
    spriteRenderer.render(this);
    
    font->drawString(renderer, "HELLO LOWRES GALAXY", 4, 0);
}
