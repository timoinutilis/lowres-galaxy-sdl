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
#include "Systems/SpriteRenderer.hpp"
#include "Systems/PlayerMovementSystem.hpp"
#include "Systems/LocalPlayerSystem.hpp"
#include "Systems/AutoScrollSystem.hpp"

class Scene
{
private:
    SDL_Renderer* renderer;
    entt::registry registry;
    
    SpriteRenderer spriteRenderer;
    PlayerMovementSystem playerMoveSystem;
    LocalPlayerSystem localPlayerSystem;
    AutoScrollSystem autoScrollSystem;
    
    SpriteAtlas* spriteAtlas;
    SpriteAtlas* bgSpriteAtlas;
    Mix_Music* music;
    
public:
    Scene(SDL_Renderer* renderer);
    
    void load();
    void unload();
    
    void onAppear();
    void onDisappear();
    
    void update();
    void render();
};

#endif /* Scene_hpp */
