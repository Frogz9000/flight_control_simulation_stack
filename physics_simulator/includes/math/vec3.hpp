#ifndef VEC3_H
#define VEC3_H

class Vec3{
public:
    double x; 
    double y; 
    double z;
    Vec3(double x, double y,double z): x(x), y(y), z(z) {}


    Vec3& operator+=(const Vec3& other){
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

};
Vec3 operator+(const Vec3& lhs, const Vec3& rhs){
    Vec3 ret_val = lhs;
    ret_val+=rhs;
    return ret_val;
}
#endif