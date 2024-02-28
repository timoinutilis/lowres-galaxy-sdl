//
//  Scene.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 03.02.24.
//

#include "Scene.hpp"
#include <iostream>

Scene::Scene(SDL_Renderer* renderer, SceneManager& sceneManager)
    : renderer(renderer)
    , sceneManager(sceneManager)
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

SpriteAtlasCache& Scene::getSpriteAtlasCache()
{
    return spriteAtlasCache;
}

FontCache& Scene::getFontCache()
{
    return fontCache;
}

MusicCache& Scene::getMusicCache()
{
    return musicCache;
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
