//
// Created by Stef van Stipdonk on 30/11/2023.
//

#ifndef BRACKOCALYPSE_REPLAY_HPP
#define BRACKOCALYPSE_REPLAY_HPP

#include <Objects/GameObject.hpp>

class Replay : public GameObject {
public:
    Replay(size_t layer);

    ~Replay() = default;
};


#endif //BRACKOCALYPSE_REPLAY_HPP
