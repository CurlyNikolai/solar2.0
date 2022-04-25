#include <iostream>
#include <vector>

#include "curlymath.hpp"
#include "celestial.hpp"
#include "velverlet.hpp"

int main() {

    std::cout << "\n=================\n";
    std::cout << "PROGRAM BEGINNING\n";
    std::cout << "=================\n";

    // Solar system initialization
    Celestial sun("Sun", 1.988E+30f, Vec3f(2.843E+05, 9.041E+05, -1.833E+4), Vec3f(-9.889E-3, 8.899E-03, 2.381E-04), Vec3f());
    Celestial earth("Earth", 5.972E+24, Vec3f(1.835E+07, 1.470E+08, -2.499E+4), Vec3f(-3.006E+1, 3.562E+00, 1.929E-04), Vec3f());
    std::vector<Celestial> celestials = {sun, earth};

    // Simulation specs initialization
    float dt = 50.0f; // timestep in seconds
    int steps = 10000; // number of timesteps to simulate

    // Print info over each celestial
    std::cout << "\n===== Initial State: =====" << std::endl;
    for (auto c : celestials)
        c.printCelestialInfo();

    // Main simulation loop
    for (int step = 0; step < steps; step++)
    {
        // Update each celestial with velocity verlet
        for (int i = 0; i < celestials.size(); i++) {
            update(dt, i, celestials);
        }
    }

    std::cout << "\n===== Final State: =====" << std::endl;
    //Print info over each celestial
    for (auto c : celestials) 
        c.printCelestialInfo();

    std::cout << "\n=================\n";
    std::cout << "PROGRAM END\n";
    std::cout << "=================\n";
}