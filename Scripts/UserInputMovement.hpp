//
// Created by SKIKK on 21/11/2023.
//
#include <Components/BehaviourScript.hpp>


#ifndef BRACKOCALYPSE_USERINPUT_HPP
#define BRACKOCALYPSE_USERINPUT_HPP

class UserInputMovement : public BehaviourScript {
public:
    UserInputMovement() : BehaviourScript() {}

    ~UserInputMovement() override = default;

    virtual void onStart() override;

    virtual void onUpdate(float deltaTime) override;

    std::unique_ptr<BehaviourScript> clone() const override {
        return std::make_unique<UserInputMovement>(*this);
    }


    UserInputMovement(const UserInputMovement &other) : BehaviourScript(other) {}

    int getPriority() const { return priority; }


    int priority;

private:
    float velocity = 0.25;
};

#endif //BRACKOCALYPSE_USERINPUT_HPP
