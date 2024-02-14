//
//  Position.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 14.02.24.
//

#include "Position.hpp"

bool Position::isNear(const Position& other, double maxDistance)
{
    double dx = x - other.x;
    double dy = y - other.y;
    return (dx * dx + dy * dy) <= maxDistance * maxDistance;
}
