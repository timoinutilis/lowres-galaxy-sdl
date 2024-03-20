//
//  HighscoreManager.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 13.03.24.
//

#include "HighscoreManager.hpp"
#include <SDL2/SDL.h>
#include <sstream>
#include <fstream>
#include <stdexcept>

HighscoreManager::HighscoreManager()
{
    load();
}

bool HighscoreManager::checkNewScore(const int score)
{
    if (score > highscore)
    {
        highscore = score;
        save();
        return true;
    }
    return false;
}

int HighscoreManager::getHighscore() const
{
    return highscore;
}

void HighscoreManager::load()
{
    auto path = getPath();
    std::ifstream file(path);
    if (file.is_open())
    {
        file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        file >> highscore;
        file.close();
    }
}

void HighscoreManager::save() const
{
    auto path = getPath();
    std::ofstream file;
    file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    file.open(path);
    file << highscore;
    file.close();
}

std::string HighscoreManager::getPath() const
{
    char* prefPath = SDL_GetPrefPath("Inutilis Software", "LowRes Galaxy ZERO");
    if (prefPath == nullptr)
    {
        throw std::runtime_error("SDL_GetPrefPath failed");
    }
    
    std::ostringstream oss;
    oss << prefPath << "highscore";
    
    SDL_free(prefPath);
    return oss.str();
}
