//
// Created by Stef van Stipdonk on 30/11/2023.
//

#ifndef BRACKOCALYPSE_REPLAYSCRIPT_HPP
#define BRACKOCALYPSE_REPLAYSCRIPT_HPP


#include "Components/BehaviourScript.hpp"
#include "Milliseconds.hpp"

class ReplayScript : public BehaviourScript {
public:
    ReplayScript(milliseconds replayStorageDuration, milliseconds snapshotIntervalDuration);

    ~ReplayScript() override = default;

    virtual void onStart() override;

    virtual void onUpdate(milliseconds deltaTime) override;

    std::unique_ptr<IComponent> clone() const override {
        return std::make_unique<ReplayScript>(*this);
    }

    void accept(ComponentVisitor &visitor) override {
        visitor.visit(*this);
        onStart();
    }

    ReplayScript(const ReplayScript &other) : BehaviourScript(other) {}
};


#endif //BRACKOCALYPSE_REPLAYSCRIPT_HPP
