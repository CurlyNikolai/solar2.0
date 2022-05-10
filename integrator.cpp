#include "integrator.hpp"

// Velocity verlet function for updating information in Celestial vector
void velverlet_update(double dt, int i, std::vector<Celestial> &celestials, double G)
{
    // Calculate values for next iteration
    Vec3d new_position = celestials[i].getPosition() + celestials[i].getVelocity() * dt + celestials[i].getAcceleration() * dt * dt * 0.5f;
    Vec3d new_acceleration = gravitational_force(i, celestials, G) * (1.0f / celestials[i].getMass());
    Vec3d new_velocity = celestials[i].getVelocity() + (celestials[i].getAcceleration() + new_acceleration) * dt * 0.5f;
    
    // Update values for next iteration
    celestials[i].setPosition(new_position);
    celestials[i].setVelocity(new_velocity);
    celestials[i].setAcceleration(new_acceleration);
}

// Method for calculating the force on the i:th celestial in celestials vector. G is Newton's gravitational constant
Vec3d gravitational_force(int i, std::vector<Celestial> celestials, double G) {

    Vec3d F = Vec3d(0.0);

    // Force calculation for celestial (sum force F)
    for (int j = 0; j < celestials.size(); j++)
    {
        if (i == j)
            continue;
        // Force calculation, see "Vector form" in https://en.wikipedia.org/wiki/Newton%27s_law_of_universal_gravitation
        double r_squared = (celestials[j].getPosition() - celestials[i].getPosition()).magnitude_squared();
        Vec3d r_norm = (celestials[j].getPosition() - celestials[i].getPosition()).normalized();
        F = F + G * (celestials[i].getMass() * celestials[j].getMass()) * r_norm * (1.0f / r_squared);
    }
    return F;
}