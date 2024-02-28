//
//  PlayerControlSystem.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#ifndef PlayerMoveSystem_hpp
#define PlayerMoveSystem_hpp

class Scene;

class PlayerControlSystem final
{
public:
    PlayerControlSystem(Scene& scene);
    void update() const;
    
private:
    Scene& scene;
};

#endif /* PlayerMoveSystem_hpp */
