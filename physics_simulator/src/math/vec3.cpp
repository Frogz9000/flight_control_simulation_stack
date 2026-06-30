#include "math/vec3.hpp"

Vec3& Vec3::operator+=(const Vec3& other){
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

 Vec3 operator+(const Vec3& lhs, const Vec3& rhs){
    Vec3 ret_val = lhs;
    ret_val+=rhs;
    return ret_val;
 }