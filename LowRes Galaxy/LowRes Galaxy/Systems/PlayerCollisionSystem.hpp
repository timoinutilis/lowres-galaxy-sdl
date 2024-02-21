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

class PlayerCollisionSystem
{
private:
    void explode(Scene& scene, PlayerStatus& status, Position& position);
    
public:
    void update(Scene& scene);
};


#endif /* PlayerCollisionSystem_hpp */
