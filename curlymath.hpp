

#ifndef CURLYMATH_HPP
#define CURLYMATH_HPP

#include <cmath>

// Class defining a 3D vector with float value elements
class Vec3f {
    public:
        Vec3f();
        Vec3f(float new_x, float new_y, float new_z);
        float x, y, z;

        // Methods for obtaining magnitude (length) of vector
        inline float magnitude() { return sqrt(x * x + y * y + z * z); };
        inline float magnitude_squared() { return (x * x + y * y + z * z); };
        inline Vec3f normalized() {return Vec3f(x / this->magnitude(), y / this->magnitude(), z / this->magnitude()); }
};


// Vector operator definitions
inline Vec3f operator*(const Vec3f v1, const float a) { return Vec3f(a * v1.x, a * v1.y, a * v1.z); };
inline Vec3f operator*(const float a, const Vec3f v1) { return Vec3f(a * v1.x, a * v1.y, a * v1.z); };
inline Vec3f operator+(const Vec3f v1, Vec3f v2) { return Vec3f(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z); }
inline Vec3f operator-(const Vec3f v1, const Vec3f v2) { return Vec3f(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z); }
inline float dot(const Vec3f v1, Vec3f v2) {return v1.x * v2.x + v1.y * v2.z + v1.z * v2.z;}

#endif // CURLYMATH_HPP