//
//  Scene.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 03.02.24.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>
#include "entt.hpp"
#include "SpriteAtlas.hpp"
#include "Utils/Random.hpp"
#include "Factories/BackgroundFactory.hpp"
#include "Factories/SpriteFactory.hpp"
#include "Systems/SpriteRenderer.hpp"
#include "Systems/PlayerControlSystem.hpp"
#include "Systems/LocalPlayerSystem.hpp"
#include "Systems/AutoScrollSystem.hpp"
#include "Systems/MoveSystem.hpp"
#include "Systems/AlienControlSystem.hpp"
#include "Systems/ShotCollisionSystem.hpp"
#include "Systems/AnimationSystem.hpp"
#include "Systems/PlayerCollisionSystem.hpp"

class Scene
{
private:
    SDL_Renderer* renderer;
    entt::registry registry;
    Random random;
    
    SpriteRenderer spriteRenderer;
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
    //TODO add caching system for assets
    SpriteAtlas* spriteAtlas;
    SpriteAtlas* bgSpriteAtlas;
    Mix_Music* music;
    
    
    Scene(SDL_Renderer* renderer);
    
    SDL_Renderer* getRenderer();
    entt::registry& getRegistry();
    Random& getRandom();
    
    entt::entity getPlayerEntity();
    bool isPeace();
    
    void load();
    void unload();
    
    void onAppear();
    void onDisappear();
    
    void update();
    void render();
};

#endif /* Scene_hpp */
