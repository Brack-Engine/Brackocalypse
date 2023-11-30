//
// Created by SKIKK on 21/11/2023.
//
#include <Components/BehaviourScript.hpp>
#include <Components/AnimationComponent.hpp>


#ifndef BRACKOCALYPSE_USERINPUT_HPP
#define BRACKOCALYPSE_USERINPUT_HPP

class UserInputMovement : public BehaviourScript {
public:
    UserInputMovement() : BehaviourScript() {}

    ~UserInputMovement() override = default;

    virtual void onStart() override;

    virtual void onUpdate(float deltaTime) override;

    std::unique_ptr<IComponent> clone() const override {
        return std::make_unique<UserInputMovement>(*this);
    }

    void accept(ComponentVisitor &visitor) override {
        visitor.visit(*this);
        onStart();
    }

    UserInputMovement(const UserInputMovement &other) : BehaviourScript(other) {}

private:
    float velocity = 250.0;

};

#endif //BRACKOCALYPSE_USERINPUT_HPP
