#ifndef VEC3_H
#define VEC3_H

class Vec3{
public:
    double x; 
    double y; 
    double z;
    Vec3(double x, double y,double z): x(x), y(y), z(z) {}


    Vec3& operator+=(const Vec3& other);

};
Vec3 operator+(const Vec3& lhs, const Vec3& rhs);

#endif