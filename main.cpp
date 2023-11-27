#include <Components/AIComponent.hpp>
#include <Components/AnimationComponent.hpp>
#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"
#include "../Brack-Engine/src/ConfigSingleton.hpp"
#include "Src/RogueLikeSheetMap.hpp"
#include "Scripts/UserInputMovement.hpp"
#include "Src/Player.hpp"
#include "Scripts/FollowGameObject.hpp"
#include "Src/LevelBuilder.hpp"

int main() {
    Config config = new Config();
    config.windowTitle = "Brackocalypse";
    config.windowSize = Vector2(640, 640);

    BrackEngine brackEngine = BrackEngine(std::move(config));
    auto camera = Camera();
    camera.addComponent(VelocityComponent());
    camera.SetBackgroundColor(Color(0, 255, 0, 255));
    camera.setTag("mainCamera");
    camera.addComponent(FollowGameObject("Player"));
    auto scene = Scene(std::move(camera));

    std::vector<std::vector<std::string>> map{};
    map.emplace_back();
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWW");
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWW");
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWW");
    map[0].emplace_back("WWWWLQQQQQQQQQQNWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWVYYYYYYYYYYCWWWW");
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWW");
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWW");
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWW");

    map.emplace_back();
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("..........J.........");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");

    auto levelBuilder = LevelBuilder(map);

    levelBuilder.buildLevel();

    for (auto &go: levelBuilder.gameObjects) {
        scene.AddGameObject(std::move(go));
    }

    auto gun = std::make_unique<GameObject>();
    auto gunSprite = std::make_unique<SpriteComponent>();
    auto &gunTransform = gun->tryGetComponent<TransformComponent>();
    gunSprite->spritePath = "Sprites/Guns/Pistol_Shooting.png";
    gunSprite->spriteSize = std::make_unique<Vector2>(80, 48);
    gunSprite->sortingLayer = 1;
    gunSprite->orderInLayer = 0;
    gunTransform.scale = std::make_unique<Vector2>(2, 2);
    gunSprite->tileOffset = std::make_unique<Vector2>(0, 0);
    gun->setTag("Gun");
    gun->setName("Gun");
    gun->addComponent(std::move(gunSprite));

    scene.AddGameObject(std::move(gun));

    SceneManager::getInstance().setActiveScene(scene);

    auto player = SceneManager::getInstance().getGameObjectByTag("Player");
    auto gunObject = SceneManager::getInstance().getGameObjectByTag("Gun");
    player.value().addChild(gunObject.value());
    brackEngine.Run();
    return 0;
}