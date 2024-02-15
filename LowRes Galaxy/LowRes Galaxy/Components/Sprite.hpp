//
//  Sprite.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#ifndef Sprite_h
#define Sprite_h

#include <string>
#include "../Rendering/SpriteAtlas.hpp"

struct Sprite
{
    SpriteAtlas* spriteAtlas = nullptr;
    std::string frame;
    bool isHidden = false;
};

#endif /* Sprite_h */
