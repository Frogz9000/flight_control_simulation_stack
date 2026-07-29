#include "vehicles/quadcopter/quadcopter.hpp"
#include "math/vec3.hpp"

Vec3 Quadcopter::get_weight(){
    return Vec3(0,0,rigid_body().mass()*9.8);
}

Vec3 Quadcopter::get_force_from_current_state(){
    Vec3 total_force = get_weight();
    //todo use transform attitude to rotate force to global frame
    
    return total_force;
}