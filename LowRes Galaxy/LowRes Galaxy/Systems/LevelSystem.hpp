//
//  LevelSystem.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 28.02.24.
//

#ifndef LevelSystem_hpp
#define LevelSystem_hpp

#include "../Events/LivesChangedEvent.hpp"

class Scene;

class LevelSystem final
{
public:
    LevelSystem(Scene& scene);
    bool isPeace() const;
    void connectEvents();
    void disconnectEvents();
    void update();
    
private:
    Scene& scene;
    
    int tick = 0;
    int level = 0;
    int peace = 0;
    bool canLevelUp = true;
    
    void onLivesChanged(const LivesChangedEvent& event);
};

#endif /* LevelSystem_hpp */
