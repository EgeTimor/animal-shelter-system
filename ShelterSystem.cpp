#include "ShelterSystem.h"
#include "Adopter.h"      // <--- ADDED THIS LINE to fix the "cannot resolve symbol" error
#include <algorithm>      // for std::remove_if
#include <iostream>       // for std::cout

ShelterSystem::ShelterSystem() {}

ShelterSystem::~ShelterSystem() {
    // Cleans up dynamic memory (unnecesarry to keep these)
    for (Animal* a : animals) delete a;
    for (ShelterUser* u : users) delete u;
}

// Recursive Helper
Animal* ShelterSystem::searchHelper(std::string name, size_t index) {
    if (index >= animals.size()) {
        return nullptr; // Base case: nothing found from the search
    }
    if (animals[index]->getName() == name) {
        return animals[index]; // Found who was being searched
    }
    return searchHelper(name, index + 1); // Recursive Step (repeats)
}

// Public wrapper for search
Animal* ShelterSystem::searchAnimal(std::string name) {
    return searchHelper(name, 0);
}

void ShelterSystem::addUser(ShelterUser* user) {
    users.push_back(user);

    std::string role = (dynamic_cast<Adopter*>(user)) ? "adopter" : "staff";

}

void ShelterSystem::addAnimalToSystem(Animal* animal) {
    animals.push_back(animal);
    std::cout << "Adding animal: \"" << animal->getName() << "\" ("
              << animal->getSpecies() << "), ID: " << animal->getAnimalID() << std::endl;
    std::cout << "Total animals: " << Animal::getTotalAnimals() << std::endl;
}

void ShelterSystem::removeAnimalFromSystem(std::string animalID) {
    auto it = std::remove_if(animals.begin(), animals.end(),
        [animalID](Animal* a) {
            if (a->getAnimalID() == animalID) {
                delete a; // Frees memory
                return true;
            }
            return false;
        });

    if (it != animals.end()) {
        animals.erase(it, animals.end());
        std::cout << "Animal " << animalID << " removed." << std::endl;
    } else {
        std::cout << "Animal ID not found." << std::endl;
    }
}

void ShelterSystem::displayAllAnimals() const {
    std::cout << "\nDisplaying all animals:" << std::endl;
    for (const auto& animal : animals) {
        animal->displayInfo();
    }
    std::cout << "Total animals: " << Animal::getTotalAnimals() << std::endl;
}

void ShelterSystem::displayAllUsers() const {
    std::cout << "\nDisplaying all users:" << std::endl;
    for (const auto& user : users) {
        user->displayUserInfo();
    }
}