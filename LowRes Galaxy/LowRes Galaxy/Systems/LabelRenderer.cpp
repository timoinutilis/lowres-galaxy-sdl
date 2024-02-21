//
//  LabelRenderer.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 16.02.24.
//

#include "LabelRenderer.hpp"
#include <SDL2/SDL.h>
#include "entt.hpp"
#include "../Scenes/Scene.hpp"
#include "../Rendering/Font.hpp"
#include "../Components/Label.hpp"
#include "../Components/Position.hpp"

void LabelRenderer::render(Scene& scene)
{
    const auto view = scene.getRegistry().view<Label, Position>();
    SDL_Renderer *renderer = scene.getRenderer();
    for (auto entity : view)
    {
        auto label = view.get<Label>(entity);
        if (!label.isHidden)
        {
            auto position = view.get<Position>(entity);
            label.font->drawString(renderer, label.text, position.x, position.y);
        }
    }
}
