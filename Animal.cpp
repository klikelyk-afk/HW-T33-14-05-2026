#include "Animal.h"
#include "ZooException.h"


Animal::Animal(string n, bool predator) : isPredator(predator) {
    if (n.empty()) throw NameException();
    name = n;
}

void Animal::showDescription() const {
    std::cout << "Name: " << name << (isPredator ? " [Predator]" : " [Herbivore]");
}


Fish::Fish(string n, bool predator, bool deep) : Animal(n, predator), isDeepWater(deep) {}
void Fish::showDescription() const {
    Animal::showDescription();
    std::cout << " | Type: Fish | Deepwater: " << (isDeepWater ? "Yes" : "No");
}


Bird::Bird(string n, bool predator, double speed) : Animal(n, predator), flySpeed(speed) {}
void Bird::showDescription() const {
    Animal::showDescription();
    std::cout << " | Type: Bird | Flight Speed: " << flySpeed << " km/h";
}


Mammal::Mammal(string n, bool predator, string hab) : Animal(n, predator), habitat(hab) {}
void Mammal::showDescription() const {
    Animal::showDescription();
    std::cout << " | Type: Mammal | Habitat: " << habitat;
}