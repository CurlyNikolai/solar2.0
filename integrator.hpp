#include <vector>

#include "celestial.hpp"
#include "curlymath.hpp"

void velverlet_update(double dt, std::vector<Celestial> &celestials, double G);
Vec3d gravitational_force(int i, std::vector<Celestial> celestials, double G);