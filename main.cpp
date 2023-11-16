#include <iostream>
#include <Components/AIComponent.hpp>
#include <Components/AnimationComponent.hpp>
#include <Objects/Text.hpp>
#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"
//#include "../Brack-Engine/src/FPSSingleton.hpp"
#include "Components/AIComponent.hpp"
#include "Components/AnimationComponent.hpp"
#include "Components/AudioComponent.hpp"
#include "Components/SoundEffectComponent.hpp"
#include "Components/SoundTrackComponent.hpp"

int main() {
    std::unique_ptr<GameObject> object = std::make_unique<GameObject>();
    auto audioPath = "../Assets/Sounds/song.mp3";
    std::unique_ptr<AudioComponent> component5 = std::make_unique<SoundEffectComponent>(audioPath);
    component5->startPlaying = true;
    component5->volume = 0.1;

    object->AddComponent(std::move(component5));

    Config config = new Config();
    config.windowTitle = "Brackocalypse";
    config.windowSize = Vector2(800, 600);
    config.showFPS = true;

    BrackEngine brackEngine = BrackEngine(std::move(config));
    auto camera = Camera();
    camera.SetBackgroundColor(Color(0, 255, 0, 255));
    auto scene = Scene(std::move(camera));

    scene.AddGameObject(std::move(object));
    SceneManager::GetInstance().SetActiveScene(scene);

    brackEngine.Run();
    return 0;
}
