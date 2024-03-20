#include <memory>
#include <iostream>
#include <cstdlib>
#include <exception>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include "entt.hpp"
#include "Caches/FontCache.hpp"
#include "Caches/SpriteAtlasCache.hpp"
#include "Caches/MusicCache.hpp"
#include "Caches/AudioClipCache.hpp"
#include "Scenes/SceneManager.hpp"
#include "Scenes/LaunchScene.hpp"
#include "Scenes/TitleScene.hpp"
#include "Config.hpp"
#include "IOWrapper/IOWrapper.hpp"
#include "Input/InputManager.hpp"
#include "Highscores/HighscoreManager.hpp"

int main( int argc, char* args[] )
{
    try
    {
        // initialize SDL
        IOWrapper ioWrapper;
        ioWrapper.initVideo("LowRes Galaxy ZERO", Config::screenWidth, Config::screenHeight, Config::defaultWindowScale);
        ioWrapper.initAudio(48000, 8);
        
        // create caches
        entt::locator<FontCache>::emplace<FontCache>();
        entt::locator<SpriteAtlasCache>::emplace<SpriteAtlasCache>();
        entt::locator<MusicCache>::emplace<MusicCache>();
        entt::locator<AudioClipCache>::emplace<AudioClipCache>();
        
        // initialize game managers
        entt::locator<HighscoreManager>::emplace<HighscoreManager>();
        
        // initialize scene
        SceneManager sceneManager(ioWrapper, 30);
        InputManager inputManager;
        
        sceneManager.setNextScene(std::make_unique<LaunchScene>(ioWrapper, sceneManager, inputManager));
        
        // initialize time
        auto previousMillis = SDL_GetTicks();
        int lagMillis = 0;
        
        bool quit = false;
        SDL_Event event;
        
        while (!quit)
        {
            // update time
            auto currentMillis = SDL_GetTicks();
            auto elapsedMillis = currentMillis - previousMillis;
            previousMillis = currentMillis;
            lagMillis += elapsedMillis;
            
            // handle input
            while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                    case SDL_QUIT:
                        quit = true;
                        break;
                }
                inputManager.handleSDLEvent(event);
            }
            
            // update game logic
            while (lagMillis >= Config::millisPerUpdate)
            {
                sceneManager.update();
                lagMillis -= Config::millisPerUpdate;
            }
            
            // avoid accumulating tiny lag inaccuracies
            if (lagMillis <= 2)
            {
                lagMillis = 0;
            }
            
            // render game
            SDL_Renderer* renderer = ioWrapper.getRenderer();
            SDL_RenderClear(renderer);
            sceneManager.render();
            SDL_RenderPresent(renderer);
        }
        
        return EXIT_SUCCESS;
    }
    catch (const std::exception& e)
    {
        if (SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Sorry, something went wrong", e.what(), nullptr))
        {
            // error popup failed, so just print out the error
            std::cerr << "Sorry, something went wrong: " << e.what() << std::endl;
        }
        return EXIT_FAILURE;
    }
}
