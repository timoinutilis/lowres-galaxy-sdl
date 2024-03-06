//
//  SpawnSystem.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 06.03.24.
//

#ifndef SpawnSystem_hpp
#define SpawnSystem_hpp

class Scene;

class SpawnSystem final
{
public:
    SpawnSystem(Scene& scene);
    void update() const;
    
private:
    Scene& scene;
};


#endif /* SpawnSystem_hpp */
