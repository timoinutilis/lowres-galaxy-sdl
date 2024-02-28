//
//  MoveSystem.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 10.02.24.
//

#ifndef MoveSystem_hpp
#define MoveSystem_hpp

class Scene;

class MoveSystem final
{
public:
    MoveSystem(Scene& scene);
    void update() const;
    
private:
    Scene& scene;
};

#endif /* MoveSystem_hpp */
