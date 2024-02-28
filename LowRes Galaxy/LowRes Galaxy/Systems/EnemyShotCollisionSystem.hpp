//
//  EnemyShotCollisionSystem.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 14.02.24.
//

#ifndef PlayerCollisionSystem_hpp
#define PlayerCollisionSystem_hpp

class Scene;
struct PlayerStatus;
struct Position;

class EnemyShotCollisionSystem final
{
public:
    EnemyShotCollisionSystem(Scene& scene);
    void update() const;
    
private:
    Scene& scene;
};


#endif /* PlayerCollisionSystem_hpp */
