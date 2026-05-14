#pragma once
#include <vector>
#include <string>
#include "Animal.h"

using std::vector;
using std::string;

class Cage {
private:
    int number;
    int maxCapacity;
    vector<Animal*> animals;

public:
    Cage(int num, int maxCap);
    ~Cage();

    void showAllAnimals() const;
    int getNumber() const;
    void setNumber(int num);
    int getMaxCapacity() const;
    void setMaxCapacity(int maxCap);
    int getCurrentCount() const;

    void addAnimal(Animal* animal);
    bool delAnimal(const string& name);
    Animal* findAnimal(const string& name) const;
};