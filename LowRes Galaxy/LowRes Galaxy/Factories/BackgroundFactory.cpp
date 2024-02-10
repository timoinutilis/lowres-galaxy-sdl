//
//  BackgroundFactory.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#include "BackgroundFactory.hpp"
#include "../Scene.hpp"
#include "../Components/Position.hpp"
#include "../Components/Sprite.hpp"
#include "../Components/AutoScroll.hpp"

void BackgroundFactory::createLayer1(Scene* scene, double x)
{
    auto& registry = scene->getRegistry();
    const auto entity = registry.create();
    registry.emplace<Position>(entity, x, 0.0, 0.0);
    registry.emplace<Sprite>(entity, scene->bgSpriteAtlas, "background_layer_1");
    registry.emplace<AutoScroll>(entity, 256, 0.125);
}

void BackgroundFactory::createLayer2(Scene* scene, double x)
{
    auto& registry = scene->getRegistry();
    const auto entity = registry.create();
    registry.emplace<Position>(entity, x, 128.0 - 67.0, 1.0);
    registry.emplace<Sprite>(entity, scene->bgSpriteAtlas, "background_layer_2");
    registry.emplace<AutoScroll>(entity, 256, 0.5);
}

void BackgroundFactory::createLayer3(Scene* scene, double x)
{
    auto& registry = scene->getRegistry();
    const auto entity = registry.create();
    registry.emplace<Position>(entity, x, 128.0 - 27.0, 2.0);
    registry.emplace<Sprite>(entity, scene->bgSpriteAtlas, "background_layer_3");
    registry.emplace<AutoScroll>(entity, 256, 1.0);
}
