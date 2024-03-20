//
//  TitleScene.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 21.02.24.
//

#ifndef TitleScene_hpp
#define TitleScene_hpp

#include "Scene.hpp"
#include "../Input/InputManager.hpp"
#include "../Systems/AutoScrollSystem.hpp"
#include "../Systems/AutoDestroySystem.hpp"

class TitleScene : public Scene
{
private:
    AutoScrollSystem autoScrollSystem;
    AutoDestroySystem autoDestroySystem;
    int tick = 0;
    void onInputAction(const InputAction action);
    
public:
    TitleScene(IOWrapper& ioWrapper, SceneManager& sceneManager, InputManager& inputManager) noexcept;
    virtual ~TitleScene() override;
    
    virtual void load() override;
    virtual void unload() override;
    
    virtual void onAppear() override;
    virtual void onDisappear() override;
    
    virtual void update() override;
};

#endif /* TitleScene_hpp */
