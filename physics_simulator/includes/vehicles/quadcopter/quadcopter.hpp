#ifndef QUADCOPTER_H
#define QUADCOPTER_H
#include "physics/rigid_body.hpp"
#include "rotor.hpp"
#include <cstddef>
#include <array>

class Quadcopter{
private:
    typedef std::array<Rotor, 4> Rotors;
    RigidBody rigid_body_;
    Rotors rotors_;
public:
    Quadcopter(RigidBody rigid_body, Rotors rotors): rigid_body_(rigid_body), rotors_ (rotors){}

    
    Vec3 get_position(){ return rigid_body_.position(); }
    Quaternion get_attitude(){ return rigid_body_.attitude(); }
    
    
};

#endif