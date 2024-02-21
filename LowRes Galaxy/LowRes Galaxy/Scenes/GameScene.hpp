//
//  GameScene.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 21.02.24.
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include "Scene.hpp"
#include "../Systems/PlayerControlSystem.hpp"
#include "../Systems/LocalPlayerSystem.hpp"
#include "../Systems/AutoScrollSystem.hpp"
#include "../Systems/MoveSystem.hpp"
#include "../Systems/AlienControlSystem.hpp"
#include "../Systems/ShotCollisionSystem.hpp"
#include "../Systems/AnimationSystem.hpp"
#include "../Systems/PlayerCollisionSystem.hpp"

class GameScene : public Scene
{
private:
    PlayerControlSystem playerControlSystem;
    LocalPlayerSystem localPlayerSystem;
    AutoScrollSystem autoScrollSystem;
    MoveSystem moveSystem;
    AlienControlSystem alienControlSystem;
    ShotCollisionSystem shotCollisionSystem;
    PlayerCollisionSystem playerCollisionSystem;
    AnimationSystem animationSystem;
    
    int tick = 0;
    int level = 0;
    int peace = 0;
    
public:
    GameScene(SDL_Renderer* renderer, SceneManager& sceneManager);
    virtual ~GameScene() override;
    
    entt::entity getPlayerEntity();
    bool isPeace() const;
    
    virtual void load() override;
    virtual void unload() override;
    
    virtual void onAppear() override;
    virtual void onDisappear() override;
    
    virtual void update() override;

};

#endif /* GameScene_hpp */
