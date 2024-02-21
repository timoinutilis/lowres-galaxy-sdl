//
//  SpriteAtlasCache.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 21.02.24.
//

#ifndef SpriteAtlasCache_hpp
#define SpriteAtlasCache_hpp

#include "entt.hpp"
#include "../Rendering/SpriteAtlas.hpp"

enum SpriteAtlasId
{
    SpriteAtlasIdSprites,
    SpriteAtlasIdBackground
};

struct SpriteAtlasLoader final {
    using result_type = std::shared_ptr<SpriteAtlas>;
    
    result_type operator()(SDL_Renderer* renderer, const std::string& filepath) const {
        return std::make_shared<SpriteAtlas>(renderer, filepath);
    }
};

using SpriteAtlasCache = entt::resource_cache<SpriteAtlas, SpriteAtlasLoader>;

#endif /* SpriteAtlasCache_hpp */
