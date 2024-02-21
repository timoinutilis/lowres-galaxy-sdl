//
//  LocalPlayerSystem.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#include "LocalPlayerSystem.hpp"
#include "entt.hpp"
#include <SDL2/SDL.h>
#include "../Scenes/Scene.hpp"
#include "../Components/LocalPlayer.hpp"
#include "../Components/PlayerInput.hpp"

void LocalPlayerSystem::update(Scene& scene) const
{
    const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
    
    const auto view = scene.getRegistry().view<LocalPlayer, PlayerInput>();
    for (auto entity : view)
    {
        auto& localPlayer = view.get<LocalPlayer>(entity);
        auto& movement = view.get<PlayerInput>(entity);
        
        if (localPlayer.playerIndex == 0)
        {
            if (keyboardState[SDL_SCANCODE_UP])
            {
                movement.directionY = -1;
            }
            else if (keyboardState[SDL_SCANCODE_DOWN])
            {
                movement.directionY = 1;
            }
            else
            {
                movement.directionY = 0;
            }
            
            if (keyboardState[SDL_SCANCODE_LEFT])
            {
                movement.directionX = -1;
            }
            else if (keyboardState[SDL_SCANCODE_RIGHT])
            {
                movement.directionX = 1;
            }
            else
            {
                movement.directionX = 0;
            }
            
            movement.isShooting = keyboardState[SDL_SCANCODE_SPACE];
        }
    }
}
