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

SpriteAtlas::SpriteAtlas(SDL_Renderer* renderer, const std::string& filepath)
{
    SDL_Surface* image = IMG_Load((filepath + ".png").c_str());
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    
    const char* cBasePath = SDL_GetBasePath();
    std::string basePath(cBasePath);
    SDL_free((void*)cBasePath);
    
    std::ifstream file(basePath + filepath + ".json");
    nlohmann::json data = nlohmann::json::parse(file);
    for (auto& frame : data["frames"])
    {
        auto& srcFrame = frame["frame"];
        SDL_Rect rect {srcFrame["x"], srcFrame["y"], srcFrame["w"], srcFrame["h"]};
        frames.insert({frame["filename"], rect});
    }
}

SpriteAtlas::~SpriteAtlas()
{
    SDL_DestroyTexture(texture);
}

void SpriteAtlas::drawFrame(SDL_Renderer* renderer, const std::string& name, const int x, const int y)
{
    const auto& frame = frames.at(name);
    SDL_Rect dst = {x, y, frame.w, frame.h};
    SDL_RenderCopy(renderer, texture, &frame, &dst);
}
