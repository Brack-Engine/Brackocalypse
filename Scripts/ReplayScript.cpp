//
// Created by Stef van Stipdonk on 30/11/2023.
//

#include "ReplayScript.hpp"
#include "../../Brack-Engine/src/includes/SystemManager.hpp"
#include "../../Brack-Engine/src/Systems/ReplaySystem.hpp"
#include "Helpers/KeyMap.hpp"

ReplayScript::ReplayScript(milliseconds replayStorageDuration, milliseconds snapshotIntervalDuration)
        : BehaviourScript() {
    SystemManager::GetInstance().GetSystem<ReplaySystem>().lock()->startRecording(replayStorageDuration,
                                                                                  snapshotIntervalDuration);
}

void ReplayScript::onStart() {}

void ReplayScript::onUpdate(milliseconds deltaTime) {
    if (InputManager::GetInstance().IsKeyPressed(KeyMap::ESCAPE))
        SystemManager::GetInstance().GetSystem<ReplaySystem>().lock()->toggleReplay();
}