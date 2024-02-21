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
    void update(Scene& scene) const;
};

#endif /* PlayerMoveSystem_hpp */
