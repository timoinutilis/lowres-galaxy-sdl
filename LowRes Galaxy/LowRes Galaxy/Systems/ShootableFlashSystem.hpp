//
//  ShootableFlashSystem.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 06.03.24.
//

#ifndef ShootableFlashSystem_hpp
#define ShootableFlashSystem_hpp

class Scene;

class ShootableFlashSystem final
{
public:
    ShootableFlashSystem(Scene& scene);
    void update() const;
    
private:
    Scene& scene;
};

#endif /* ShootableFlashSystem_hpp */
