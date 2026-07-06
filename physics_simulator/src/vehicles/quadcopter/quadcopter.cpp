#include "vehicles/quadcopter/quadcopter.hpp"


Vec3 Quadcopter::get_force_from_current_state(){
    Vec3 total_force = {0,0,0};
    for (auto rotor : rotors_){
        total_force += rotor.get_current_force();
    }
    //todo use transform attitude to rotate force to global frame
    
    return total_force;
}