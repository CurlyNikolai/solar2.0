#ifndef SOLARSYSTEM_HPP
#define SOLARSYSTEM_HPP

#include <vector>

#include "celestial.hpp"

class SolarSystem {

    public:
        SolarSystem();
        SolarSystem(std::string planet_file_path);
        ~SolarSystem();
        
        void addCelestial();
        void printSolarSystemFull();
        void printSolarSystemCompact();

        inline Celestial getCelestial(int id) { return celestials_[id]; };
        inline std::vector<Celestial> getCelestials() { return celestials_; };
        inline std::vector<Celestial>* getCelestialsPtr() { return &celestials_; };

        inline double getG() { return G_; };
        inline void setG(double new_G) { G_ = new_G; };

    private:
        std::vector<Celestial>     celestials_;
        double                     G_ = 6.67408E-20f; // Nkm^2 / kg^2

};

#endif // SOLARSYSTEM_HPP