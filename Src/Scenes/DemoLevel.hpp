#ifndef BRACKOCALYPSE_DEMOLEVEL_HPP
#define BRACKOCALYPSE_DEMOLEVEL_HPP

#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"

class DemoLevel : public Scene {
public:
    DemoLevel();
    void build() override;
};


#endif //BRACKOCALYPSE_DEMOLEVEL_HPP
