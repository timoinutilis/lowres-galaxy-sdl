//
//  Music.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 21.02.24.
//

#ifndef Music_hpp
#define Music_hpp

#include <string>
#include <SDL2_mixer/SDL_mixer.h>

class Music
{
public:
    Music(const std::string& filepath);
    ~Music();
    
    void play();
    void halt();
    
private:
    Mix_Music* music;
};

#endif /* Music_hpp */
