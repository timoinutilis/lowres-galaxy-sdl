//
//  UIFactory.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 19.02.24.
//

#include "UIFactory.hpp"
#include "../Scenes/Scene.hpp"
#include "../Components/Position.hpp"
#include "../Components/Sprite.hpp"
#include "../Components/Label.hpp"
#include "../Components/AutoScroll.hpp"
#include "Config.hpp"

void UIFactory::createImage(Scene& scene, entt::id_type cacheId, std::string frame, double x, double y)
{
    auto& registry = scene.getRegistry();
    const auto entity = registry.create();
    registry.emplace<Position>(entity, x, y, 11);
    registry.emplace<Sprite>(entity, scene.getSpriteAtlasCache()[cacheId], frame);
}

void UIFactory::createLabel(Scene& scene, const std::string& text, double x, double y)
{
    auto& registry = scene.getRegistry();
    const auto entity = registry.create();
    registry.emplace<Position>(entity, x, y, 0);
    registry.emplace<Label>(entity, scene.getFontCache()[FontIdDefault], text, false);
}

void UIFactory::createScrollingLabel(Scene& scene, const std::string& text, double x, double y)
{
    auto& registry = scene.getRegistry();
    const auto entity = registry.create();
    registry.emplace<Position>(entity, x, y, 0);
    registry.emplace<Label>(entity, scene.getFontCache()[FontIdDefault], text, false);
    double textWidth = text.length() * 8.0;
    registry.emplace<AutoScroll>(entity, -textWidth, x, 1.0);
    
}
