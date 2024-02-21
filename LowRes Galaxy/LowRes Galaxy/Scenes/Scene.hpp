//
//  Scene.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 03.02.24.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <SDL2/SDL.h>
#include "entt.hpp"
#include "../Caches/SpriteAtlasCache.hpp"
#include "../Caches/FontCache.hpp"
#include "../Caches/MusicCache.hpp"
#include "../Utils/Random.hpp"
#include "../Systems/SpriteRenderer.hpp"
#include "../Systems/LabelRenderer.hpp"
#include "../Systems/PlayerControlSystem.hpp"
#include "../Systems/LocalPlayerSystem.hpp"
#include "../Systems/AutoScrollSystem.hpp"
#include "../Systems/MoveSystem.hpp"
#include "../Systems/AlienControlSystem.hpp"
#include "../Systems/ShotCollisionSystem.hpp"
#include "../Systems/AnimationSystem.hpp"
#include "../Systems/PlayerCollisionSystem.hpp"

class Scene
{
private:
    SDL_Renderer* renderer;
    
    entt::registry registry;
    SpriteAtlasCache spriteAtlasCache;
    FontCache fontCache;
    MusicCache musicCache;
    Random random;
    
    SpriteRenderer spriteRenderer;
    LabelRenderer labelRenderer;
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
    Scene(SDL_Renderer* renderer);
    
    SDL_Renderer* getRenderer();
    
    entt::registry& getRegistry();
    SpriteAtlasCache& getSpriteAtlasCache();
    FontCache& getFontCache();
    MusicCache& getMusicCache();
    Random& getRandom();
    
    entt::entity getPlayerEntity();
    bool isPeace() const;
    
    void load();
    void unload();
    
    void onAppear();
    void onDisappear();
    
    void update();
    void render();
};

#endif /* Scene_hpp */
