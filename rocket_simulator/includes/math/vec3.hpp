#ifndef VEC3_H
#define VEC3_H

class Vec3{
private:
    //private mutable vars
    double x_; 
    double y_; 
    double z_;
public:
    //constructor
    Vec3(double x, double y, double z): x_ (x), y_ (y), z_ (z) {}
    //readonly public access
    double x() const {return x_;}
    double y() const {return y_;}
    double z() const {return z_;}
    
};


#endif