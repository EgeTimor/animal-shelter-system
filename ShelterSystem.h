#ifndef SHELTERSYSTEM_H
#define SHELTERSYSTEM_H

#include <vector>
#include <string>
#include "Animal.h"
#include "ShelterUser.h"

class ShelterSystem {
private:
    std::vector<Animal*> animals;
    std::vector<ShelterUser*> users;

    // Helper for recursive search
    Animal* searchHelper(std::string name, size_t index);

public:
    ShelterSystem();
    ~ShelterSystem();

    void addUser(ShelterUser* user);
    Animal* searchAnimal(std::string name);

    // System management methods
    void addAnimalToSystem(Animal* animal);
    void removeAnimalFromSystem(std::string animalID);

    void displayAllAnimals() const;
    void displayAllUsers() const;
};

#endif // SHELTERSYSTEM_H