//
//  GameScene.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 21.02.24.
//

#include "GameScene.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "../Factories/BackgroundFactory.hpp"
#include "../Factories/SpriteFactory.hpp"
#include "../Factories/UIFactory.hpp"
#include "../Components/PlayerStatus.hpp"
#include "../Components/Label.hpp"
#include "../Components/Sprite.hpp"
#include "TitleScene.hpp"
#include "Config.hpp"

GameScene::GameScene(SDL_Renderer* renderer, SceneManager& sceneManager, InputManager& inputManager)
    : Scene(renderer, sceneManager, inputManager)
    , levelSystem(*this)
    , playerControlSystem(*this)
    , localPlayerSystem(*this)
    , autoScrollSystem(*this)
    , moveSystem(*this)
    , alienControlSystem(*this)
    , shotCollisionSystem(*this)
    , playerCollisionSystem(*this)
    , animationSystem(*this)
    , spawnSystem(*this)
{
}

GameScene::~GameScene()
{
}

entt::entity GameScene::getPlayerEntity()
{
    const auto view = registry.view<PlayerStatus>();
    return view.front();
}

bool GameScene::isPeace() const
{
    return levelSystem.isPeace();
}

void GameScene::load()
{
    playerControlSystem.connectEvents();
    levelSystem.connectEvents();
    
    dispatcher.sink<ScoreChangedEvent>().connect<&GameScene::onScoreChanged>(*this);
    dispatcher.sink<LivesChangedEvent>().connect<&GameScene::onLivesChanged>(*this);
    dispatcher.sink<LevelChangedEvent>().connect<&GameScene::onLevelChanged>(*this);
    
    getMusicCache().load(MusicIdGame, "Audio/game.ogg");
    getFontCache().load(FontIdDefault, getRenderer(), "Textures/font");
    getSpriteAtlasCache().load(SpriteAtlasIdSprites, getRenderer(), "Textures/sprites");
    getSpriteAtlasCache().load(SpriteAtlasIdBackground, getRenderer(), "Textures/background");
    
    BackgroundFactory::createLayer1(*this, 0.0);
    BackgroundFactory::createLayer1(*this, 256.0);
    BackgroundFactory::createLayer2(*this, 0.0);
    BackgroundFactory::createLayer2(*this, 256.0);
    BackgroundFactory::createLayer3(*this, 0.0);
    BackgroundFactory::createLayer3(*this, 256.0);
    
    SpriteFactory::createShip(*this, 32.0, 48.0);
    
    scoreLabelEntity = UIFactory::createLabel(*this, "00000", Config::screenWidth - 40.0, 0.0);
    
    for (int i = 0; i < Config::lives; ++i)
    {
        liveIconEntities.push_back(UIFactory::createImage(*this, SpriteAtlasIdSprites, "ship_icon", i * 8.0, 0.0));
    }
}

void GameScene::unload()
{
    playerControlSystem.disconnectEvents();
    levelSystem.disconnectEvents();
    
    dispatcher.sink<ScoreChangedEvent>().disconnect(this);
    dispatcher.sink<LivesChangedEvent>().disconnect(this);
    dispatcher.sink<LevelChangedEvent>().disconnect(this);
}

void GameScene::onAppear()
{
    inputManager.getActionSink().connect<&GameScene::onInputAction>(this);
    getMusicCache()[MusicIdGame]->play();
}

void GameScene::onDisappear()
{
    inputManager.getActionSink().disconnect(this);
    getMusicCache()[MusicIdGame]->halt();
}

void GameScene::update()
{
    // systems
    levelSystem.update();
    autoScrollSystem.update();
    localPlayerSystem.update();
    playerControlSystem.update();
    moveSystem.update();
    alienControlSystem.update();
    shotCollisionSystem.update();
    playerCollisionSystem.update();
    spawnSystem.update();
    animationSystem.update();
    
    dispatcher.update();
}

void GameScene::onInputAction(const InputAction action)
{
    switch (state)
    {
        case GameSceneState::playing:
            break;
        case GameSceneState::gameOver:
            if (action == InputAction::fire)
            {
                sceneManager.setNextScene(std::make_unique<TitleScene>(getRenderer(), sceneManager, inputManager));
            }
            break;
    }
}

void GameScene::onScoreChanged(const ScoreChangedEvent& event)
{
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(5) << std::to_string(event.score);
    
    auto& label = registry.get<Label>(scoreLabelEntity);
    label.text = oss.str();
}

void GameScene::onLivesChanged(const LivesChangedEvent& event)
{
    for (int i = 0; i < liveIconEntities.size(); ++i)
    {
        registry.get<Sprite>(liveIconEntities[i]).isHidden = i >= event.lives;
    }
    if (event.lives == 0)
    {
        // game over
        state = GameSceneState::gameOver;
        UIFactory::createImage(*this, SpriteAtlasIdSprites, "game_over", (Config::screenWidth - 134.0) * 0.5, 16.0);
    }
}

void GameScene::onLevelChanged(const LevelChangedEvent& event)
{
    std::cout << "level " << event.level << "\n";
}

