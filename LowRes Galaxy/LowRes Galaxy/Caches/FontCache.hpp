//
//  FontCache.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 21.02.24.
//

#ifndef FontCache_h
#define FontCache_h

#include "entt.hpp"
#include "../Rendering/Font.hpp"

enum FontId
{
    FontIdDefault,
};

struct FontLoader final {
    using result_type = std::shared_ptr<Font>;
    
    result_type operator()(SDL_Renderer* renderer, const std::string& filepath) const {
        return std::make_shared<Font>(renderer, filepath);
    }
};

using FontCache = entt::resource_cache<Font, FontLoader>;

#endif /* FontCache_h */
