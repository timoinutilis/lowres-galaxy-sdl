#include <memory>
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
#include "Input/InputManager.hpp"
#include "Highscores/HighscoreManager.hpp"

int main( int argc, char* args[] )
{
    bool quit = false;
    SDL_Event event;
    
    // initialize SDL
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER);
    IMG_Init(IMG_INIT_PNG);
    Mix_Init(MIX_INIT_OGG);
    
    // create window
    SDL_Window* window = SDL_CreateWindow("LowRes Galaxy ZERO", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Config::screenWidth * Config::defaultWindowScale, Config::screenHeight * Config::defaultWindowScale, SDL_WINDOW_RESIZABLE | SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_RenderSetLogicalSize(renderer, Config::screenWidth, Config::screenHeight);
    SDL_ShowCursor(SDL_DISABLE);
    
    // start audio
    Mix_OpenAudio(48000, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_AllocateChannels(4);
    
    {
        // create caches
        entt::locator<FontCache>::emplace<FontCache>();
        entt::locator<SpriteAtlasCache>::emplace<SpriteAtlasCache>();
        entt::locator<MusicCache>::emplace<MusicCache>();
        entt::locator<AudioClipCache>::emplace<AudioClipCache>();
        
        // initialize game managers
        entt::locator<HighscoreManager>::emplace<HighscoreManager>();
        
        // initialize scene
        SceneManager sceneManager(renderer, 30);
        InputManager inputManager;
        
        sceneManager.setNextScene(std::make_unique<LaunchScene>(renderer, sceneManager, inputManager));
        
        // initialize time
        auto previousMillis = SDL_GetTicks();
        int lagMillis = 0;
        
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
            SDL_RenderClear(renderer);
            sceneManager.render();
            SDL_RenderPresent(renderer);
        }
    }
    
    Mix_CloseAudio();
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
    
    return 0;
}
