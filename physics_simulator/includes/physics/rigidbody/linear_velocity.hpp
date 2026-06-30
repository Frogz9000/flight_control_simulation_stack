#ifndef LINEAR_VELOCITY_H
#define LINEAR_VELOCITY_H
#include "math/vec3.hpp"
class LinearVelocity{
private:
    Vec3 velocity_;
   
public:
    //default constructor
    LinearVelocity(Vec3 velocity = {0,0,0}): 
    velocity_ (velocity){}
    //getters
    const Vec3& velocity() const {return velocity_;}
    //setters
    void set_velocity(Vec3 velocity){ velocity_ = velocity; }
};

#endif


