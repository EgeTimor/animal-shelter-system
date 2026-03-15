#include "Animal.h"
// Initializing static member
int Animal::totalAnimals = 0;

// Constructor
Animal::Animal(std::string name, std::string species, std::string animalID)
    : name(name), species(species), animalID(animalID), isAdopted(false) {
    totalAnimals++;
}

// Destructor
Animal::~Animal() {
    totalAnimals--;
}

// Displays the animals information
void Animal::displayInfo() const {
    std::cout << "Name: " << name
              << ", Species: " << species
              << ", ID: " << animalID
              << ", Adopted: " << (isAdopted ? "Yes" : "No")
              << std::endl;
}

void Animal::setAdoptionStatus(bool status) {
    isAdopted = status;
}

bool Animal::isAdoptedStatus() const {
    return isAdopted;
}

// Static method implementation
int Animal::getTotalAnimals() {
    return totalAnimals;
}

// Getters
std::string Animal::getName() const { return name; }
std::string Animal::getSpecies() const { return species; }
std::string Animal::getAnimalID() const { return animalID; }