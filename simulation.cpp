#include "simulation.hpp"
#include "integrator.hpp"
#include "celestial.hpp"
#include "solarsystem.hpp"
Simulation::Simulation() {}

Simulation::~Simulation() {}

void Simulation::runSimulation() {

    std::vector<Celestial> &celestials = *system_.getCelestialsPtr();
    double G = system_.getG();

    std::cout << celestials.size() << "\n";
    std::cout << "Framenumber: " << 0 << "\n";
    system_.printSolarSystemCompact();

    // Main simulation loop
    for (int step = 1; step <= steps_; step++) {
        
        // Update celestials with velocity verlet
        velverlet_update(dt_, celestials, G);

        if (step % print_interval_ == 0) {
            std::cout << celestials.size() << "\n";
            std::cout << "Framenumber: " << step << "\n";
            system_.printSolarSystemCompact();
        }

    }
    
}