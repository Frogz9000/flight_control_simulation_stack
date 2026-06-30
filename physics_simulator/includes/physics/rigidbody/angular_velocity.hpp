#ifndef ANGULAR_VELOCITY_H
#define ANGULAR_VELOCITY_H
#include "math/vec3.hpp"
#include "math/quaternion.hpp"

class AngularVelocity{
private:
    Vec3 angular_velocity_;
   
public:
    //default constructor
    AngularVelocity(Vec3 velocity = {0,0,0}): 
    angular_velocity_ (velocity){}
    //getters
    const Vec3& velocity() const {return angular_velocity_;}
    //setters
    void set_velocity(Vec3 velocity){ angular_velocity_ = velocity; }
};

#endif