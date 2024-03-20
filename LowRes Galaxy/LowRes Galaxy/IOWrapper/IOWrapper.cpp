//
//  IOWrapper.cpp
//  LowRes Galaxy ZERO
//
//  Created by Timo Kloss on 20.03.24.
//

#include "IOWrapper.hpp"
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>

IOWrapper::IOWrapper()
{
    // initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER))
    {
        throw std::runtime_error(SDL_GetError());
    }
}

IOWrapper::~IOWrapper()
{
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
    }
    
    if (window)
    {
        SDL_DestroyWindow(window);
    }
    
    Mix_CloseAudio();
    
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

void IOWrapper::initVideo(const std::string& title, const int width, const int height, const int defaultWindowScale)
{
    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        throw std::runtime_error("IMG_Init failed");
    }
    
    // create window
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width * defaultWindowScale, height * defaultWindowScale, SDL_WINDOW_RESIZABLE | SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr)
    {
        throw std::runtime_error(SDL_GetError());
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        throw std::runtime_error(SDL_GetError());
    }
    
    SDL_RenderSetLogicalSize(renderer, width, height);
    SDL_ShowCursor(SDL_DISABLE);
}

void IOWrapper::initAudio(const int frequency, const int channels)
{
    if (Mix_Init(MIX_INIT_OGG) != MIX_INIT_OGG)
    {
        throw std::runtime_error("Mix_Init failed");
    }
    
    // start audio
    if (Mix_OpenAudio(frequency, MIX_DEFAULT_FORMAT, 2, 2048))
    {
        throw std::runtime_error("Mix_OpenAudio failed");
    }
    
    if (Mix_AllocateChannels(channels) != channels)
    {
        throw std::runtime_error("Mix_AllocateChannels failed");
    }
}

SDL_Renderer* IOWrapper::getRenderer()
{
    return renderer;
}
