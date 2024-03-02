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
#include "../Input/InputManager.hpp"

LocalPlayerSystem::LocalPlayerSystem(Scene& scene)
    : scene(scene)
{
}

void LocalPlayerSystem::update() const
{
    auto& inputManager = scene.getInputManager();
    const auto view = scene.getRegistry().view<LocalPlayer, PlayerInput>();
    for (auto entity : view)
    {
        auto& localPlayer = view.get<LocalPlayer>(entity);
        auto& movement = view.get<PlayerInput>(entity);
        
        if (localPlayer.playerIndex == 0)
        {
            if (inputManager.isPressed(InputAction::up))
            {
                movement.directionY = -1;
            }
            else if (inputManager.isPressed(InputAction::down))
            {
                movement.directionY = 1;
            }
            else
            {
                movement.directionY = 0;
            }
            
            if (inputManager.isPressed(InputAction::left))
            {
                movement.directionX = -1;
            }
            else if (inputManager.isPressed(InputAction::right))
            {
                movement.directionX = 1;
            }
            else
            {
                movement.directionX = 0;
            }
            
            movement.isShooting = inputManager.isPressed(InputAction::fire);
        }
    }
}
