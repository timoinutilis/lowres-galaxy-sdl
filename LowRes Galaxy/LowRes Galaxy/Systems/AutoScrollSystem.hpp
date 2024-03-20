//
//  AutoScrollSystem.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#ifndef AutoScrollSystem_hpp
#define AutoScrollSystem_hpp

class Scene;

class AutoScrollSystem final
{
public:
    AutoScrollSystem(Scene& scene) noexcept;
    void update() const;
    
private:
    Scene& scene;
};

#endif /* AutoScrollSystem_hpp */
