//
// Created by SKIKK on 23/11/2023.
//

#ifndef BRACKOCALYPSE_LEVELFACTORY_HPP
#define BRACKOCALYPSE_LEVELFACTORY_HPP


#include <Objects/GameObject.hpp>
#include <Helpers/Vector2.hpp>
#include "../Helpers/RogueLikeSheetMap.hpp"
#include "../Helpers/MapType.hpp"

class LevelFactory {
public:
    void setSize(Vector2 size);

    std::unique_ptr<GameObject> createGameObject(char c, Vector2 position, size_t layer, MapType mapType);

    Vector2 getSpriteTileOffset(char c, MapType mapType);

private:
    Vector2 size_;
    RogueLikeSheetMap rogueLikeSheetMap = RogueLikeSheetMap();
};


#endif //BRACKOCALYPSE_LEVELFACTORY_HPP
