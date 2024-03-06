//
//  SceneManager.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 21.02.24.
//

#include "SceneManager.hpp"
#include "Scene.hpp"
#include "../Config.hpp"

SceneManager::SceneManager(SDL_Renderer* renderer, int fadeTicks)
    : renderer(renderer)
    , fadeTicks(fadeTicks)
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
    switch (state)
    {
        case SceneManagerState::inactive:
        {
            if (nextScene != nullptr)
            {
                setCurrentScene(nextScene);
                nextScene = nullptr;
                state = SceneManagerState::fadingIn;
                ticks = 0;
            }
            break;
        }
        case SceneManagerState::fadingIn:
        {
            if (++ticks >= fadeTicks)
            {
                state = SceneManagerState::active;
            }
            break;
        }
        case SceneManagerState::active:
        {
            if (nextScene != nullptr)
            {
                state = SceneManagerState::fadingOut;
                ticks = 0;
            }
            break;
        }
        case SceneManagerState::fadingOut:
        {
            if (++ticks >= fadeTicks)
            {
                if (nextScene != nullptr)
                {
                    setCurrentScene(nextScene);
                    nextScene = nullptr;
                    state = SceneManagerState::fadingIn;
                    ticks = 0;
                }
                else
                {
                    state = SceneManagerState::inactive;
                }
            }
            break;
        }
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
    switch (state)
    {
        case SceneManagerState::fadingIn:
        {
            SDL_Rect rect {0, 0, Config::screenWidth, Config::screenHeight};
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255 - ticks * 255 / fadeTicks);
            SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
            SDL_RenderFillRect(renderer, &rect);
            break;
        }
        case SceneManagerState::fadingOut:
        {
            SDL_Rect rect {0, 0, Config::screenWidth, Config::screenHeight};
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, ticks * 255 / fadeTicks);
            SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
            SDL_RenderFillRect(renderer, &rect);
            break;
        }
        default:
            break;
    }
}
