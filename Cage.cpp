#include "Cage.h"
#include <algorithm>
#include "ZooException.h"
#include <iostream>

Cage::Cage(int num, int maxCap) : number(num), maxCapacity(maxCap) {}

Cage::~Cage() {
    std::for_each(animals.begin(), animals.end(), [](Animal* a) {
        delete a;
        });
    animals.clear();
}

int Cage::getNumber() const { return number; }
void Cage::setNumber(int num) { number = num; }
int Cage::getMaxCapacity() const { return maxCapacity; }
void Cage::setMaxCapacity(int maxCap) { maxCapacity = maxCap; }
int Cage::getCurrentCount() const { return (int)animals.size(); }

void Cage::addAnimal(Animal* animal) {
    if (animals.size() >= (size_t)maxCapacity) {
        throw MaxCapacityException();
    }

    if (!animals.empty()) {
        if (animal->getIsPredator() != animals[0]->getIsPredator()) {
            throw PredatorException();
        }
    }
    animals.push_back(animal);
}

bool Cage::delAnimal(const string& name) {
    auto it = std::find_if(animals.begin(), animals.end(), [&name](Animal* a) {
        return a->getName() == name;
        });

    if (it != animals.end()) {
        delete* it;
        animals.erase(it);
        return true;
    }
    return false;
}

Animal* Cage::findAnimal(const string& name) const {
    auto it = std::find_if(animals.begin(), animals.end(), [&name](Animal* a) {
        return a->getName() == name;
        });

    return (it != animals.end()) ? *it : nullptr;
}

void Cage::showAllAnimals() const {
    if (animals.empty()) {
        std::cout << "The cage is empty." << std::endl;
        return;
    }

    std::cout << "Animals in cage #" << number << ":" << std::endl;

    int count = 1;
    std::for_each(animals.begin(), animals.end(), [&count](Animal* a) {
        std::cout << count++ << ". ";
        a->showDescription();
        std::cout << std::endl;
        });
}