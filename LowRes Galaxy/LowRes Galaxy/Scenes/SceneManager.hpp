//
//  SceneManager.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 21.02.24.
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include <memory>
#include <SDL2/SDL.h>

class Scene;

enum class SceneManagerState
{
    inactive,
    fadingIn,
    active,
    fadingOut
};

class SceneManager final
{
private:
    SDL_Renderer* renderer;
    SceneManagerState state = SceneManagerState::inactive;
    int fadeTicks;
    int ticks;
    std::shared_ptr<Scene> currentScene;
    std::shared_ptr<Scene> nextScene;
    void setCurrentScene(std::shared_ptr<Scene> scene);
    
public:
    SceneManager(SDL_Renderer* renderer, int fadeTicks);
    ~SceneManager();
    
    void setNextScene(std::shared_ptr<Scene> scene);
    void update();
    void render();
};

#endif /* SceneManager_hpp */
