#include <memory>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include "entt.hpp"
#include "Caches/FontCache.hpp"
#include "Caches/SpriteAtlasCache.hpp"
#include "Caches/MusicCache.hpp"
#include "Scenes/SceneManager.hpp"
#include "Scenes/TitleScene.hpp"
#include "Config.hpp"
#include "Input/InputManager.hpp"

int main( int argc, char* args[] )
{
    bool quit = false;
    SDL_Event event;
    
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER);
    IMG_Init(IMG_INIT_PNG);
    Mix_Init(MIX_INIT_OGG);
    
    SDL_Window* window = SDL_CreateWindow("LowRes Galaxy", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Config::screenWidth * Config::defaultWindowScale, Config::screenHeight * Config::defaultWindowScale, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_RenderSetLogicalSize(renderer, Config::screenWidth, Config::screenHeight);
    
    Mix_OpenAudio(48000, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_AllocateChannels(2);
    
    {
        entt::locator<FontCache>::emplace<FontCache>();
        entt::locator<SpriteAtlasCache>::emplace<SpriteAtlasCache>();
        entt::locator<MusicCache>::emplace<MusicCache>();
        
        SceneManager sceneManager;
        InputManager inputManager;
        
        sceneManager.setNextScene(std::make_unique<TitleScene>(renderer, sceneManager, inputManager));
        
        while (!quit)
        {
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
            
            sceneManager.update();
            
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
