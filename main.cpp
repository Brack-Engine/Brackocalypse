#include <iostream>
#include <Components/AIComponent.hpp>
#include <Components/AnimationComponent.hpp>
#include <Objects/Text.hpp>
#include <Components/CircleCollisionComponent.hpp>
#include <Components/TextComponent.hpp>
#include <Components/BoxCollisionComponent.hpp>
#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"
//#include "../Brack-Engine/src/FPSSingleton.hpp"

int main() {
    Config config = new Config();
    config.windowTitle = "Brackocalypse";
    config.windowSize = Vector2(800, 600);
    config.showFPS = false;

    BrackEngine brackEngine = BrackEngine(std::move(config));
    auto camera = Camera();
    camera.SetBackgroundColor(Color(0, 255, 0, 255));
    auto scene = Scene(std::move(camera));

    std::unique_ptr<Text> gameObject1 = std::make_unique<Text>("test");
    std::unique_ptr<Text> gameObject2 = std::make_unique<Text>("test2");


    std::unique_ptr<VelocityComponent> veloc1 = std::make_unique<VelocityComponent>();
    std::unique_ptr<VelocityComponent> veloc2 = std::make_unique<VelocityComponent>();


    std::unique_ptr<CircleCollisionComponent> comp1 = std::make_unique<CircleCollisionComponent>(5);
    std::unique_ptr<CircleCollisionComponent> comp2 = std::make_unique<CircleCollisionComponent>(5);
    comp1->radius = std::make_unique<Vector2>(10.0f, 10.0f);
    comp2->radius = std::make_unique<Vector2>(10.0f, 10.0f);

//    std::unique_ptr<BoxCollisionComponent> comp1 = std::make_unique<BoxCollisionComponent>(Vector2(5, 5));
    //std::unique_ptr<BoxCollisionComponent> comp2 = std::make_unique<BoxCollisionComponent>(Vector2(5, 5));
//    comp1->size = std::make_unique<Vector2>(5.0f, 5.0f);
    //comp2->size = std::make_unique<Vector2>(5.0f, 5.0f);

    comp1->collisionType = CollisionType::DYNAMIC;
    comp2->collisionType = CollisionType::DYNAMIC;

//    Left -- Right
/*    gameObject1->TryGetComponent<TransformComponent>().position = std::make_unique<Vector2>(50.0f, 50.0f);
    gameObject2->TryGetComponent<TransformComponent>().position = std::make_unique<Vector2>(5.0f, 50.0f);

    veloc1->velocity = Vector2(-10.0f, 0.0f);
    veloc2->velocity = Vector2(10.0f, 0.0f);*/

    //    Up -- Down
    gameObject1->tryGetComponent<TransformComponent>().position = std::make_unique<Vector2>(50.0f, 5.0f);
    gameObject2->tryGetComponent<TransformComponent>().position = std::make_unique<Vector2>(50.0f, 50.0f);

    veloc1->velocity = Vector2(0.0f, 10.0f);
    veloc2->velocity = Vector2(0.0f, -10.0f);

    gameObject1->tryGetComponent<TextComponent>().sortingLayer = 1;
    gameObject2->tryGetComponent<TextComponent>().sortingLayer = 1;


    gameObject1->AddComponent(std::move(comp1));
    gameObject1->AddComponent(std::move(veloc1));

    gameObject2->AddComponent(std::move(comp2));
    gameObject2->AddComponent(std::move(veloc2));


    scene.AddGameObject(std::move(gameObject1));
    scene.AddGameObject(std::move(gameObject2));

    SceneManager::getInstance().setActiveScene(scene);


    brackEngine.Run();
    return 0;
}