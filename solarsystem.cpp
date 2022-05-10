
#include <fstream>
#include <string>
#include <sstream>

#include "solarsystem.hpp"
#include "celestial.hpp"

SolarSystem::SolarSystem() {

}

SolarSystem::~SolarSystem() {

}

SolarSystem::SolarSystem(std::string planet_file_path)
{

    // Open file and read planet information from each line
    std::string line;
    std::ifstream input_file(planet_file_path);
    if (input_file.is_open())
    {

        while (getline(input_file, line))
        {
            // Make line into stream to get planet information (name, id, mass, position and velocity)
            std::istringstream iss(line);
            std::string name;
            int         id;
            double      mass, px, py, pz, vx, vy, vz;

            iss >> name >> id >> mass >> px >> py >> pz >> vx >> vy >> vz;

            celestials_.push_back(Celestial(name, id, mass, Vec3d(px, py, pz), Vec3d(vx, vy, vz), Vec3d(0.0)));

        }
        input_file.close();
    
    }
    else
    {
        std::cout << "Unable to open provided input file at " + planet_file_path;
    }
}

void SolarSystem::printSolarSystemFull() {
    for (auto c : celestials_)
        c.printCelestialInfo();
}

void SolarSystem::printSolarSystemCompact() {
    for (auto c : celestials_)
        c.printCelestialLine();
}