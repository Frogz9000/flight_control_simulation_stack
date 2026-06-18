#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H
#include "math/vec3.hpp"
#include "math/quaternion.hpp"
#include <string>

class rocket_transform{
private:
    Vec3 coordinates;
    Vec3 velocity;
    Quaternion attitude;
    Vec3 angular_velocity;//is this vec 3???
public:
    //default rocket constructor
    rocket_transform(Vec3 coordinates, Vec3 velocity,  Quaternion attitude, Vec3 angular_velocity): 
    coordinates (coordinates), attitude (attitude), velocity (velocity), angular_velocity (angular_velocity){}
    //getters
    //return x coordinate
    double x() const {return coordinates.x;}
    //return y coordinate
    double y() const {return coordinates.y;}
    //return z coordinate
    double z() const {return coordinates.z;}

    //return velocity in x direction
    double vx() const {return velocity.x;}
    //return velocity in y direction
    double vy() const {return velocity.y;}
    //return velocity in z direction
    double vz() const {return velocity.z;}
    
    //need to learn to more about quaternions and av to do more

    std::string print_position(void);


};

class rocket
{
    rocket_transform transform;
};

#endif