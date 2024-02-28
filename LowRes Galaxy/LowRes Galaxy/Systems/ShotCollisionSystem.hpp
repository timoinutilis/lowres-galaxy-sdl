//
//  ShotCollisionSystem.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 14.02.24.
//

#ifndef ShotCollisionSystem_hpp
#define ShotCollisionSystem_hpp

class GameScene;

class ShotCollisionSystem final
{
public:
    ShotCollisionSystem(GameScene& scene);
    void update() const;
    
private:
    GameScene& scene;
};

#endif /* ShotCollisionSystem_hpp */
