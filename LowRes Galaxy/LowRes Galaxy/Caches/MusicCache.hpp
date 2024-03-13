//
//  MusicCache.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 21.02.24.
//

#ifndef MusicCache_h
#define MusicCache_h

#include "entt.hpp"
#include "../Sound/Music.hpp"

enum MusicId
{
    MusicIdTitle,
    MusicIdGame,
    MusicIdGameOver
};

struct MusicLoader final {
    using result_type = std::shared_ptr<Music>;
    
    result_type operator()(const std::string& filepath) const {
        return std::make_shared<Music>(filepath);
    }
};

using MusicCache = entt::resource_cache<Music, MusicLoader>;

#endif /* MusicCache_h */
