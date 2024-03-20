//
//  EnemyShotCollisionSystem.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 14.02.24.
//

#ifndef EnemyShotCollisionSystem_hpp
#define EnemyShotCollisionSystem_hpp

class Scene;
struct PlayerStatus;
struct Position;

class EnemyShotCollisionSystem final
{
public:
    EnemyShotCollisionSystem(Scene& scene) noexcept;
    void update() const;
    
private:
    Scene& scene;
};


#endif /* EnemyShotCollisionSystem_hpp */
