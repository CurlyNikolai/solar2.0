#include "curlymath.hpp"

Vec3f::Vec3f() {
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

Vec3f::Vec3f(float new_x, float new_y, float new_z) {
    x = new_x;
    y = new_y;
    z = new_z;
}