#ifndef POSE_H
#define POSE_H
#include "math/vec3.hpp"
#include "math/quaternion.hpp"

class Pose{
private:
    Vec3 position_;
    Quaternion attitude_;
public:
    //default constructor
    Pose(Vec3 position = {0,0,0},  Quaternion attitude = {0,0,0,0}): 
    position_ (position), attitude_ (attitude){}
    //getters
    const Vec3& position() const {return position_;}
    const Quaternion& attitude() const {return attitude_;}
    //setters
    void set_position(Vec3 position){ position_ = position; }
    void set_attitude(Quaternion attitude){ attitude_ = attitude; }
};

#endif