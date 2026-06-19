#ifndef ROCKET_TRANSFORM_H
#define ROCKET_TRANSFORM_H

#include "math/vec3.hpp"
#include "math/quaternion.hpp"
#include <string>

class rocket_transform{
public:
    Vec3 position;
    Vec3 velocity;
    Quaternion attitude;
    Vec3 angular_velocity;//is this vec 3???

    //default rocket constructor
    rocket_transform(Vec3 position, Vec3 velocity,  Quaternion attitude, Vec3 angular_velocity): 
    position (position), attitude (attitude), velocity (velocity), angular_velocity (angular_velocity){}
    //getters
    //return x coordinate
    double x() const {return position.x;}
    //return y coordinate
    double y() const {return position.y;}
    //return z coordinate
    double z() const {return position.z;}

    //return velocity in x direction
    double vx() const {return velocity.x;}
    //return velocity in y direction
    double vy() const {return velocity.y;}
    //return velocity in z direction
    double vz() const {return velocity.z;}
    
    //need to learn to more about quaternions and av to do more

    std::string print_position(void);
};

#endif