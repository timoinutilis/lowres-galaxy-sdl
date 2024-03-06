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

struct SpriteFrame final
{
    SDL_Rect rect;
    SDL_Point pivot;
};

class SpriteAtlas final
{
public:
    SpriteAtlas(SDL_Renderer* renderer, const std::string& filepath, bool supportsFx);
    ~SpriteAtlas();
    
    void drawFrame(SDL_Renderer* renderer, const std::string& name, const int x, const int y, SDL_Color fxColor = {0, 0, 0, 0}) const;
    
private:
    SDL_Texture *texture;
    SDL_Texture *fxTexture;
    std::unordered_map<std::string, SpriteFrame> frames;
};

#endif /* SpriteAtlas_hpp */
