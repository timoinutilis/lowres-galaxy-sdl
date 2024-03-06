//
//  PlayerCollisionSystem.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 06.03.24.
//

#ifndef PlayerCollisionSystem_hpp
#define PlayerCollisionSystem_hpp

class Scene;

class PlayerCollisionSystem final
{
public:
    PlayerCollisionSystem(Scene& scene);
    void update() const;
    
private:
    Scene& scene;
};

#endif /* PlayerCollisionSystem_hpp */
