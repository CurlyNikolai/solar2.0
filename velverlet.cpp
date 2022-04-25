#include "velverlet.hpp"

// Velocity verlet function for updating information in Celestial vector
void update(float dt, int i, std::vector<Celestial> &celestials)
{
    // Calculate values for next iteration
    Vec3f new_position = celestials[i].getPosition() + celestials[i].getVelocity() * dt + celestials[i].getAcceleration() * dt * dt * 0.5f;
    Vec3f new_acceleration = calculate_forces(i, celestials) * (1.0f / celestials[i].getMass());
    Vec3f new_velocity = celestials[i].getVelocity() + (celestials[i].getAcceleration() + new_acceleration) * dt * 0.5f;
    
    // Update values for next iteration
    celestials[i].setPosition(new_position);
    celestials[i].setVelocity(new_velocity);
    celestials[i].setAcceleration(new_acceleration);
}

// Method for calculating the force on the i:th celestial in celestials vector
Vec3f calculate_forces(int i, std::vector<Celestial> celestials) {

    float G = 6.67408E-20f; // Nkm^2 / kg^2
    Vec3f F = Vec3f();

    // Force calculation for celestial (sum force F)
    for (int j = 0; j < celestials.size(); j++)
    {
        if (i == j)
            continue;
        // Force calculation, see "Vector form" in https://en.wikipedia.org/wiki/Newton%27s_law_of_universal_gravitation
        float r_squared = (celestials[j].getPosition() - celestials[i].getPosition()).magnitude_squared();
        Vec3f r_norm = (celestials[j].getPosition() - celestials[i].getPosition()).normalized();
        F = F - G * (celestials[i].getMass() * celestials[j].getMass()) * r_norm * (1.0f / r_squared);
    }

    return F;
}