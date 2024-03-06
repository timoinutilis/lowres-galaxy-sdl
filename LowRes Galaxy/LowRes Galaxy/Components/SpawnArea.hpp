//
//  SpawnArea.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 06.03.24.
//

#ifndef SpawnArea_h
#define SpawnArea_h

#include <functional>

struct SpawnArea final
{
    double x = 0.0;
    double y = 0.0;
    double width = 0.0;
    double height = 0.0;
    
    int count = 1;
    int delay = 0;
    int ticks = 0;
    
    std::function<void(double, double)> spawnFunction;
};


#endif /* SpawnArea_h */
