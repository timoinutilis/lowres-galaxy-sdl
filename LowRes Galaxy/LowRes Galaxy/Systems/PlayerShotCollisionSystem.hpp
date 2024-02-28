//
//  PlayerShotCollisionSystem.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 14.02.24.
//

#ifndef ShotCollisionSystem_hpp
#define ShotCollisionSystem_hpp

class Scene;

class PlayerShotCollisionSystem final
{
public:
    PlayerShotCollisionSystem(Scene& scene);
    void update() const;
    
private:
    Scene& scene;
};

#endif /* ShotCollisionSystem_hpp */
