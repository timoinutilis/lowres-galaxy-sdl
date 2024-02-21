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
#include "SceneManager.hpp"
#include "../Caches/SpriteAtlasCache.hpp"
#include "../Caches/FontCache.hpp"
#include "../Caches/MusicCache.hpp"
#include "../Utils/Random.hpp"
#include "../Systems/SpriteRenderer.hpp"
#include "../Systems/LabelRenderer.hpp"

class Scene
{
private:
    SDL_Renderer* renderer;
        
    SpriteRenderer spriteRenderer;
    LabelRenderer labelRenderer;
    
protected:
    entt::registry registry;
    SceneManager& sceneManager;
    SpriteAtlasCache spriteAtlasCache;
    FontCache fontCache;
    MusicCache musicCache;
    Random random;
    
public:
    Scene(SDL_Renderer* renderer, SceneManager& sceneManager);
    virtual ~Scene() = default;
    
    SDL_Renderer* getRenderer();
    
    entt::registry& getRegistry();
    SceneManager& getSceneManager();
    SpriteAtlasCache& getSpriteAtlasCache();
    FontCache& getFontCache();
    MusicCache& getMusicCache();
    Random& getRandom();
    
    virtual void load() = 0;
    virtual void unload() = 0;
    
    virtual void onAppear() = 0;
    virtual void onDisappear() = 0;
    
    virtual void update() = 0;
    virtual void render();
};

#endif /* Scene_hpp */
