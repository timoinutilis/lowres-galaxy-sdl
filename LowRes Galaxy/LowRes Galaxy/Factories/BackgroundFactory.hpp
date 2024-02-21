//
//  BackgroundFactory.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#ifndef BackgroundFactory_hpp
#define BackgroundFactory_hpp

#include "entt.hpp"

class Scene;

class BackgroundFactory final
{
public:
    static void createLayer1(Scene& scene, double x);
    static void createLayer2(Scene& scene, double x);
    static void createLayer3(Scene& scene, double x);
};

#endif /* BackgroundFactory_hpp */
