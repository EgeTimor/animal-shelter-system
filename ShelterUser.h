#ifndef SHELTERUSER_H
#define SHELTERUSER_H

#include <string>
#include <iostream>

class ShelterUser {
protected:
    std::string name;
    int userID;

public:

    ShelterUser(std::string name, int userID);

    // Destructor:
    virtual ~ShelterUser();

    // Pure Virtual Function
    virtual void displayUserInfo() const = 0;

    // Getters
    std::string getName() const;
    int getUserID() const;
};

#endif // SHELTERUSER_H