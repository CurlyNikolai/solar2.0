#include <string>
#include <iostream>
#include <iomanip>
#include "celestial.hpp"

Celestial::Celestial() {}

Celestial::Celestial(std::string new_name, int new_id, double new_mass, Vec3d new_position, Vec3d new_velocity, Vec3d new_acceleration) : 
                     name_(new_name), id_(new_id), mass_(new_mass), position_(new_position), velocity_(new_velocity), acceleration_(new_acceleration) {}




void Celestial::printCelestialLine() {
    std::cout << std::left << std::setw(15) << name_ << id_;
    std::cout << std::right;
    std::cout << std::scientific << std::setw(15) << mass_;
    std::cout << std::setw(20) << position_.x << std::setw(20) << position_.y << std::setw(20) << position_.z;
    std::cout << std::setw(20) << velocity_.x << std::setw(20) << velocity_.y << std::setw(20) << velocity_.z << "\n";
}

// Method for printing out class information
void Celestial::printCelestialInfo() {
    //SAVE INFO STRING WRITING FOR LATER WHEN WRITE FUNCTION IS IMPLEMENTED
    //std::string info = "Planet: " + name_ + "\n";
    //info += "  - id: " + std::to_string(id_) + "\n";
    //info += "  - mass (kg): " + std::to_string(mass_) + "\n";
    //info += "  - position (km): " + std::to_string(position_.x) + ", " + std::to_string(position_.y) + ", " + std::to_string(position_.z) + "\n";
    //info += "  - velocity : " + std::to_string(velocity_.x) + ", " + std::to_string(velocity_.y) + ", " + std::to_string(velocity_.z) + "\n";

    std::cout << "Planet: " + name_ + "\n";

    std::cout << std::left;
    std::cout << std::setw(20) << "  - mass: ";
    std::cout << std::right;
    std::cout << std::scientific << std::setw(15) << mass_ << "\n";

    std::cout << std::left;
    std::cout << std::setw(20) << "  - position: ";
    std::cout << std::right;
    std::cout << std::scientific << std::setw(15) << position_.x << " " << std::setw(15) << position_.y << " " << std::setw(15) << position_.z << "\n";

    std::cout << std::left;
    std::cout << std::setw(20) << "  - velocity: ";
    std::cout << std::right;
    std::cout << std::scientific << std::setw(15) << velocity_.x << " " << std::setw(15) << velocity_.y << " " << std::setw(15) << velocity_.z << "\n";

    std::cout << std::left;
    std::cout << std::setw(20) << "  - acceleration: ";
    std::cout << std::right;
    std::cout << std::scientific << std::setw(15) << acceleration_.x << " " << std::setw(15) << acceleration_.y << " " << std::setw(15) << acceleration_.z << "\n";

}