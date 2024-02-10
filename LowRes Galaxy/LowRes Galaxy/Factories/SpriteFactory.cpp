//
//  SpriteFactory.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#include "SpriteFactory.hpp"
#include "../Scene.hpp"
#include "../Components/Position.hpp"
#include "../Components/Sprite.hpp"
#include "../Components/PlayerMovement.hpp"
#include "../Components/LocalPlayer.hpp"
#include "../Components/MoveDirection.hpp"

void SpriteFactory::createShip(Scene* scene, double x, double y)
{
    auto& registry = scene->getRegistry();
    const auto entity = registry.create();
    registry.emplace<Position>(entity, x, y, 10.0);
    registry.emplace<Sprite>(entity, scene->spriteAtlas, "ship");
    registry.emplace<PlayerMovement>(entity);
    registry.emplace<LocalPlayer>(entity, 0);
}

void SpriteFactory::createEnemy(Scene* scene, double x, double y)
{
    auto& registry = scene->getRegistry();
    const auto entity = registry.create();
    registry.emplace<Position>(entity, x, y, 10.0);
    registry.emplace<Sprite>(entity, scene->spriteAtlas, "enemy_blue_big-0");
}

void SpriteFactory::createShot(Scene* scene, double x, double y)
{
    auto& registry = scene->getRegistry();
    const auto entity = registry.create();
    registry.emplace<Position>(entity, x, y, 11.0);
    registry.emplace<Sprite>(entity, scene->spriteAtlas, "shot");
    registry.emplace<MoveDirection>(entity, 3.0, 0.0);
}
