#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "curlymath.hpp"
#include "celestial.hpp"
#include "integrator.hpp"
#include "solarsystem.hpp"
#include "simulation.hpp"

using namespace std;

int main(int argc, char *argv[]) {


    // Read solar system from file
    string input_file_path = "./data/test_data.dat";
    SolarSystem system(input_file_path);

    Simulation simulation;

    simulation.setSolarSystem(system);

    simulation.setSteps(6311600);
    simulation.setPrintInterval(10000);
    simulation.setTimeStep(1000.0);

    simulation.runSimulation();
}