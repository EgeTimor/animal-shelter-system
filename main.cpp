#include <iostream>
#include "ShelterSystem.h"
#include "Adopter.h"
#include "ShelterStaff.h"
#include "Animal.h"

int main() {
    std::cout << "Animal Shelter System Initialized." << std::endl;

    //Initializing System (ShelterSystem)
    ShelterSystem shelter;

    //Creating and Adding Users  John Doe, Sarah Smith with their IDs
    std::cout << std::endl;
    ShelterUser* adopter1 = new Adopter("John Doe", 101);
    std::cout << "Adding new adopter: " << adopter1->getName() << " (ID: " << adopter1->getUserID() << ")" << std::endl;
    shelter.addUser(adopter1);

    ShelterUser* staff1 = new ShelterStaff("Sarah Smith", 102);
    std::cout << "Adding new staff: " << staff1->getName() << " (ID: " << staff1->getUserID() << ")" << std::endl;
    shelter.addUser(staff1);

    //  Creating Animals & Staff, this adds them one by one
    // With this total animals will increment as new animals are defined. "Total animals: 1" then "Total animals: 2" output
    std::cout << std::endl;

    //Buddy (Count becomes 1)
    Animal* buddy = new Animal("Buddy", "Dog", "D101");

    ShelterStaff* staffPtr = dynamic_cast<ShelterStaff*>(staff1);
    if(staffPtr) staffPtr->addAnimal(buddy);

    // System stores "Total animals: 1"
    shelter.addAnimalToSystem(buddy);

    std::cout << std::endl;

    //Whiskers (Count becomes 2)
    Animal* whiskers = new Animal("Whiskers", "Cat", "C102");

    if(staffPtr) staffPtr->addAnimal(whiskers);

    // System stores "Total animals: 2"
    shelter.addAnimalToSystem(whiskers);

    // Adoption/Returning Process
    std::cout << std::endl;
    Adopter* adopterPtr = dynamic_cast<Adopter*>(adopter1);
    if (adopterPtr) {
        adopterPtr->adoptPet(buddy);

        // Possible error: trying to adopt an already adopted animal
        // adopterPtr->adoptPet(buddy); // Uncomment to test error message

        adopterPtr->returnPet(buddy);
    }

    shelter.displayAllAnimals();
    shelter.displayAllUsers();

    return 0;
}