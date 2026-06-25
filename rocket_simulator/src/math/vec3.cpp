#include "math/vec3.hpp"

Vec3& Vec3::operator+=(const Vec3& other){
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}