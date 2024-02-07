//
//  Scene.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 03.02.24.
//

#include "Scene.hpp"
#include "Components/Position.hpp"
#include "Components/Sprite.hpp"
#include "Components/PlayerMovement.hpp"
#include "Components/LocalPlayer.hpp"
#include "Components/AutoScroll.hpp"

Scene::Scene(SDL_Renderer* renderer)
    : renderer(renderer)
    , spriteRenderer(renderer, registry)
    , playerMoveSystem(registry)
    , localPlayerSystem(registry)
    , autoScrollSystem(registry)
{
}

void Scene::load()
{
    spriteAtlas = new SpriteAtlas(renderer, "Textures/sprites");
    bgSpriteAtlas = new SpriteAtlas(renderer, "Textures/background");
    music = Mix_LoadMUS("Audio/title.ogg");
    
    {
        const auto entity = registry.create();
        registry.emplace<Position>(entity, 0.0, 128.0 - 27.0);
        registry.emplace<Sprite>(entity, bgSpriteAtlas, "background_layer_3");
        registry.emplace<AutoScroll>(entity, 256, 1.0);
    }
    {
        const auto entity = registry.create();
        registry.emplace<Position>(entity, 256.0, 128.0 - 27.0);
        registry.emplace<Sprite>(entity, bgSpriteAtlas, "background_layer_3");
        registry.emplace<AutoScroll>(entity, 256, 1.0);
    }
    {
        const auto entity = registry.create();
        registry.emplace<Position>(entity, 32.0, 48.0);
        registry.emplace<Sprite>(entity, spriteAtlas, "ship");
        registry.emplace<PlayerMovement>(entity);
        registry.emplace<LocalPlayer>(entity, 0);
    }
    {
        const auto entity = registry.create();
        registry.emplace<Position>(entity, 160.0 - 32.0, 48.0);
        registry.emplace<Sprite>(entity, spriteAtlas, "enemy_blue_big-0");
    }
    {
        const auto entity = registry.create();
        registry.emplace<Position>(entity, 0.0, 128.0 - 67.0);
        registry.emplace<Sprite>(entity, bgSpriteAtlas, "background_layer_2");
        registry.emplace<AutoScroll>(entity, 256, 0.5);
    }
    {
        const auto entity = registry.create();
        registry.emplace<Position>(entity, 256.0, 128.0 - 67.0);
        registry.emplace<Sprite>(entity, bgSpriteAtlas, "background_layer_2");
        registry.emplace<AutoScroll>(entity, 256, 0.5);
    }
    {
        const auto entity = registry.create();
        registry.emplace<Position>(entity, 0.0, 0.0);
        registry.emplace<Sprite>(entity, bgSpriteAtlas, "background_layer_1");
        registry.emplace<AutoScroll>(entity, 256, 0.125);
    }
    {
        const auto entity = registry.create();
        registry.emplace<Position>(entity, 256.0, 0.0);
        registry.emplace<Sprite>(entity, bgSpriteAtlas, "background_layer_1");
        registry.emplace<AutoScroll>(entity, 256, 0.125);
    }
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
    Mix_PlayMusic(music, -1);
}

void Scene::onDisappear()
{
    Mix_HaltMusic();
}

void Scene::update()
{
    autoScrollSystem.update();
    localPlayerSystem.update();
    playerMoveSystem.update();
}

void Scene::render()
{
    spriteRenderer.render();
}
