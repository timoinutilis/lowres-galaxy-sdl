//
//  PlayerControlSystem.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#ifndef PlayerMoveSystem_hpp
#define PlayerMoveSystem_hpp

class Scene;
struct AddScoreEvent;
struct HitEvent;
struct LevelChangedEvent;

class PlayerControlSystem final
{
public:
    PlayerControlSystem(Scene& scene);
    void connectEvents() const;
    void disconnectEvents() const;
    void update() const;
    
private:
    Scene& scene;
    
    void onAddScore(const AddScoreEvent& event) const;
    void onHit(const HitEvent& event) const;
    void onLevelChanged(const LevelChangedEvent& event) const;
};

#endif /* PlayerMoveSystem_hpp */
