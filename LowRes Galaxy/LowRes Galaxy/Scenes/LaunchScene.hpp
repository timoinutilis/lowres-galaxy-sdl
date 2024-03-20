//
//  LaunchScene.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.03.24.
//

#ifndef LaunchScene_hpp
#define LaunchScene_hpp

#include "Scene.hpp"

class LaunchScene : public Scene
{
public:
    LaunchScene(IOWrapper& ioWrapper, SceneManager& sceneManager, InputManager& inputManager) noexcept;
    virtual ~LaunchScene() override;
    
    virtual void load() override;
    virtual void unload() override;
    
    virtual void onAppear() override;
    virtual void onDisappear() override;
    
    virtual void update() override;

private:
    int ticks;
};


#endif /* LaunchScene_hpp */
