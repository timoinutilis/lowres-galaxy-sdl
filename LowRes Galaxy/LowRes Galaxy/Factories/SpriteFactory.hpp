//
//  SpriteFactory.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#ifndef SpriteFactory_hpp
#define SpriteFactory_hpp

#include "entt.hpp"
#include <string>

class Scene;

class SpriteFactory final
{
public:
    static void createShip(Scene& scene, double x, double y);
    static void createShot(Scene& scene, entt::entity attacker, double x, double y);
    static void createEnemyShot(Scene& scene, double x, double y, double targetX, double targetY);
    static void createExplosion(Scene& scene, double x, double y);
    
    static void createExplosionSpawnArea(Scene& scene, double x, double y);
    
    static void createSmallBlueAlien(Scene& scene);
    static void createBigBlueAlien(Scene& scene);
    static void createSmallRedAlien(Scene& scene);
    static void createBigRedAlien(Scene& scene);
};

#endif /* SpriteFactory_hpp */
