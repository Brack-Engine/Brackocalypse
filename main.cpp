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

int main() {
    Config config = new Config();
    config.windowTitle = "Brackocalypse";
    config.windowSize = Vector2(800, 600);

    BrackEngine brackEngine = BrackEngine(std::move(config));
    auto camera = Camera();

    camera.SetBackgroundColor(Color(0, 255, 0, 255));
    auto scene = Scene(std::move(camera));

    GameObject object = GameObject();
    SpriteComponent *sprite = new SpriteComponent();

    object.AddComponent(sprite);


    Text text = Text("Poepjes", 40);

    scene.AddGameObject(object);
    scene.AddGameObject(text);

    SceneManager::GetInstance().SetActiveScene(scene);

    AIComponent component = AIComponent();
    AnimationComponent component2 = AnimationComponent();

    AudioComponent component5 = AudioComponent();
    component5.audioPath = "../Assets/Sounds/sound.mp3";
    component5.isPlaying = false;
    component5.volume = 1;
    component5.shouldBePlaying = true;
    component5.isLooping = false;
    component5.channel = 1;
    component5.isSoundTrack = true;

    object.AddComponent(&component2);
    object.AddComponent(&component);
    object.AddComponent(&component5);
    scene.AddGameObject(object);

    SceneManager::GetInstance().SetActiveScene(scene);

    object.RemoveComponent<AnimationComponent>();
    camera.SetCameraComponent(new CameraComponent());
    camera.SetBackgroundColor(Color(255, 0, 0, 255));
    scene = Scene(std::move(camera));
    scene.AddGameObject(object);

    SceneManager::GetInstance().SetActiveScene(scene);

    brackEngine.Run();

    return 0;
}
