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
#include "SpriteAtlas.hpp"

class Scene;

class SpriteFactory
{
public:
    static void createShip(Scene* scene, double x, double y);
    static void createShot(Scene* scene, double x, double y);
    static void createEnemyShot(Scene* scene, double x, double y, double targetX, double targetY);
    static void createExplosion(Scene* scene, double x, double y);
    
    static void createSmallBlueAlien(Scene* scene);
    static void createBigBlueAlien(Scene* scene);
    static void createSmallRedAlien(Scene* scene);
    static void createBigRedAlien(Scene* scene);
    
    static void createLabel(Scene* scene, const std::string& text, double x, double y);
    static void createScrollingLabel(Scene* scene, const std::string& text, double x, double y);
};

#endif /* SpriteFactory_hpp */
