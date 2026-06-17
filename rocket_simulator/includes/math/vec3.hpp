#ifndef VEC3_H
#define VEC3_H

class Vec3{
private:
    //private mutable vars
    double x_; 
    double y_; 
    double z_;
public:
    Vec3(double x, double y, double z);
    //readonly public access
    double Vec3::x() const {return x_;}
    double Vec3::y() const {return y_;}
    double Vec3::z() const {return z_;}
};



#endif