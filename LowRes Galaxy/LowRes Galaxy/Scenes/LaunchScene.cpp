//
//  LaunchScene.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.03.24.
//

#include "LaunchScene.hpp"
#include "../Factories/UIFactory.hpp"
#include "TitleScene.hpp"
#include "Config.hpp"

LaunchScene::LaunchScene(SDL_Renderer* renderer, SceneManager& sceneManager, InputManager& inputManager)
    : Scene(renderer, sceneManager, inputManager)
{
}

LaunchScene::~LaunchScene()
{
}

void LaunchScene::load()
{
    getMusicCache().load(MusicIdTitle, "Audio/music_title.ogg");
    getMusicCache().load(MusicIdGame, "Audio/music_game.ogg");
    getMusicCache().load(MusicIdGameOver, "Audio/music_game_over.ogg");
    
    getAudioClipCache().load(AudioClipLevelUp, "Audio/level_up.aiff");
    getAudioClipCache().load(AudioClipPlayerShot, "Audio/player_shot.aiff");
    getAudioClipCache().load(AudioClipPlayerExplosion, "Audio/player_explosion.aiff");
    getAudioClipCache().load(AudioClipEnemyShot, "Audio/enemy_shot.aiff");
    getAudioClipCache().load(AudioClipEnemyHit, "Audio/enemy_hit.aiff");
    getAudioClipCache().load(AudioClipExplosion, "Audio/explosion.aiff");
    
    getFontCache().load(FontIdDefault, getRenderer(), "Textures/font");
    
    getSpriteAtlasCache().load(SpriteAtlasIdSprites, getRenderer(), "Textures/sprites", true);
    getSpriteAtlasCache().load(SpriteAtlasIdBackground, getRenderer(), "Textures/background", false);
    
    UIFactory::createImage(*this, SpriteAtlasIdSprites, "inutilis", (Config::screenWidth - 68.0) * 0.5, (Config::screenHeight - 22.0) * 0.5);
}

void LaunchScene::unload()
{
}

void LaunchScene::onAppear()
{
}

void LaunchScene::onDisappear()
{
}

void LaunchScene::update()
{
    if (++ticks == 180)
    {
        sceneManager.setNextScene(std::make_unique<TitleScene>(getRenderer(), getSceneManager(), getInputManager()));
    }
}
