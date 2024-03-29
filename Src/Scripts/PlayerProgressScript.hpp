//
// Created by stijn on 6-12-2023.
//

#ifndef BRACKOCALYPSE_PLAYERPROGRESSSCRIPT_HPP
#define BRACKOCALYPSE_PLAYERPROGRESSSCRIPT_HPP

#include <BehaviourScripts/BehaviourScript.hpp>

class PlayerProgressScript : public BehaviourScript {
public:
    PlayerProgressScript(int beersNeeded, int numberOfLives) : BehaviourScript() {
        this->beersNeeded = beersNeeded;
        this->numberOfLives = numberOfLives;
        this->currentNumberOfLives = numberOfLives;
        beersCollected = 0;
    }

    ~PlayerProgressScript() override = default;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<PlayerProgressScript>(*this);
    }

    PlayerProgressScript(const PlayerProgressScript &other) : BehaviourScript(other) {
        beersNeeded = other.beersNeeded;
        beersCollected = other.beersCollected;
    }

    virtual void onStart() override;

    virtual void onUpdate(milliseconds deltaTime) override;

    void addBeer();

    void addZombieKill();

    int getBeersCollected() { return beersCollected; }

    void setBeersNeeded(int amount) { beersNeeded = amount; }

    void setNumberOfLives(int amount) { currentNumberOfLives = amount; }

    int getNumberOfLives() { return currentNumberOfLives; }

    int getMaxNumberOfLives() { return numberOfLives; }

    void setBeersCollected(int amount);

    int getZombiesKilled() { return zombiesKilled; }

    void setZombiesKilled(int amount) { zombiesKilled = amount; }

private:
    int beersNeeded = 0;
    int beersCollected = 0;
    int zombiesKilled = 0;
    float newWidth = 0;
    int numberOfLives = 0;
    int currentNumberOfLives = 0;
};


#endif //BRACKOCALYPSE_PLAYERPROGRESSSCRIPT_HPP