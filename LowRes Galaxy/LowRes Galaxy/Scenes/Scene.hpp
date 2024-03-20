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
#include "../Input/InputManager.hpp"
#include "../Caches/SpriteAtlasCache.hpp"
#include "../Caches/FontCache.hpp"
#include "../Caches/MusicCache.hpp"
#include "../Caches/AudioClipCache.hpp"
#include "../Utils/Random.hpp"
#include "../Systems/SpriteRenderer.hpp"
#include "../Systems/LabelRenderer.hpp"

class IOWrapper;

class Scene
{
private:
    IOWrapper& ioWrapper;
        
    SpriteRenderer spriteRenderer;
    LabelRenderer labelRenderer;
    
protected:
    entt::registry registry;
    entt::dispatcher dispatcher;
    SceneManager& sceneManager;
    InputManager& inputManager;
    Random random;
    
public:
    Scene(IOWrapper& ioWrapper, SceneManager& sceneManager, InputManager& inputManager) noexcept;
    virtual ~Scene() = default;
    
    SDL_Renderer* getRenderer();
    IOWrapper& getIOWrapper();
    
    entt::registry& getRegistry();
    entt::dispatcher& getDispatcher();
    SceneManager& getSceneManager();
    InputManager& getInputManager();
    SpriteAtlasCache& getSpriteAtlasCache();
    FontCache& getFontCache();
    MusicCache& getMusicCache();
    AudioClipCache& getAudioClipCache();
    Random& getRandom();
    
    virtual void load() = 0;
    virtual void unload() = 0;
    
    virtual void onAppear() = 0;
    virtual void onDisappear() = 0;
    
    virtual void update() = 0;
    virtual void render();
};

#endif /* Scene_hpp */
