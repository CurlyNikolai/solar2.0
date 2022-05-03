#ifndef CELESTIAL_HPP
#define CELESTIAL_HPP


#include <iostream>

#include "curlymath.hpp"


// Class for holding information o celestial object (planets, moons, stars)
class Celestial {

    public:
        Celestial();
        Celestial(std::string new_name, float new_mass, Vec3f new_position, Vec3f new_velocity, Vec3f new_acceleration);

        // Getters
        inline std::string getName()    { return name; };  
        inline float getMass()          { return mass; };
        inline Vec3f getPosition()      { return position; };
        inline Vec3f getVelocity()      { return velocity; };
        Vec3f getAcceleration()         { return acceleration; };

        // Setters
        inline void setMass(float new_mass)                     { mass = new_mass; };
        inline void setPosition(Vec3f new_position)             { position = new_position; };
        inline void setVelocity(Vec3f new_velocity)             { velocity = new_velocity; };
        inline void setAcceleration(Vec3f new_acceleration)     { acceleration = new_acceleration; };

        void printCelestialInfo();

    private:
        std::string name = "";
        float mass = 0.0f;
        Vec3f position = Vec3f();
        Vec3f velocity = Vec3f();
        Vec3f acceleration = Vec3f();
};

#endif // CELESTIAL_HPP