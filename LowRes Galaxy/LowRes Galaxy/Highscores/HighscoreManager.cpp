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
    std::ifstream file;
    file.open(path);
    file >> highscore;
}

void HighscoreManager::save() const
{
    auto path = getPath();
    std::ofstream file;
    file.open(path);
    file << highscore;
}

std::string HighscoreManager::getPath() const
{
    char* prefPath = SDL_GetPrefPath("Inutilis Software", "LowRes Galaxy ZERO");
    
    std::ostringstream oss;
    oss << prefPath << "highscore";
    
    SDL_free(prefPath);
    return oss.str();
}
