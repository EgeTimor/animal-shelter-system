#include "Adopter.h"
#include <iostream>
#include <algorithm>

// Constructor
Adopter::Adopter(std::string name, int userID)
    : ShelterUser(name, userID) {}

void Adopter::adoptPet(Animal* animal) {
    if (animal->isAdoptedStatus()) {
        std::cout << "Error: " << animal->getName() << " is already adopted." << std::endl;
        return;
    }
    animal->setAdoptionStatus(true);
    adoptedPets.push_back(animal);
    std::cout << "Adopter " << getName() << " is adopting \"" << animal->getName() << "\"." << std::endl;
}

void Adopter::returnPet(Animal* animal) {
    auto it = std::find(adoptedPets.begin(), adoptedPets.end(), animal);

    if (it != adoptedPets.end()) {
        animal->setAdoptionStatus(false);
        adoptedPets.erase(it);
        std::cout << "Adopter " << getName() << " returned \"" << animal->getName() << "\"." << std::endl;
    } else {
        std::cout << "Error: " << animal->getName() << " is not adopted by " << getName() << "." << std::endl;
    }
}

void Adopter::displayUserInfo() const {

    std::cout << "Adopter: " << getName()
              << ", ID: " << getUserID() << std::endl;
}