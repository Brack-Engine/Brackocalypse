#include <Components/TileMapComponent.hpp>
#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"
#include "../Brack-Engine/src/ConfigSingleton.hpp"
#include "Src/Helpers/RogueLikeSheetMap.hpp"
#include "Scripts/UserInputMovement.hpp"
#include "Src/Scenes/HomeScene.hpp"
#include "Scripts/FollowGameObject.hpp"
#include "Src/LevelBuilder.hpp"

int main() {
    auto config = std::make_unique<Config>();
    config->windowTitle = "Brackocalypse";
    config->windowSize = Vector2(640, 640);

    BrackEngine brackEngine = BrackEngine(std::move(config));

    auto scene = HomeScene();
    SceneManager::getInstance().setActiveScene(scene);

    brackEngine.Run();
    return 0;
}