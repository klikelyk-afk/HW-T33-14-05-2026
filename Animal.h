#pragma once
#include <string>
#include <iostream>

using std::string;

class Animal {
protected:
    string name;
    bool isPredator;
public:
    Animal(string n, bool predator);
    virtual ~Animal() {}

    string getName() const { return name; }
    bool getIsPredator() const { return isPredator; }
    virtual void showDescription() const;
};


class Fish : public Animal {
private:
    bool isDeepWater;
public:
    Fish(string n, bool predator, bool deep);
    bool getIsDeepWater() const { return isDeepWater; }
    void setIsDeepWater(bool deep) { isDeepWater = deep; }
    void showDescription() const override;
};


class Bird : public Animal {
private:
    double flySpeed;
public:
    Bird(string n, bool predator, double speed);
    double getFlySpeed() const { return flySpeed; }
    void setFlySpeed(double speed) { flySpeed = speed; }
    void showDescription() const override;
};


class Mammal : public Animal {
private:
    string habitat;
public:
    Mammal(string n, bool predator, string hab);
    string getHabitat() const { return habitat; }
    void setHabitat(string hab) { habitat = hab; }
    void showDescription() const override;
};