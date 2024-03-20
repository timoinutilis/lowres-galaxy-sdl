//
//  LocalPlayerSystem.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#ifndef LocalPlayerSystem_hpp
#define LocalPlayerSystem_hpp

class Scene;

class LocalPlayerSystem final
{
public:
    LocalPlayerSystem(Scene& scene) noexcept;
    void update() const;
    
private:
    Scene& scene;
};

#endif /* LocalPlayerSystem_hpp */
