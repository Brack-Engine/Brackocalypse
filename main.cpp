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
#include "Src/Replay.hpp"

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
    std::unique_ptr<GameObject> replay = std::make_unique<Replay>(0);
    scene.AddGameObject(std::move(replay));

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

    SceneManager::getInstance().setActiveScene(scene);

    brackEngine.Run();
    return 0;
}