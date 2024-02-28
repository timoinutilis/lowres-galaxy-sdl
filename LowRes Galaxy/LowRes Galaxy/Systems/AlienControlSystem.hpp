//
//  AlienControlSystem.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 14.02.24.
//

#ifndef AlienControlSystem_hpp
#define AlienControlSystem_hpp

class GameScene;

class AlienControlSystem final
{
public:
    AlienControlSystem(GameScene& scene);
    void update() const;
    
private:
    GameScene& scene;
};

#endif /* AlienControlSystem_hpp */
