//
//  CollisionBox.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 14.02.24.
//

#include "CollisionBox.hpp"

bool CollisionBox::checkCollision(const Position& position1, const CollisionBox& box1, const Position& position2, const CollisionBox& box2)
{
    if (box1.group == box2.group)
    {
        return false;
    }
    
    CollisionBox absBox1 = box1;
    absBox1.minX += position1.x;
    absBox1.minY += position1.y;
    absBox1.maxX += position1.x;
    absBox1.maxY += position1.y;
    
    CollisionBox absBox2 = box2;
    absBox2.minX += position2.x;
    absBox2.minY += position2.y;
    absBox2.maxX += position2.x;
    absBox2.maxY += position2.y;
    
    return absBox1.minX < absBox2.maxX && absBox2.minX < absBox1.maxX && absBox1.minY < absBox2.maxY && absBox2.minY < absBox1.maxY;
}
