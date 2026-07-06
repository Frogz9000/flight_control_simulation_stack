#ifndef VEHICLE_H
#define VEHICLE_H
#include "math/vec3.hpp"

class Vehicle{

    virtual Vec3 get_force_from_current_state();
};


#endif