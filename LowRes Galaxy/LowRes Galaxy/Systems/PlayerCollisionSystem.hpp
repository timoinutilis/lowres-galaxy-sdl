//
//  PlayerCollisionSystem.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 14.02.24.
//

#ifndef PlayerCollisionSystem_hpp
#define PlayerCollisionSystem_hpp

class Scene;
struct PlayerStatus;
struct Position;

class PlayerCollisionSystem final
{
public:
    PlayerCollisionSystem(Scene& scene);
    void update() const;
    
private:
    Scene& scene;
    
    void explode(Scene& scene, PlayerStatus& status, Position& position) const;
};


#endif /* PlayerCollisionSystem_hpp */
