#ifndef FRAME_H
#define FRAME_H
#include "math/vec3.hpp"
#include "math/quaternion.hpp"

class Frame{
private:
    Vec3 _position;
    Quaternion _attitude;
public:
    //rotation/transformation to another frame will live here
    Frame(Vec3 position, Quaternion attitude): _position(position), _attitude(attitude) {}
};



#endif