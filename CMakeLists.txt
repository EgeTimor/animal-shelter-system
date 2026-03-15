cmake_minimum_required(VERSION 3.20)
project(first)

set(CMAKE_CXX_STANDARD 17)

add_executable(first
        main.cpp
        Animal.cpp
        ShelterUser.cpp
        Adopter.cpp
        ShelterStaff.cpp
        ShelterSystem.cpp
)