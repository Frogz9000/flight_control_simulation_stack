#include "vehicles/quadcopter/rotor.hpp"
#include "math/vec3.hpp"

Vec3 Rotor::get_lift(){
        //Lift = 1/2 rho v^2 A C_L
        //rho = air density (set this constant for now)
        //v = velocity through air
        //A = area of wing
        //C_L = lift coefficient
        return Vec3();
}

Vec3 Rotor::get_drag(){
        //drag is 1/2 rho velocity^2 A C_D
        return Vec3();
}

Vec3 Rotor::get_thrust(){
        return Vec3();
}


Vec3 Rotor::get_current_force(){
       return get_lift()+get_drag()+get_thrust(); 
}