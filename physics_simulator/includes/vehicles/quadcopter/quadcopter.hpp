#ifndef QUADCOPTER_H
#define QUADCOPTER_H
#include "physics/rigid_body.hpp"
#include "rotor.hpp"
#include <cstddef>
#include <array>

typedef std::array<Rotor, 4> Rotors;

class Quadcopter {
private:
    RigidBody rigid_body_;
    Rotors rotors_;
public:
    Quadcopter(RigidBody rigid_body, Rotors rotors): rigid_body_(rigid_body), rotors_ (rotors){}
    //immutable accessors
    const RigidBody& rigid_body() const { return rigid_body_; }
    const Rotors& rotors() const { return rotors_; }
    
    //mutable accessors
    RigidBody& rigid_body() { return rigid_body_; }
    Rotors& rotors() { return rotors_; }

    void set_rotor_rotational_freq(size_t rotor_id, double RPM){
        rotors_[rotor_id].set_RPM(RPM);
    }

    void set_rotor_direction(size_t rotor_id, enum SpinDirection direction){
        rotors_[rotor_id].set_spin_direction(direction);
    }
    //get downward force from weight
    Vec3 get_weight();
    //just get force, later get Torque and collect in Wrench type
    Vec3 get_force_from_current_state();
};

#endif