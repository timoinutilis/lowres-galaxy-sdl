#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>

int main( int argc, char* args[] )
{
    bool quit = false;
    SDL_Event event;
    
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    IMG_Init(IMG_INIT_PNG);
    Mix_Init(MIX_INIT_OGG);
    
    SDL_Window* window = SDL_CreateWindow("LowRes Galaxy", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface* image = IMG_Load("Textures/sprites.png");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
    
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_AllocateChannels(2);
    
    Mix_Music* music = Mix_LoadMUS("Audio/title.ogg");
    Mix_PlayMusic(music, -1);
    
    while (!quit)
    {
        SDL_WaitEvent(&event);
        
        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
        }
        
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }
    
    Mix_CloseAudio();
    
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
    
    return 0;
}
