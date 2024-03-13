//
//  AudioClip.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 13.03.24.
//

#include "AudioClip.hpp"

AudioClip::AudioClip(const std::string& filepath)
{
    chunk = Mix_LoadWAV(filepath.c_str());
}

AudioClip::~AudioClip()
{
    Mix_FreeChunk(chunk);
}

void AudioClip::play() const
{
    Mix_PlayChannel(-1, chunk, 0);
}
