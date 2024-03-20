//
//  ShootableFlashSystem.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 06.03.24.
//

#include "ShootableFlashSystem.hpp"
#include "entt.hpp"
#include "../Scenes/Scene.hpp"
#include "../Components/Shootable.hpp"
#include "../Components/Sprite.hpp"

ShootableFlashSystem::ShootableFlashSystem(Scene& scene) noexcept
    : scene(scene)
{
}

void ShootableFlashSystem::update() const
{
    const auto view = scene.getRegistry().view<Shootable, Sprite>();
    for (auto entity : view)
    {
        auto& shootable = view.get<Shootable>(entity);
        
        if (shootable.flash > 0)
        {
            auto& sprite = view.get<Sprite>(entity);
            sprite.fxColor = SDL_Color {255, 255, 255, 128};
            if (--shootable.flash == 0)
            {
                sprite.fxColor = SDL_Color {0, 0, 0, 0};
            }
        }
    }
}
