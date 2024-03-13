//
//  HighscoreManager.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 13.03.24.
//

#ifndef HighscoreManager_hpp
#define HighscoreManager_hpp

#include <string>

class HighscoreManager
{
public:
    HighscoreManager();
    
    bool checkNewScore(const int score);
    int getHighscore() const;
    
private:
    int highscore = 0;
    
    void load();
    void save() const;
    std::string getPath() const;
};

#endif /* HighscoreManager_hpp */
