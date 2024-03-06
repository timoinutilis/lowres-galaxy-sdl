//
//  Sprite.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#ifndef Sprite_h
#define Sprite_h

#include <string>
#include <memory>
#include <SDL2/SDL.h>
#include "../Rendering/SpriteAtlas.hpp"

struct Sprite final
{
    entt::resource<SpriteAtlas> spriteAtlas;
    std::string frame;
    bool isHidden = false;
    SDL_Color fxColor {0, 0, 0, 0};
};

#endif /* Sprite_h */
