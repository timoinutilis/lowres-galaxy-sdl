//
//  SpriteRenderer.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#include "SpriteRenderer.hpp"
#include "SpriteAtlas.hpp"
#include "../Components/Sprite.hpp"
#include "../Components/Position.hpp"

SpriteRenderer::SpriteRenderer(SDL_Renderer* renderer, entt::registry& registry)
    : renderer(renderer)
    , registry(registry)
{
}

void SpriteRenderer::render()
{
    const auto view = registry.view<Sprite, Position>();
    for (auto entity : view) {
        auto sprite = view.get<Sprite>(entity);
        auto position = view.get<Position>(entity);
        sprite.spriteAtlas->drawFrame(renderer, sprite.frame, position.x, position.y);
    }
}
