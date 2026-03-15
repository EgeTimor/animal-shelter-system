#include "ShelterUser.h"

// Constructor
ShelterUser::ShelterUser(std::string name, int userID)
    : name(name), userID(userID) {}

// Destructor
ShelterUser::~ShelterUser() {}

// Getters
std::string ShelterUser::getName() const { return name; }
int ShelterUser::getUserID() const { return userID; }