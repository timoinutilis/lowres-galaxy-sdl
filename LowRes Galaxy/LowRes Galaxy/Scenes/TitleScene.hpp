//
//  TitleScene.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 21.02.24.
//

#ifndef TitleScene_hpp
#define TitleScene_hpp

#include "Scene.hpp"
#include "../Systems/AutoScrollSystem.hpp"

class TitleScene : public Scene
{
private:
    AutoScrollSystem autoScrollSystem;
    
public:
    TitleScene(SDL_Renderer* renderer, SceneManager& sceneManager);
    virtual ~TitleScene() override;
    
    virtual void load() override;
    virtual void unload() override;
    
    virtual void onAppear() override;
    virtual void onDisappear() override;
    
    virtual void update() override;
};

#endif /* TitleScene_hpp */
