//
// Created by Stef van Stipdonk on 12/12/2023.
//

#include "PauseMenu.hpp"
#include "Helpers/Vector2.hpp"
#include <ConfigSingleton.hpp>
#include "Components/TransformComponent.hpp"
#include "EngineManagers/ReplayManager.hpp"
#include "EngineManagers/SceneManager.hpp"
#include "SaveLoadGame.hpp"
#include <Objects/Button.hpp>

#include "Components/SpriteComponent.hpp"
#include "Scenes/LevelManager.hpp"
#include "Scripts/PauseHandler.hpp"
#include "Scripts/PlayerProgressScript.hpp"

PauseMenu::PauseMenu() : GameObject() {
    setTag("PauseMenu");
    setName("PauseMenu");
    setActive(false);

    // Add bg image
    auto bgImageSprite = std::make_unique<SpriteComponent>();
    bgImageSprite->spritePath = "Sprites/beer_background.png";
    bgImageSprite->spriteSize = std::make_unique<Vector2>(1048, 698);
    bgImageSprite->tileOffset = std::make_unique<Vector2>(0, 0);
    bgImageSprite->sortingLayer = 0;
    bgImageSprite->orderInLayer = 2;
    auto &transformBgImage = this->tryGetComponent<TransformComponent>();
    transformBgImage.position = std::make_unique<Vector2>(0, 0);
    transformBgImage.scale = std::make_unique<Vector2>(1.25, 1.25);
    this->addComponent(std::move(bgImageSprite));

    auto centerY = ConfigSingleton::getInstance().getInitialWindowSize().getY() / 2;
    auto centerX = ConfigSingleton::getInstance().getInitialWindowSize().getX() / 2;
    auto buttonSize = Vector2(210, 70);
    auto offset = -280;
    auto spaceing = 25;

    auto resume = std::make_unique<Button>(buttonSize, "Resume");
    resume->setFontSize(20);
    resume->setTag("ResumeButton");
    resume->setName("ResumeButton");
    resume->setClickEvent([]() {
        auto obj = SceneManager::getInstance().getGameObjectByName("PauseManager");
        auto pauseHandlerPtr = BehaviourScriptStore::getInstance().getBehaviourScripts<PauseHandler>(
                obj.value()->getEntityId())[0];

        pauseHandlerPtr.get().togglePause();
    });

    auto backToMenu = std::make_unique<Button>(buttonSize, "Main Menu");
    backToMenu->setFontSize(20);
    backToMenu->setTag("MainMenuButton");
    backToMenu->setName("MainMenuButton");
    backToMenu->setClickEvent([]() {
        ConfigSingleton::getInstance().deltaTimeMultiplier = 1.0;
        auto playerProgress = SceneManager::getGameObjectByName("PlayerProgress");
        if (playerProgress.has_value()) {
            auto &playerProgressScript = playerProgress.value()->tryGetBehaviourScript<PlayerProgressScript>();
            playerProgressScript.setZombiesKilled(0);
            playerProgressScript.setBeersCollected(0);
        }
        LevelManager::getInstance().goToSpecificLevel(HOME_SCENE);
    });

    auto speed1x = std::make_unique<Button>(buttonSize, "Speed 1x");
    speed1x->setFontSize(20);
    speed1x->setTag("Speed1x");
    speed1x->setName("Speed1x");
    speed1x->setClickEvent([]() {
        auto obj = SceneManager::getInstance().getGameObjectByName("PauseManager");
        auto pauseHandlerPtr = BehaviourScriptStore::getInstance().getBehaviourScripts<PauseHandler>(
                obj.value()->getEntityId())[0];

        pauseHandlerPtr.get().togglePause();
        ConfigSingleton::getInstance().deltaTimeMultiplier = 1.0;
    });

    auto speed2x = std::make_unique<Button>(buttonSize, "Speed 2x");
    speed2x->setFontSize(20);
    speed2x->setTag("Speed2x");
    speed2x->setName("Speed2x");
    speed2x->setClickEvent([]() {
        auto obj = SceneManager::getInstance().getGameObjectByName("PauseManager");
        auto pauseHandlerPtr = BehaviourScriptStore::getInstance().getBehaviourScripts<PauseHandler>(
                obj.value()->getEntityId())[0];

        pauseHandlerPtr.get().togglePause();
        ConfigSingleton::getInstance().deltaTimeMultiplier = 2.0;
    });


    auto replayButton = std::make_unique<Button>(buttonSize, "Replay");
    replayButton->setFontSize(20);
    replayButton->setTag("ReplayButton");
    replayButton->setName("ReplayButton");
    replayButton->setClickEvent([]() {
        auto obj = SceneManager::getInstance().getGameObjectByName("PauseManager");
        auto pauseHandlerPtr = BehaviourScriptStore::getInstance().getBehaviourScripts<PauseHandler>(
                obj.value()->getEntityId())[0];

        pauseHandlerPtr.get().togglePause();
        ReplayManager::getInstance().toggleReplay();
        ConfigSingleton::getInstance().deltaTimeMultiplier = 1.0;
    });


    auto quitButton = std::make_unique<Button>(buttonSize, "Quit game");
    quitButton->setFontSize(20);
    quitButton->setTag("QuitButton");
    quitButton->setName("QuitButton");
    quitButton->setClickEvent([]() {
        ConfigSingleton::getInstance().toggleIsRunning();
    });


    auto saveButton = std::make_unique<Button>(buttonSize, "Save game");
    saveButton->setFontSize(20);
    saveButton->setTag("SaveButton");
    saveButton->setName("SaveButton");
    saveButton->setClickEvent([]() {
        auto obj = SceneManager::getInstance().getGameObjectByName("PauseManager");
        auto pauseHandlerPtr = BehaviourScriptStore::getInstance().getBehaviourScripts<PauseHandler>(
                obj.value()->getEntityId())[0];

        pauseHandlerPtr.get().togglePause();

        SaveLoadGame::getInstance().save();
    });

    auto &transformSave = saveButton->tryGetComponent<TransformComponent>();
    transformSave.position = std::make_unique<Vector2>(centerX - buttonSize.getX() / 2,
                                                       centerY - buttonSize.getY() / 2 + offset);

    offset += buttonSize.getY() + spaceing;

    auto &resumeTransform = resume->tryGetComponent<TransformComponent>();
    resumeTransform.position = std::make_unique<Vector2>(centerX - buttonSize.getX() / 2,
                                                         centerY - buttonSize.getY() / 2 + offset);

    offset += buttonSize.getY() + spaceing;

    auto &backToMenuTransform = backToMenu->tryGetComponent<TransformComponent>();
    backToMenuTransform.position = std::make_unique<Vector2>(centerX - buttonSize.getX() / 2,
                                                             centerY - buttonSize.getY() / 2 + offset);

    offset += buttonSize.getY() + spaceing;

    auto &transformSpeed1x = speed1x->tryGetComponent<TransformComponent>();
    transformSpeed1x.position = std::make_unique<Vector2>(centerX - buttonSize.getX() / 2,
                                                          centerY - buttonSize.getY() / 2 + offset);

    offset += buttonSize.getY() + spaceing;

    auto &transformSpeed2x = speed2x->tryGetComponent<TransformComponent>();
    transformSpeed2x.position = std::make_unique<Vector2>(centerX - buttonSize.getX() / 2,
                                                          centerY - buttonSize.getY() / 2 + offset);

    offset += buttonSize.getY() + spaceing;

    auto &transformReplay = replayButton->tryGetComponent<TransformComponent>();
    transformReplay.position = std::make_unique<Vector2>(centerX - buttonSize.getX() / 2,
                                                         centerY - buttonSize.getY() / 2 + offset);

    offset += buttonSize.getY() + spaceing;

    auto &transformQuit = quitButton->tryGetComponent<TransformComponent>();
    transformQuit.position = std::make_unique<Vector2>(centerX - (buttonSize.getX() / 2),
                                                       centerY - (buttonSize.getY() / 2) + offset);

    addChild(std::move(saveButton));
    addChild(std::move(quitButton));
    addChild(std::move(resume));
    addChild(std::move(speed1x));
    addChild(std::move(backToMenu));
    addChild(std::move(speed2x));
    addChild(std::move(replayButton));
}
