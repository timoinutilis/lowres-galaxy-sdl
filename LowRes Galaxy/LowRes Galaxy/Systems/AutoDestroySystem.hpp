//
//  AutoDestroySystem.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 06.03.24.
//

#ifndef AutoDestroySystem_hpp
#define AutoDestroySystem_hpp


class Scene;

class AutoDestroySystem final
{
public:
    AutoDestroySystem(Scene& scene) noexcept;
    void update() const;
    
private:
    Scene& scene;
};

#endif /* AutoDestroySystem_hpp */
