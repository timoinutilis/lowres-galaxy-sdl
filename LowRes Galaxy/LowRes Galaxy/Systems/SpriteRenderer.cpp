//
//  SpriteRenderer.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#include "SpriteRenderer.hpp"
#include <SDL2/SDL.h>
#include "entt.hpp"
#include "../Scenes/Scene.hpp"
#include "../Rendering/SpriteAtlas.hpp"
#include "../Components/Sprite.hpp"
#include "../Components/Position.hpp"

SpriteRenderer::SpriteRenderer(Scene& scene) noexcept
    : scene(scene)
{
}

void SpriteRenderer::render() const
{
    scene.getRegistry().sort<Position>([](const auto& lhs, const auto& rhs) { return lhs.layer < rhs.layer; });
    auto view = scene.getRegistry().view<Position, Sprite>();
    view.use<Position>();
    SDL_Renderer *renderer = scene.getRenderer();
    for (auto entity : view)
    {
        const auto& sprite = view.get<Sprite>(entity);
        if (!sprite.isHidden)
        {
            auto position = view.get<Position>(entity);
            sprite.spriteAtlas->drawFrame(renderer, sprite.frame, position.x, position.y, sprite.fxColor);
        }
    }
}
