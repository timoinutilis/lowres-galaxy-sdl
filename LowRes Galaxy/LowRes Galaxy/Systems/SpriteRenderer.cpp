//
//  SpriteRenderer.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#include "SpriteRenderer.hpp"
#include <SDL2/SDL.h>
#include "entt.hpp"
#include "../Scene.hpp"
#include "../SpriteAtlas.hpp"
#include "../Components/Sprite.hpp"
#include "../Components/Position.hpp"

void SpriteRenderer::render(Scene* scene)
{
    scene->getRegistry().sort<Position>([](const auto& lhs, const auto& rhs) { return lhs.z < rhs.z; });
    const auto view = scene->getRegistry().view<Position, Sprite>();
    SDL_Renderer *renderer = scene->getRenderer();
    for (auto entity : view) {
        auto sprite = view.get<Sprite>(entity);
        auto position = view.get<Position>(entity);
        sprite.spriteAtlas->drawFrame(renderer, sprite.frame, position.x, position.y);
    }
}
