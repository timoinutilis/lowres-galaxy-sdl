//
//  SpriteAtlas.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 28.01.24.
//

#ifndef SpriteAtlas_hpp
#define SpriteAtlas_hpp

#include <SDL2/SDL.h>
#include <string>

struct SpriteFrame
{
    SDL_Rect rect;
    SDL_Point pivot;
};

class SpriteAtlas
{
public:
    SpriteAtlas(SDL_Renderer* renderer, const std::string& filepath);
    ~SpriteAtlas();
    
    void drawFrame(SDL_Renderer* renderer, const std::string& name, const int x, const int y);
    
private:
    SDL_Texture *texture;
    std::unordered_map<std::string, SpriteFrame> frames;
};

#endif /* SpriteAtlas_hpp */
