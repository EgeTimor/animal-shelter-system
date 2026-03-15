#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

class Animal {
private:
    std::string name;
    std::string species;
    std::string animalID;
    bool isAdopted;
    static int totalAnimals; // Static variable declaration

public:
    // Constructor
    Animal(std::string name, std::string species, std::string animalID);

    // Destructor
    ~Animal();

    // Functions of the class (methods)
    void displayInfo() const;
    void setAdoptionStatus(bool status);
    bool isAdoptedStatus() const;

    // Static Method
    static int getTotalAnimals();

    // Getters
    std::string getName() const;
    std::string getSpecies() const;
    std::string getAnimalID() const;
};

#endif // ANIMAL_H