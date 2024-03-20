//
//  Random.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 14.02.24.
//

#ifndef Random_hpp
#define Random_hpp

#include <random>

class Random final
{
private:
    std::uniform_real_distribution<double> unif;
    std::default_random_engine re;
    
public:
    Random() noexcept;
    double getDouble();
    int getInt(const int range);
};

#endif /* Random_hpp */
