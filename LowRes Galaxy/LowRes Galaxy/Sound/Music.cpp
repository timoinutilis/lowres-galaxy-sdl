//
//  Music.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 21.02.24.
//

#include "Music.hpp"
#include <stdexcept>

Music::Music(const std::string& filepath)
{
    music = Mix_LoadMUS(filepath.c_str());
    if (music == nullptr)
    {
        throw std::runtime_error("Mix_LoadMUS failed for " + filepath);
    }
}

Music::~Music()
{
    Mix_FreeMusic(music);
}

void Music::play() const
{
    if (Mix_PlayMusic(music, -1))
    {
        throw std::runtime_error("Mix_PlayMusic failed");
    }
}

void Music::halt() const
{
    Mix_HaltMusic();
}
