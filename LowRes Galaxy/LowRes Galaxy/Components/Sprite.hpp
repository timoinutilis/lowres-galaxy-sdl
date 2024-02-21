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
#include "../Rendering/SpriteAtlas.hpp"

struct Sprite final
{
    entt::resource<SpriteAtlas> spriteAtlas;
    std::string frame;
    bool isHidden = false;
};

#endif /* Sprite_h */
