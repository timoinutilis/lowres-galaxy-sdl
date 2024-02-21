//
//  Random.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 14.02.24.
//

#include "Random.hpp"

Random::Random() : unif(0.0, 1.0)
{
}

double Random::getDouble()
{
    return unif(re);
}

int Random::getInt(const int range)
{
    return unif(re) * range;
}
