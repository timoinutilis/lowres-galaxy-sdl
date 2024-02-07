//
//  Sprite.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#ifndef Sprite_h
#define Sprite_h

#include <string>
#include "../SpriteAtlas.hpp"

struct Sprite
{
    SpriteAtlas* spriteAtlas;
    std::string frame;
};

#endif /* Sprite_h */
