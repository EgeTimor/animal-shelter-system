# Animal Shelter Management System

## Overview
I wanted to reinforce what I learned in object-oriented C++ programming so i decided to build a C++ Object-Oriented Management System that utilizes stuff like dynamic memory allocation and polymorphism.
This project is a C++ Object-Oriented system that is designed to manage the daily operations of an animal shelter. The system tracks animal inventory, handles user roles, and processes adoptions using dynamic memory allocation and polymorphism.

## System Architecture
The architecture is esentially split into five primary classes with specific responsibilities:

* **Animal**: Represents individual animals with encapsulated attributes (name, species, ID, adoption status) and maintains a static counter for the total number of animals in the system.
* **ShelterUser (Abstract Base Class)**: Serves as a generic template for system users, defining common attributes and a pure virtual function (`displayUserInfo()`) that enforces implementation in derived classes. It utilizes a virtual destructor to ensure derived class destructors are called correctly for safe memory cleanup.
* **Adopter**: Derived from `ShelterUser`, this class uses a dynamically resizable array (`std::vector<Animal*>`) to track a user's adopted pets, updating adoption statuses during the `adoptPet` and `returnPet` processes.
* **ShelterStaff**: Derived from `ShelterUser`, this class simulates authorization for staff members to process adding or removing animals from the system.
* **ShelterSystem**: The main controller managing collections of dynamic animal and user objects.

## Technical Highlights
* **Polymorphism**: The system stores both `Adopter` and `ShelterStaff` objects as `ShelterUser*` pointers in a single dynamic array, allowing uniform method calls across different user types.
* **Dynamic Memory Management**: Objects are instantiated dynamically using the `new` keyword to ensure they persist beyond single functions. The `ShelterSystem` destructor iterates through all vectors and deletes every pointer to prevent memory leaks.
* **Data Structures**: Dynamic arrays (`std::vector`) are utilized instead of static arrays to seamlessly handle the fluctuating number of shelter users and animals.
* **Recursive Search**: Implements a private recursive helper function to efficiently search through the dynamic array of animals by name.

## Development Challenges Overcome
* Refactored the initial architecture from static arrays to dynamic `std::vector` implementations to better manage memory.
* Resolved linking errors in the build process by updating the `CMakeLists.txt` file to properly include all source class files.
* Debugged and corrected an object instantiation order issue that was causing the static total animal counter to miscalculate upon initialization.
