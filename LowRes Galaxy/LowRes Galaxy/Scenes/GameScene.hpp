//
//  GameScene.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 21.02.24.
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include <vector>
#include "Scene.hpp"
#include "entt.hpp"
#include "../Input/InputManager.hpp"
#include "../Systems/LevelSystem.hpp"
#include "../Systems/PlayerControlSystem.hpp"
#include "../Systems/LocalPlayerSystem.hpp"
#include "../Systems/AutoScrollSystem.hpp"
#include "../Systems/MoveSystem.hpp"
#include "../Systems/AlienControlSystem.hpp"
#include "../Systems/PlayerShotCollisionSystem.hpp"
#include "../Systems/AnimationSystem.hpp"
#include "../Systems/EnemyShotCollisionSystem.hpp"
#include "../Events/ScoreChangedEvent.hpp"
#include "../Events/LivesChangedEvent.hpp"
#include "../Events/LevelChangedEvent.hpp"

enum class GameSceneState
{
    playing,
    gameOver
};

class GameScene : public Scene
{
private:
    LevelSystem levelSystem;
    PlayerControlSystem playerControlSystem;
    LocalPlayerSystem localPlayerSystem;
    AutoScrollSystem autoScrollSystem;
    MoveSystem moveSystem;
    AlienControlSystem alienControlSystem;
    PlayerShotCollisionSystem shotCollisionSystem;
    EnemyShotCollisionSystem playerCollisionSystem;
    AnimationSystem animationSystem;
    
    entt::entity scoreLabelEntity;
    std::vector<entt::entity> liveIconEntities;
    
    GameSceneState state = GameSceneState::playing;
    
    void onInputAction(const InputAction action);
    void onScoreChanged(const ScoreChangedEvent& event);
    void onLivesChanged(const LivesChangedEvent& event);
    void onLevelChanged(const LevelChangedEvent& event);
    
public:
    GameScene(SDL_Renderer* renderer, SceneManager& sceneManager, InputManager& inputManager);
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
