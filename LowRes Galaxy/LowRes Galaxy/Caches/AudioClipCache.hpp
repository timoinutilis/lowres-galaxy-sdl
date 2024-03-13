//
//  AudioClipCache.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 13.03.24.
//

#ifndef AudioClipCache_h
#define AudioClipCache_h

#include "entt.hpp"
#include "../Sound/AudioClip.hpp"

enum AudioClipId
{
    AudioClipLevelUp,
    AudioClipPlayerShot,
    AudioClipPlayerExplosion,
    AudioClipEnemyShot,
    AudioClipEnemyHit,
    AudioClipExplosion
};

struct AudioClipLoader final {
    using result_type = std::shared_ptr<AudioClip>;
    
    result_type operator()(const std::string& filepath) const {
        return std::make_shared<AudioClip>(filepath);
    }
};

using AudioClipCache = entt::resource_cache<AudioClip, AudioClipLoader>;

#endif /* AudioClipCache_h */
