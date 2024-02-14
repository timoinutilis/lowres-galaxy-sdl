//
//  Animation.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 14.02.24.
//

#ifndef Animation_h
#define Animation_h

#include <string>

struct Animation
{
    std::vector<std::string> frames;
    int frameTicks = 1;
    bool destroyAfterEnd = false;
    int frameIndex = 0;
    int tick = 0;
};

#endif /* Animation_h */
