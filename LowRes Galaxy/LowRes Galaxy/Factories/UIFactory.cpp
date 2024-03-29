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
#include "../Components/AutoDestroy.hpp"
#include "../Caches/SpriteAtlasCache.hpp"
#include "Config.hpp"

entt::entity UIFactory::createImage(Scene& scene, entt::id_type cacheId, std::string frame, double x, double y)
{
    auto& registry = scene.getRegistry();
    const auto entity = registry.create();
    registry.emplace<Position>(entity, x, y, 11);
    registry.emplace<Sprite>(entity, scene.getSpriteAtlasCache()[cacheId], frame);
    return entity;
}

entt::entity UIFactory::createLabel(Scene& scene, const std::string& text, double x, double y)
{
    auto& registry = scene.getRegistry();
    const auto entity = registry.create();
    registry.emplace<Position>(entity, x, y, 0);
    registry.emplace<Label>(entity, scene.getFontCache()[FontIdDefault], text, false);
    return entity;
}

entt::entity UIFactory::createScrollingLabel(Scene& scene, const std::string& text, double x, double y)
{
    auto& registry = scene.getRegistry();
    const auto entity = registry.create();
    registry.emplace<Position>(entity, x, y, 0);
    registry.emplace<Label>(entity, scene.getFontCache()[FontIdDefault], text, false);
    double textWidth = text.length() * 8.0;
    registry.emplace<AutoScroll>(entity, -textWidth, x, 1.0);
    return entity;
}

entt::entity UIFactory::createMessage(Scene& scene, const std::string& text, bool autoDestroy)
{
    auto& registry = scene.getRegistry();
    const auto entity = registry.create();
    registry.emplace<Position>(entity, (Config::screenWidth - text.length() * 8.0) * 0.5, Config::screenHeight - 24.0, 0);
    registry.emplace<Label>(entity, scene.getFontCache()[FontIdDefault], text, false);
    if (autoDestroy)
    {
        registry.emplace<AutoDestroy>(entity, 120);
    }
    return entity;
}
