#include <vector>

#include "celestial.hpp"
#include "curlymath.hpp"

void update(float dt, int i, std::vector<Celestial> &celestials);
Vec3f calculate_forces(int i, std::vector<Celestial> celestials);