//
//  AnimationSystem.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 14.02.24.
//

#ifndef AnimationSystem_hpp
#define AnimationSystem_hpp

class Scene;

class AnimationSystem final
{
public:
    AnimationSystem(Scene& scene);
    void update() const;
    
private:
    Scene& scene;
};

#endif /* AnimationSystem_hpp */
