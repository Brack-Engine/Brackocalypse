#include <iostream>
#include <Components/AIComponent.hpp>
#include <Components/AnimationComponent.hpp>
#include <Objects/Text.hpp>
#include <Components/AIComponent.hpp>
#include <Components/AnimationComponent.hpp>
#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"
//#include "../Brack-Engine/src/FPSSingleton.hpp"
#include "../Brack-Engine/src/ConfigSingleton.hpp"
#include "Components/AudioComponent.hpp"

int main() {
    Config config = new Config();
    config.windowTitle = "Brackocalypse";
    config.windowSize = Vector2(800, 600);
    config.fpsLimit = 60;

    BrackEngine brackEngine = BrackEngine(std::move(config));
    auto camera = Camera();
    auto transformCam = camera.TryGetComponent<TransformComponent>();
    transformCam.rotation = 90;
    camera.SetBackgroundColor(Color(0, 255, 0, 255));
    auto scene = Scene(std::move(camera));

    //Sprite
    auto object = std::make_unique<GameObject>();
    auto sprite = std::make_unique<SpriteComponent>();
    auto transform = std::make_unique<TransformComponent>();
    sprite->spritePath =
            ConfigSingleton::GetInstance().GetBaseAssetPath() + "Sprites/roguelikeSheet_transparent_1.bmp";
    sprite->spriteSize = std::make_unique<Vector2>(16, 16);
    sprite->tileOffset = std::make_unique<Vector2>(6, 0);
    sprite->margin = 1;

    transform->position = std::make_unique<Vector2>(100, 100);
    transform->scale = std::make_unique<Vector2>(6, 6);

    object->AddComponent(std::move(sprite));
    object->AddComponent(std::move(transform));
    scene.AddGameObject(std::move(object));

    SceneManager::GetInstance().SetActiveScene(scene);

    brackEngine.Run();
    return 0;
}