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
    Frame(Vec3 position = Vec3(), Quaternion attitude = Quaternion()): _position(position), _attitude(attitude) {}

    void set_position(Vec3 position){ _position = position; }
    void set_attitude(Quaternion attitude){ _attitude = attitude; }
    
    //immutable accessors
    const Vec3& position() const { return _position; }
    const Quaternion& attitude() const { return _attitude; }
   
    //mutable accessors
    Vec3& position() { return _position; }
    Quaternion& attitude() { return _attitude; }
};



#endif