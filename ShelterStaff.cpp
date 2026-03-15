#include "ShelterStaff.h"
#include <iostream>

ShelterStaff::ShelterStaff(std::string name, int userID)
    : ShelterUser(name, userID) {}

void ShelterStaff::addAnimal(Animal* animal) {

}

void ShelterStaff::removeAnimal(std::string animalID) {

    std::cout << "Staff " << getName() << " is authorizing removal of ID: " 
              << animalID << std::endl;
}

void ShelterStaff::displayUserInfo() const {
    std::cout << "Staff: " << getName()
              << ", ID: " << getUserID() << std::endl;
}