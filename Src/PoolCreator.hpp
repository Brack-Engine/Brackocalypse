//
// Created by Olaf van den Berg on 11-12-2023.
//

#ifndef BRACKOCALYPSE_POOLCREATOR_HPP
#define BRACKOCALYPSE_POOLCREATOR_HPP

#include <Objects/GameObject.hpp>

template<typename T>
class PoolCreator : public GameObject {
public:
    template<typename...Args>
    PoolCreator(size_t layer, size_t poolSize, Args &&...args) {
        for (size_t i = 0; i < poolSize; i++) {
            auto enemy = std::make_unique<T>(layer, std::forward<Args>(args)...);
            enemy->setActive(false);
            addChild(std::move(enemy));
        }
    };

    ~PoolCreator() = default;


};


#endif //BRACKOCALYPSE_POOLCREATOR_HPP
