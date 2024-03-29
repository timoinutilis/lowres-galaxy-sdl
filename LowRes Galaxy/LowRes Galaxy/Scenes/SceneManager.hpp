//
//  SceneManager.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 21.02.24.
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include <memory>

class Scene;
class IOWrapper;

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
    IOWrapper& ioWrapper;
    SceneManagerState state = SceneManagerState::inactive;
    int fadeTicks;
    int ticks;
    std::shared_ptr<Scene> currentScene;
    std::shared_ptr<Scene> nextScene;
    void setCurrentScene(std::shared_ptr<Scene> scene);
    
public:
    SceneManager(IOWrapper& ioWrapper, int fadeTicks) noexcept;
    ~SceneManager();
    
    void setNextScene(std::shared_ptr<Scene> scene);
    void update();
    void render();
};

#endif /* SceneManager_hpp */
