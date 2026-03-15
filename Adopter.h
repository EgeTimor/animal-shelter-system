#ifndef ADOPTER_H
#define ADOPTER_H

#include "ShelterUser.h"
#include "Animal.h"
#include <vector>

class Adopter : public ShelterUser {
private:
    std::vector<Animal*> adoptedPets;

public:
    // Constructor
    Adopter(std::string name, int userID);

    // functions for adopting and returning pets
    void adoptPet(Animal* animal);
    void returnPet(Animal* animal);

    void displayUserInfo() const override;
};

#endif // ADOPTER_H