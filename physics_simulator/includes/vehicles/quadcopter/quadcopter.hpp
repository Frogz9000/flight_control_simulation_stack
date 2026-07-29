#ifndef QUADCOPTER_H
#define QUADCOPTER_H
#include "physics/rigid_body.hpp"
#include "vehicles/components/propeller.hpp"
#include <cstddef>
#include <array>

typedef std::array<Propeller, 4> Propellers;

class Quadcopter {
private:
    RigidBody _rigid_body;
    Propellers _props; //props are a POD class, force calc should all exist here
public:
    Quadcopter(RigidBody rigid_body, Propellers propellers): _rigid_body(rigid_body), _props (propellers){}
    //immutable accessors
    const RigidBody& rigid_body() const { return _rigid_body; }
    const Propellers& propellers() const { return _props; }
    
    //mutable accessors
    RigidBody& rigid_body() { return _rigid_body; }
    Propellers& propellers() { return _props; }

    void set_rotor_rotational_freq(size_t prop_id, double RPM){
        _props[prop_id].set_RPM(RPM);
    }

    void set_rotor_direction(size_t prop_id, enum SpinDirection direction){
        _props[prop_id].set_spin_direction(direction);
    }
    //get downward force from weight
    Vec3 get_weight();
    //just get force, later get Torque and collect in Wrench type
    Vec3 get_force_from_current_state();
};

#endif