//
//  InputManager.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 01.03.24.
//

#include "InputManager.hpp"
#include <iostream>

InputManager::InputManager()
    : actionStatuses(6)
    , actionSink(actionSignal)
{
}

InputManager::~InputManager()
{
    if (gameController != nullptr)
    {
        SDL_GameControllerClose(gameController);
    }
}

void InputManager::handleSDLEvent(const SDL_Event& event)
{
    switch (event.type)
    {
        case SDL_KEYDOWN:
        {
            if (event.key.repeat)
            {
                break;
            }
            
            SDL_Keycode keycode = event.key.keysym.sym;
            SDL_Scancode scancode = event.key.keysym.scancode;
            
            if (scancode == SDL_SCANCODE_UP)
            {
                actionSignal.publish(InputAction::up);
                actionStatuses[static_cast<int>(InputAction::up)] = true;
            }
            else if (scancode == SDL_SCANCODE_DOWN)
            {
                actionSignal.publish(InputAction::down);
                actionStatuses[static_cast<int>(InputAction::down)] = true;
            }
            else if (scancode == SDL_SCANCODE_LEFT)
            {
                actionSignal.publish(InputAction::left);
                actionStatuses[static_cast<int>(InputAction::left)] = true;
            }
            else if (scancode == SDL_SCANCODE_RIGHT)
            {
                actionSignal.publish(InputAction::right);
                actionStatuses[static_cast<int>(InputAction::right)] = true;
            }
            else if (scancode == SDL_SCANCODE_SPACE)
            {
                actionSignal.publish(InputAction::fire);
                actionStatuses[static_cast<int>(InputAction::fire)] = true;
            }
            else if (scancode == SDL_SCANCODE_ESCAPE)
            {
                actionSignal.publish(InputAction::back);
                actionStatuses[static_cast<int>(InputAction::back)] = true;
            }
            else if (keycode == SDLK_p)
            {
                actionSignal.publish(InputAction::pause);
                actionStatuses[static_cast<int>(InputAction::pause)] = true;
            }
            break;
        }
            
        case SDL_KEYUP:
        {
            SDL_Keycode keycode = event.key.keysym.sym;
            SDL_Scancode scancode = event.key.keysym.scancode;
            
            if (scancode == SDL_SCANCODE_UP)
            {
                actionStatuses[static_cast<int>(InputAction::up)] = false;
            }
            else if (scancode == SDL_SCANCODE_DOWN)
            {
                actionStatuses[static_cast<int>(InputAction::down)] = false;
            }
            else if (scancode == SDL_SCANCODE_LEFT)
            {
                actionStatuses[static_cast<int>(InputAction::left)] = false;
            }
            else if (scancode == SDL_SCANCODE_RIGHT)
            {
                actionStatuses[static_cast<int>(InputAction::right)] = false;
            }
            else if (scancode == SDL_SCANCODE_SPACE)
            {
                actionStatuses[static_cast<int>(InputAction::fire)] = false;
            }
            else if (scancode == SDL_SCANCODE_ESCAPE)
            {
                actionStatuses[static_cast<int>(InputAction::back)] = false;
            }
            else if (keycode == SDLK_p)
            {
                actionStatuses[static_cast<int>(InputAction::pause)] = false;
            }
            break;
        }
        
        case SDL_CONTROLLERDEVICEADDED:
        {
            if (gameController == nullptr && event.cdevice.which == 0)
            {
                gameController = SDL_GameControllerOpen(0);
            }
            break;
        }
        
        case SDL_CONTROLLERDEVICEREMOVED:
        {
            if (gameController != nullptr) //TODO: check if it's the connected gameController
            {
                SDL_GameControllerClose(gameController);
                gameController = nullptr;
            }
            break;
        }
        
        case SDL_CONTROLLERBUTTONDOWN:
        {
            switch (event.cbutton.button)
            {
                case SDL_CONTROLLER_BUTTON_A:
                {
                    actionSignal.publish(InputAction::fire);
                    actionStatuses[static_cast<int>(InputAction::fire)] = true;
                    break;
                }
                case SDL_CONTROLLER_BUTTON_DPAD_UP:
                {
                    actionSignal.publish(InputAction::up);
                    actionStatuses[static_cast<int>(InputAction::up)] = true;
                    break;
                }
                case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
                {
                    actionSignal.publish(InputAction::down);
                    actionStatuses[static_cast<int>(InputAction::down)] = true;
                    break;
                }
                case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
                {
                    actionSignal.publish(InputAction::left);
                    actionStatuses[static_cast<int>(InputAction::left)] = true;
                    break;
                }
                case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
                {
                    actionSignal.publish(InputAction::right);
                    actionStatuses[static_cast<int>(InputAction::right)] = true;
                    break;
                }
                case SDL_CONTROLLER_BUTTON_START:
                {
                    actionSignal.publish(InputAction::pause);
                    actionStatuses[static_cast<int>(InputAction::pause)] = true;
                    break;
                }
            }
            break;
        }
        
        case SDL_CONTROLLERBUTTONUP:
        {
            switch (event.cbutton.button)
            {
                case SDL_CONTROLLER_BUTTON_A:
                {
                    actionStatuses[static_cast<int>(InputAction::fire)] = false;
                    break;
                }
                case SDL_CONTROLLER_BUTTON_DPAD_UP:
                {
                    actionStatuses[static_cast<int>(InputAction::up)] = false;
                    break;
                }
                case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
                {
                    actionStatuses[static_cast<int>(InputAction::down)] = false;
                    break;
                }
                case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
                {
                    actionStatuses[static_cast<int>(InputAction::left)] = false;
                    break;
                }
                case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
                {
                    actionStatuses[static_cast<int>(InputAction::right)] = false;
                    break;
                }
                case SDL_CONTROLLER_BUTTON_START:
                {
                    actionStatuses[static_cast<int>(InputAction::pause)] = false;
                    break;
                }
            }
            break;
        }
    }
}

entt::sink<entt::sigh<InputManager::Listener>>& InputManager::getActionSink()
{
    return actionSink;
}

bool InputManager::isPressed(const InputAction action) const
{
    return actionStatuses[static_cast<int>(action)];
}
