//
//  UISelectableSystem.cpp
//  LowRes Galaxy ZERO
//
//  Created by Timo Kloss on 31.03.24.
//

#include "UISelectableSystem.hpp"
#include "entt.hpp"
#include "../Scenes/Scene.hpp"
#include "../Components/UISelectable.hpp"

UISelectableSystem::UISelectableSystem(Scene& scene) noexcept
    : scene(scene)
{
}

void UISelectableSystem::update() const
{
    const auto view = scene.getRegistry().view<UISelectable>();
    for (auto entity : view)
    {
        auto& selectable = view.get<UISelectable>(entity);
    }
}
