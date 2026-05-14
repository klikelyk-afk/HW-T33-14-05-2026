#include <iostream>
#include <string>
#include <vector>
#include "Cage.h"
#include "Animal.h"
#include "ZooException.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main() {
    vector<Cage*> zoo;
    zoo.push_back(new Cage(1, 3));
    zoo.push_back(new Cage(2, 5));


    Animal* myGoldfish = new Fish("Goldie", false, false);
    Animal* myEagle = new Bird("Sky", true, 150.0);
    Animal* myLion = new Mammal("Simba", true, "Savannah");


    try {
        zoo[0]->addAnimal(myGoldfish);
        zoo[1]->addAnimal(myEagle);
        zoo[1]->addAnimal(myLion);
    }
    catch (const ZooException& e) {
        cout << "Pre-start error: " << e.showMessage() << endl;
    }

    int choice = -1;
    cout << "=== ZOO MANAGEMENT SYSTEM ===" << endl;

    while (choice != 0) {
        cout << "\n--- MAIN MENU ---" << endl;
        cout << "1. Add Animal to Specific Cage" << endl;
        cout << "2. Remove Animal from Cage" << endl;
        cout << "3. Show Specific Cage Status" << endl;
        cout << "4. Show All Animals in Specific Cage" << endl;
        cout << "5. GLOBAL REPORT (All Cages)" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        try {
            if (choice == 1) {
                int cageIdx;
                cout << "Select Cage Index (0 to " << zoo.size() - 1 << "): ";
                cin >> cageIdx;

                if (cageIdx < 0 || cageIdx >= zoo.size()) {
                    cout << "!!! Invalid cage index!" << endl;
                }
                else {
                    string name;
                    int isPred, type;
                    cout << "Select Type: 1-Fish, 2-Bird, 3-Mammal: ";
                    cin >> type;
                    cout << "Name: "; cin >> name;
                    cout << "Predator? (1-Yes, 0-No): "; cin >> isPred;

                    Animal* newAnimal = nullptr;
                    if (type == 1) {
                        int deep; cout << "Deepwater? (1-Yes, 0-No): "; cin >> deep;
                        newAnimal = new Fish(name, isPred == 1, deep == 1);
                    }
                    else if (type == 2) {
                        double speed; cout << "Flight speed: "; cin >> speed;
                        newAnimal = new Bird(name, isPred == 1, speed);
                    }
                    else if (type == 3) {
                        string hab; cout << "Habitat: "; cin >> hab;
                        newAnimal = new Mammal(name, isPred == 1, hab);
                    }
                    else {
                        newAnimal = new Animal(name, isPred == 1);
                    }

                    zoo[cageIdx]->addAnimal(newAnimal);
                    cout << ">> Success! Added to Cage #" << zoo[cageIdx]->getNumber() << endl;
                }
            }
            else if (choice == 2) {
                int cageIdx;
                cout << "Cage Index: "; cin >> cageIdx;
                if (cageIdx >= 0 && cageIdx < zoo.size()) {
                    string name;
                    cout << "Name to delete: "; cin >> name;
                    if (zoo[cageIdx]->delAnimal(name)) cout << ">> Deleted." << endl;
                    else cout << ">> Not found." << endl;
                }
            }
            else if (choice == 3) {
                int cageIdx;
                cout << "Cage Index: "; cin >> cageIdx;
                if (cageIdx >= 0 && cageIdx < zoo.size()) {
                    cout << "Cage #" << zoo[cageIdx]->getNumber()
                        << " | Animals: " << zoo[cageIdx]->getCurrentCount()
                        << "/" << zoo[cageIdx]->getMaxCapacity() << endl;
                }
            }
            else if (choice == 4) {
                int cageIdx;
                cout << "Cage Index: "; cin >> cageIdx;
                if (cageIdx >= 0 && cageIdx < zoo.size()) {
                    zoo[cageIdx]->showAllAnimals();
                }
            }
            else if (choice == 5) {
                cout << "\n======= GLOBAL ZOO REPORT =======" << endl;
                for (int i = 0; i < zoo.size(); i++) {
                    cout << "CAGE INDEX [" << i << "] (Number: " << zoo[i]->getNumber() << ")" << endl;
                    zoo[i]->showAllAnimals();
                    cout << "---------------------------------" << endl;
                }
            }
        }
        catch (const ZooException& e) {
            cout << "\n!!! SYSTEM ERROR: " << e.showMessage() << endl;
        }
        catch (...) {
            cout << "\n!!! Critical error occurred!" << endl;
        }
    }


    for (auto c : zoo) delete c;

    cout << "System closed." << endl;
    return 0;
}