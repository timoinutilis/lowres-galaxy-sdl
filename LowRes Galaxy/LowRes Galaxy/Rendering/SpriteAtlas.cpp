//
//  SpriteAtlas.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 28.01.24.
//

#include "SpriteAtlas.hpp"
#include <SDL2_image/SDL_image.h>
#include "json.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

SpriteAtlas::SpriteAtlas(SDL_Renderer* renderer, const std::string& filepath, bool supportsFx)
{
    //TODO: complete resource cleanup on exceptions
    
    SDL_Surface* image = IMG_Load((filepath + ".png").c_str());
    if (image == nullptr)
    {
        throw std::runtime_error("IMG_Load failed for " + filepath);
    }
    
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    
    if (texture == nullptr)
    {
        throw std::runtime_error(SDL_GetError());
    }
    
    if (supportsFx)
    {
        SDL_Surface* fxImage = IMG_Load((filepath + "_fx.png").c_str());
        if (fxImage == nullptr)
        {
            throw std::runtime_error("IMG_Load failed for " + filepath + "_fx");
        }
        
        fxTexture = SDL_CreateTextureFromSurface(renderer, fxImage);
        SDL_FreeSurface(fxImage);
        
        if (fxTexture == nullptr)
        {
            throw std::runtime_error(SDL_GetError());
        }
        
        if (SDL_SetTextureBlendMode(fxTexture, SDL_BLENDMODE_ADD))
        {
            throw std::runtime_error(SDL_GetError());
        }
        
    }
    
    const char* cBasePath = SDL_GetBasePath();
    if (cBasePath == nullptr)
    {
        throw std::runtime_error(SDL_GetError());
    }
    
    std::string basePath(cBasePath);
    SDL_free((void*)cBasePath);
    
    std::ifstream file;
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    file.open(basePath + filepath + ".json");
    nlohmann::json data = nlohmann::json::parse(file);
    for (auto& frame : data["frames"])
    {
        auto& srcFrame = frame["frame"];
        SDL_Rect rect {srcFrame["x"], srcFrame["y"], srcFrame["w"], srcFrame["h"]};
        
        auto& srcPivot = frame["pivot"];
        double px = srcPivot["x"];
        double py = srcPivot["y"];
        SDL_Point pivot {static_cast<int>(px * rect.w), static_cast<int>(py * rect.h)};
        
        frames.insert({frame["filename"], SpriteFrame {rect, pivot}});
    }
}

SpriteAtlas::~SpriteAtlas()
{
    SDL_DestroyTexture(texture);
    if (fxTexture != nullptr)
    {
        SDL_DestroyTexture(fxTexture);
    }
}

void SpriteAtlas::drawFrame(SDL_Renderer* renderer, const std::string& name, const int x, const int y, SDL_Color fxColor) const
{
    const auto& frame = frames.at(name);
    SDL_Rect dst = {x - frame.pivot.x, y - frame.pivot.y, frame.rect.w, frame.rect.h};
    
    if (SDL_RenderCopy(renderer, texture, &frame.rect, &dst))
    {
        throw std::runtime_error(SDL_GetError());
    }
    
    if (fxColor.a > 0 && fxTexture != nullptr)
    {
        if (SDL_SetTextureColorMod(fxTexture, fxColor.r, fxColor.g, fxColor.b))
        {
            throw std::runtime_error(SDL_GetError());
        }
        
        if (SDL_SetTextureAlphaMod(fxTexture, fxColor.a))
        {
            throw std::runtime_error(SDL_GetError());
        }
        
        if (SDL_RenderCopy(renderer, fxTexture, &frame.rect, &dst))
        {
            throw std::runtime_error(SDL_GetError());
        }
    }
}
