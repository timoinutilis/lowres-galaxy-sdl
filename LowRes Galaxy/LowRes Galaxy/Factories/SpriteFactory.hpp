//
//  SpriteFactory.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#ifndef SpriteFactory_hpp
#define SpriteFactory_hpp

#include "entt.hpp"
#include "SpriteAtlas.hpp"

class Scene;

class SpriteFactory
{
public:
    static void createShip(Scene* scene, double x, double y);
    static void createEnemy(Scene* scene, double x, double y);
    static void createShot(Scene* scene, double x, double y);
};

#endif /* SpriteFactory_hpp */
