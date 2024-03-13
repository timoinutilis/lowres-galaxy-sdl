//
//  AudioClip.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 13.03.24.
//

#ifndef AudioClip_hpp
#define AudioClip_hpp

#include <string>
#include <SDL2_mixer/SDL_mixer.h>

class AudioClip final
{
public:
    AudioClip(const std::string& filepath);
    ~AudioClip();
    
    void play() const;
    
private:
    Mix_Chunk* chunk;
};

#endif /* AudioClip_hpp */
