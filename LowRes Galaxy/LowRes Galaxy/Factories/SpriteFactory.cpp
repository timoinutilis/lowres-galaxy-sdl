//
//  SpriteFactory.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#include "SpriteFactory.hpp"
#include <cmath>
#include "../Scenes/Scene.hpp"
#include "../Components/Position.hpp"
#include "../Components/Sprite.hpp"
#include "../Components/PlayerInput.hpp"
#include "../Components/PlayerStatus.hpp"
#include "../Components/LocalPlayer.hpp"
#include "../Components/MoveDirection.hpp"
#include "../Components/AlienStatus.hpp"
#include "../Components/Shootable.hpp"
#include "../Components/Shot.hpp"
#include "../Components/EnemyShot.hpp"
#include "../Components/Animation.hpp"
#include "../Components/CollisionBox.hpp"
#include "../Components/Label.hpp"
#include "../Components/AutoScroll.hpp"

void SpriteFactory::createShip(Scene* scene, double x, double y)
{
    auto& registry = scene->getRegistry();
    const auto entity = registry.create();
    registry.emplace<Position>(entity, x, y, 10);
    registry.emplace<CollisionBox>(entity, 0.0, 3.0, 15.0, 12.0, 0);
    registry.emplace<Sprite>(entity, scene->spriteAtlas, "");
    registry.emplace<Animation>(entity, std::vector<std::string> {"ship-0", "ship-1"}, 8, false, 0, 0);
    registry.emplace<PlayerInput>(entity);
    registry.emplace<PlayerStatus>(entity, 0, 0, 120, 0, 5, 0);
    registry.emplace<LocalPlayer>(entity);
}

void SpriteFactory::createShot(Scene* scene, double x, double y)
{
    auto& registry = scene->getRegistry();
    const auto entity = registry.create();
    registry.emplace<Position>(entity, x, y, 10);
    registry.emplace<CollisionBox>(entity, 0.0, 0.0, 7.0, 3.0, 0);
    registry.emplace<Sprite>(entity, scene->spriteAtlas, "shot");
    registry.emplace<MoveDirection>(entity, 3.0, 0.0);
    registry.emplace<Shot>(entity, 1);
}

void SpriteFactory::createEnemyShot(Scene* scene, double x, double y, double targetX, double targetY)
{
    auto& registry = scene->getRegistry();
    const auto entity = registry.create();
    registry.emplace<Position>(entity, x, y, 10);
    registry.emplace<CollisionBox>(entity, 0.0, 0.0, 3.0, 3.0, 1);
    registry.emplace<Sprite>(entity, scene->spriteAtlas, "shot_enemy");
    registry.emplace<EnemyShot>(entity);
    
    double u = targetX - x;
    double v = targetY - y;
    double w = std::sqrt(u * u + v * v);
    registry.emplace<MoveDirection>(entity, u / w, v / w);
}

void SpriteFactory::createExplosion(Scene* scene, double x, double y)
{
    auto& registry = scene->getRegistry();
    const auto entity = registry.create();
    registry.emplace<Position>(entity, x, y, 11);
    registry.emplace<Sprite>(entity, scene->spriteAtlas, "");
    registry.emplace<Animation>(entity, std::vector<std::string> {"explosion-0", "explosion-1", "explosion-2", "explosion-3"}, 5, true, 0, 0);
}

void SpriteFactory::createSmallBlueAlien(Scene* scene)
{
    auto& registry = scene->getRegistry();
    const auto entity = registry.create();
    double x = 160.0;
    double y = 16.0 + scene->getRandom().getDouble() * 80.0;
    registry.emplace<Position>(entity, x, y, 10);
    registry.emplace<CollisionBox>(entity, 0.0, 0.0, 7.0, 7.0, 1);
    registry.emplace<Sprite>(entity, scene->spriteAtlas, "");
    registry.emplace<Animation>(entity, std::vector<std::string> {"enemy_blue_small-0", "enemy_blue_small-1"}, 12, false, 0, 0);
    registry.emplace<AlienStatus>(entity, 0, y, scene->getRandom().getDouble() * 12.0, 0.5, 0.05);
    registry.emplace<Shootable>(entity, 1, 10);
}

void SpriteFactory::createBigBlueAlien(Scene* scene)
{
    auto& registry = scene->getRegistry();
    const auto entity = registry.create();
    double x = 160.0;
    double y = 16.0 + scene->getRandom().getDouble() * 80.0;
    registry.emplace<Position>(entity, x, y, 10);
    registry.emplace<CollisionBox>(entity, 2.0, 2.0, 13.0, 13.0, 1);
    registry.emplace<Sprite>(entity, scene->spriteAtlas, "");
    registry.emplace<Animation>(entity, std::vector<std::string> {"enemy_blue_big-0", "enemy_blue_big-1"}, 16, false, 0, 0);
    registry.emplace<AlienStatus>(entity, 0, y, scene->getRandom().getDouble() * 32.0, 0.25, 0.016);
    registry.emplace<Shootable>(entity, 4, 400);
}

void SpriteFactory::createSmallRedAlien(Scene* scene)
{
    auto& registry = scene->getRegistry();
    const auto entity = registry.create();
    double x = 160.0;
    double y = 16.0 + scene->getRandom().getDouble() * 80.0;
    registry.emplace<Position>(entity, x, y, 10);
    registry.emplace<CollisionBox>(entity, 0.0, 0.0, 7.0, 7.0, 1);
    registry.emplace<Sprite>(entity, scene->spriteAtlas, "");
    registry.emplace<Animation>(entity, std::vector<std::string> {"enemy_red_small-0", "enemy_red_small-1"}, 12, false, 0, 0);
    registry.emplace<AlienStatus>(entity, 0, y, scene->getRandom().getDouble() * 20.0, 0.35, 0.05);
    registry.emplace<Shootable>(entity, 1, 20);
}

void SpriteFactory::createBigRedAlien(Scene* scene)
{
    auto& registry = scene->getRegistry();
    const auto entity = registry.create();
    double x = 160.0;
    double y = 16.0 + scene->getRandom().getDouble() * 80.0;
    registry.emplace<Position>(entity, x, y, 10);
    registry.emplace<CollisionBox>(entity, 2.0, 2.0, 13.0, 13.0, 1);
    registry.emplace<Sprite>(entity, scene->spriteAtlas, "");
    registry.emplace<Animation>(entity, std::vector<std::string> {"enemy_red_big-0", "enemy_red_big-1"}, 16, false, 0, 0);
    registry.emplace<AlienStatus>(entity, 0, y, scene->getRandom().getDouble() * 40.0, 0.15, 0.016);
    registry.emplace<Shootable>(entity, 8, 600);
}

void SpriteFactory::createLabel(Scene* scene, const std::string& text, double x, double y)
{
    auto& registry = scene->getRegistry();
    const auto entity = registry.create();
    registry.emplace<Position>(entity, x, y, 0);
    registry.emplace<Label>(entity, scene->font, text, false);
}

void SpriteFactory::createScrollingLabel(Scene* scene, const std::string& text, double x, double y)
{
    auto& registry = scene->getRegistry();
    const auto entity = registry.create();
    registry.emplace<Position>(entity, x, y, 0);
    registry.emplace<Label>(entity, scene->font, text, false);
    registry.emplace<AutoScroll>(entity, static_cast<int>(text.length()) * 8, 1.0);
    
}
