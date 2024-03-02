//
//  InputManager.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 01.03.24.
//

#ifndef InputManager_hpp
#define InputManager_hpp

#include <SDL2/SDL.h>
#include "entt.hpp"
#include <vector>

enum class InputAction
{
    up,
    down,
    left,
    right,
    fire,
    pause
};

class InputManager
{
public:
    using Listener = void(const InputAction);
    
    InputManager();
    ~InputManager();
    
    void handleSDLEvent(const SDL_Event& event);
    entt::sink<entt::sigh<Listener>>& getActionSink();
    bool isPressed(const InputAction action) const;
    
private:
    std::vector<bool> actionStatuses;
    entt::sigh<Listener> actionSignal;
    entt::sink<entt::sigh<Listener>> actionSink;
    SDL_GameController* gameController = nullptr;
};

//TODO: replace with ServiceLocator
extern InputManager inputManager;

#endif /* InputManager_hpp */
