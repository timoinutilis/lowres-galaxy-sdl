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

void Scene::render()
{
    spriteRenderer.render();
    labelRenderer.render();
}
