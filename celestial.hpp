#ifndef CELESTIAL_HPP
#define CELESTIAL_HPP


#include <iostream>

#include "curlymath.hpp"


// Class for holding information o celestial object (planets, moons, stars)
class Celestial {

    public:
        Celestial();
        Celestial(std::string new_name, int id, double new_mass, Vec3d new_position, Vec3d new_velocity, Vec3d new_acceleration);

        // Getters
        inline std::string getName()    { return name_; };
        inline int getId()              { return id_; };
        inline float getMass()          { return mass_; };
        inline Vec3d getPosition()      { return position_; };
        inline Vec3d getVelocity()      { return velocity_; };
        Vec3d getAcceleration()         { return acceleration_; };

        // Setters
        inline void setMass(double new_mass)                     { mass_ = new_mass; };
        inline void setPosition(Vec3d new_position)             { position_ = new_position; };
        inline void setVelocity(Vec3d new_velocity)             { velocity_ = new_velocity; };
        inline void setAcceleration(Vec3d new_acceleration)     { acceleration_ = new_acceleration; };

        void printCelestialInfo();
        void printCelestialLine();

    private:
        std::string     name_ = "";
        double          mass_ = 0.0f;
        int             id_;
        Vec3d           position_ = Vec3d();
        Vec3d           velocity_ = Vec3d();
        Vec3d           acceleration_ = Vec3d();
};

#endif // CELESTIAL_HPP