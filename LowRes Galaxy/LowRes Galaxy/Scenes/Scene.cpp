//
//  Scene.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 03.02.24.
//

#include "Scene.hpp"
#include <iostream>

Scene::Scene(SDL_Renderer* renderer, SceneManager& sceneManager, InputManager& inputManager)
    : renderer(renderer)
    , sceneManager(sceneManager)
    , inputManager(inputManager)
    , spriteRenderer(*this)
    , labelRenderer(*this)
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

entt::dispatcher& Scene::getDispatcher()
{
    return dispatcher;
}

SceneManager& Scene::getSceneManager()
{
    return sceneManager;
}

InputManager& Scene::getInputManager()
{
    return inputManager;
}

SpriteAtlasCache& Scene::getSpriteAtlasCache()
{
    return entt::locator<SpriteAtlasCache>::value();
}

FontCache& Scene::getFontCache()
{
    return entt::locator<FontCache>::value();
}

MusicCache& Scene::getMusicCache()
{
    return entt::locator<MusicCache>::value();
}

Random& Scene::getRandom()
{
    return random;
}

void Scene::update()
{
    dispatcher.update();
}

void Scene::render()
{
    spriteRenderer.render();
    labelRenderer.render();
}
