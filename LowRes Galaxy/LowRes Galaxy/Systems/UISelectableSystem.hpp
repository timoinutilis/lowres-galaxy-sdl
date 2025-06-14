//
//  UISelectableSystem.hpp
//  LowRes Galaxy ZERO
//
//  Created by Timo Kloss on 31.03.24.
//

#ifndef UISelectableSystem_hpp
#define UISelectableSystem_hpp

class Scene;

class UISelectableSystem final
{
public:
    UISelectableSystem(Scene& scene) noexcept;
    void update() const;
    
private:
    Scene& scene;
};


#endif /* UISelectableSystem_hpp */
