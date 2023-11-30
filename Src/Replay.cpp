//
// Created by Stef van Stipdonk on 30/11/2023.
//

#include "Replay.hpp"
#include "../Scripts/ReplayScript.hpp"

Replay::Replay(size_t layer) : GameObject() {
    addComponent(std::make_unique<ReplayScript>(10000, 50));
    setTag("Replay");
}