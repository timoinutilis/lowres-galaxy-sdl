//
//  Music.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 21.02.24.
//

#include "Music.hpp"

Music::Music(const std::string& filepath)
{
    music = Mix_LoadMUS(filepath.c_str());
}

Music::~Music()
{
    Mix_FreeMusic(music);
}

void Music::play() const
{
    Mix_PlayMusic(music, -1);
}

void Music::halt() const
{
    Mix_HaltMusic();
}
