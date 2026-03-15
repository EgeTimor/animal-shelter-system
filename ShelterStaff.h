#ifndef SHELTERSTAFF_H
#define SHELTERSTAFF_H

#include "ShelterUser.h"
#include "Animal.h"
#include <string>

class ShelterStaff : public ShelterUser {
public:
    // Constructor
    ShelterStaff(std::string name, int userID);

    // Note: Since Staff doesn't hold the 'system' pointer,
    // these methods act as confirmation/logging actions.
    void addAnimal(Animal* animal);
    void removeAnimal(std::string animalID);

    // Override
    void displayUserInfo() const override;
};

#endif // SHELTERSTAFF_H