//
//  SceneManager.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 21.02.24.
//

#include "SceneManager.hpp"
#include "Scene.hpp"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
    setCurrentScene(nullptr);
}

void SceneManager::setCurrentScene(std::shared_ptr<Scene> scene)
{
    if (currentScene != nullptr)
    {
        currentScene->onDisappear();
        currentScene->unload();
    }
    currentScene = scene;
    if (scene != nullptr)
    {
        currentScene->load();
        currentScene->onAppear();
    }
}

void SceneManager::setNextScene(std::shared_ptr<Scene> scene)
{
    nextScene = scene;
}

void SceneManager::update()
{
    if (nextScene != nullptr)
    {
        setCurrentScene(nextScene);
        nextScene = nullptr;
    }
    if (currentScene != nullptr)
    {
        currentScene->update();
    }
}

void SceneManager::render()
{
    if (currentScene != nullptr)
    {
        currentScene->render();
    }
}
