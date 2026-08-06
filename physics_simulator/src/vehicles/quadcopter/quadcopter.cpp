#include "vehicles/quadcopter/quadcopter.hpp"
#include "math/vec3.hpp"

Vec3 Quadcopter::get_force_from_current_state(){
    Vec3 total_force = Vec3();
    //todo use transform attitude to rotate force to global frame
    for (Propeller& p : propellers()){
        //body frame
        double thrust;
        double drag;
        double lift;
        total_force += {thrust-drag,0.0,lift};
        
    }
    return total_force;
}