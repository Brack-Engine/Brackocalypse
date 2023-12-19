#include "PlayerProgress.hpp"
#include <EngineManagers/SceneManager.hpp>
#include <Components/RectangleComponent.hpp>
#include "../Src/Helpers/RogueLikeSheetMap.hpp"
#include "UserInputMovement.hpp"
#include "../Src/Components/HealthComponent.hpp"
#include "../Src/Scenes/GameOverScene.hpp"
#include "../Src/Scenes/InterludeOneScene.hpp"

void PlayerProgress::onStart() {

}

void PlayerProgress::onUpdate(milliseconds deltaTime) {
    int totalProgress = beersCollected - foodCollected;

    auto &progressBar = getGameObjectByTag("ProgressBar").value().tryGetComponent<RectangleComponent>();
    int progressWidth = 300 / 100 * (totalProgress * 10);
    progressBar.size->setX(progressWidth);

    auto &health = tryGetComponent<HealthComponent>();
    if (totalProgress >= maxForLevel || health.health <= 0) {
        maxForLevel += 10;
        auto scene = new InterludeOneScene();
        scene->build();
        SceneManager::getInstance().goToNewScene(scene);
    }
    if (health.health <= 0) {
        auto scene = new GameOverScene();
        scene->build();
        SceneManager::getInstance().goToNewScene(scene);
    }
}