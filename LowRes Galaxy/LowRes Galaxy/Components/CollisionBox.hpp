//
//  CollisionBox.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 14.02.24.
//

#ifndef CollisionBox_h
#define CollisionBox_h

#include "Position.hpp"

struct CollisionBox final
{
    double minX = 0.0;
    double minY = 0.0;
    double maxX = 0.0;
    double maxY = 0.0;
    
    static bool checkCollision(const Position& position1, const CollisionBox& box1, const Position& position2, const CollisionBox& box2);
};

#endif /* CollisionBox_h */
