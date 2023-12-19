#include "HomeScene.hpp"
#include <Components/AIComponent.hpp>
#include <Objects/Button.hpp>
#include <Components/SpriteComponent.hpp>
#include <Components/SoundTrackComponent.hpp>
#include "BrackEngine.hpp"
#include "../../Brack-Engine/src/ConfigSingleton.hpp"
#include "../Helpers/RogueLikeSheetMap.hpp"
#include "../Player.hpp"
#include "DemoLevel.hpp"
#include "../../Scripts/ToggleFPS.hpp"

HomeScene::HomeScene() : Scene() {
    auto obj = SceneManager::getInstance().getGameObjectByName("FPS");
    if (obj.has_value()) {
        obj.value()->addBehaviourScript(std::make_unique<ToggleFPS>());
    }
    auto &camera = getCameras()[0];
    camera->addComponent(VelocityComponent());
    camera->SetBackgroundColor(Color(0, 255, 0, 255));
    auto backgroundSound = std::make_unique<SoundTrackComponent>("Sounds/atje.mp3");
    backgroundSound->volume = 0.02;
    backgroundSound->startPlaying = true;
    camera->addComponent(std::move(backgroundSound));
    auto windowSize = ConfigSingleton::getInstance().getWindowSize();

    auto bgImage = std::make_unique<GameObject>();
    auto bgImageSprite = std::make_unique<SpriteComponent>();
    bgImageSprite->spritePath = "Sprites/background_homescreen.png";
    bgImageSprite->spriteSize = std::make_unique<Vector2>(1264, 717);
    bgImageSprite->tileOffset = std::make_unique<Vector2>(0, 0);
    bgImageSprite->orderInLayer = 1;
    auto &transformBgImage = bgImage->tryGetComponent<TransformComponent>();
    transformBgImage.position = std::make_unique<Vector2>(0, 0);
    transformBgImage.scale = std::make_unique<Vector2>(1, 1);
    bgImage->addComponent(std::move(bgImageSprite));
    addGameObject(std::move(bgImage));


    auto logo = std::make_unique<GameObject>();

    auto spriteBg = std::make_unique<SpriteComponent>();
    spriteBg->spritePath = "Sprites/logo.png";
    spriteBg->spriteSize = std::make_unique<Vector2>(736, 105);
    spriteBg->tileOffset = std::make_unique<Vector2>(0, 0);
    spriteBg->orderInLayer = 0;

    auto transformBg = std::make_unique<TransformComponent>();
    transformBg->position = std::make_unique<Vector2>(0, -100);
    transformBg->scale = std::make_unique<Vector2>(0.6, 0.6);
    logo->addComponent(std::move(spriteBg));
    logo->addComponent(std::move(transformBg));
    addGameObject(std::move(logo));

    //Start button
    auto startButton = std::make_unique<Button>(Vector2(210, 70), "Start game");
    startButton->setFontSize(40);
    startButton->setClickEvent([]() {
        auto scene = new DemoLevel();
        SceneManager::getInstance().goToNewScene(scene);
    });

    auto centerY = ConfigSingleton::getInstance().getWindowSize().getY() / 2;
    auto centerX = ConfigSingleton::getInstance().getWindowSize().getX() / 2;

    auto &transformStartButton = startButton->tryGetComponent<TransformComponent>();
    transformStartButton.position = std::make_unique<Vector2>(-150 + centerX - 105, centerY + 50);
    addGameObject(std::move(startButton));

    //Quit button
    auto quitButton = std::make_unique<Button>(Vector2(210, 70), "Quit");
    quitButton->setFontSize(40);
    quitButton->setClickEvent([]() {
        ConfigSingleton::getInstance().toggleIsRunning();
    });

    auto &transformQuitButton = quitButton->tryGetComponent<TransformComponent>();
    transformQuitButton.position = std::make_unique<Vector2>(150 + centerX - 105, centerY + 50);
    addGameObject(std::move(quitButton));
}