//
//  AudioClip.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 13.03.24.
//

#include "AudioClip.hpp"
#include <stdexcept>

AudioClip::AudioClip(const std::string& filepath)
{
    chunk = Mix_LoadWAV(filepath.c_str());
    if (chunk == nullptr)
    {
        throw std::runtime_error("Mix_LoadWAV failed for " + filepath);
    }
}

AudioClip::~AudioClip()
{
    Mix_FreeChunk(chunk);
}

void AudioClip::play() const
{
    Mix_PlayChannel(-1, chunk, 0);
}
