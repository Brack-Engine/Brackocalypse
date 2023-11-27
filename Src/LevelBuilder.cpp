//
// Created by SKIKK on 17/11/2023.
//

#include <Components/SpriteComponent.hpp>
#include "LevelBuilder.hpp"

void LevelBuilder::buildLevel() {
    size_t sortingLayer = map.size();
    for (const auto& layer: map) {
        int y = 0;
        for (const std::string& row : layer) {
            int x = 0;
            for (char c : row) {
                if(c == '.') continue;
                std::unique_ptr<GameObject> object = levelFactory_.createGameObject(c,Vector2(x,y), sortingLayer);
                if(c == 'J') {
                    object->setRotation(30);
                }
                gameObjects.push_back(std::move(object));
                x++;
            }
            y++;
        }
        sortingLayer--;
    }
}