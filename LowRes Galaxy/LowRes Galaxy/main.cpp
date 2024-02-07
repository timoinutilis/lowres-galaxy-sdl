#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include "Scene.hpp"

int main( int argc, char* args[] )
{
    bool quit = false;
    SDL_Event event;
    
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    IMG_Init(IMG_INIT_PNG);
    Mix_Init(MIX_INIT_OGG);
    
    SDL_Window* window = SDL_CreateWindow("LowRes Galaxy", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 512, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_RenderSetLogicalSize(renderer, 160, 128);
    
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_AllocateChannels(2);
    
    Scene scene(renderer);
    scene.load();
    scene.onAppear();
    
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
        }
        
        scene.update();
        
        SDL_RenderClear(renderer);
        scene.render();
        SDL_RenderPresent(renderer);
    }
    
    scene.onDisappear();
    scene.unload();
    
    Mix_CloseAudio();
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
    
    return 0;
}
