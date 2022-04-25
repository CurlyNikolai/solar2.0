#include <string>
#include <iostream>
#include <iomanip>
#include "celestial.hpp"

Celestial::Celestial() {}

Celestial::Celestial(std::string new_name, float new_mass, Vec3f new_position, Vec3f new_velocity, Vec3f new_acceleration) : 
                     name(new_name), mass(new_mass), position(new_position), velocity(new_velocity), acceleration(new_acceleration) {}




// Method for printing out class information
std::string Celestial::printCelestialInfo() {
    std::string info = "Planet: " + name + "\n";

    info += "  - mass (kg): " + std::to_string(mass) + "\n";
    info += "  - position (km): " + std::to_string(position.x) + ", " + std::to_string(position.y) + ", " + std::to_string(position.z) + "\n";
    info += "  - velocity : " + std::to_string(velocity.x) + ", " + std::to_string(velocity.y) + ", " + std::to_string(velocity.z) + "\n";

    std::cout << "Planet: " + name + "\n";

    std::cout << std::left;
    std::cout << std::setw(20) << "  - mass: ";
    std::cout << std::right;
    std::cout << std::scientific << std::setw(15) << mass << "\n";

    std::cout << std::left;
    std::cout << std::setw(20) << "  - position: ";
    std::cout << std::right;
    std::cout << std::scientific << std::setw(15) << position.x << " " << std::setw(15) << position.y << " " << std::setw(15) << position.z << "\n";

    std::cout << std::left;
    std::cout << std::setw(20) << "  - velocity: ";
    std::cout << std::right;
    std::cout << std::scientific << std::setw(15) << velocity.x << " " << std::setw(15) << velocity.y << " " << std::setw(15) << velocity.z << "\n";

    std::cout << std::left;
    std::cout << std::setw(20) << "  - acceleration: ";
    std::cout << std::right;
    std::cout << std::scientific << std::setw(15) << acceleration.x << " " << std::setw(15) << acceleration.y << " " << std::setw(15) << acceleration.z << "\n";

    return info;

}