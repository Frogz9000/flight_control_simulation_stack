#include "physics/physics_engine.hpp"
#include <iostream>


// for now just make -9.8m/s to y, in future define earth COM xyz and draw 
// vector path from object COM to earth COM to get direction and gravitational strength
void physics_engine::apply_gravitational_force(physics_object &object){
    //update acceleration
    object.set_velocity(0.0, -9.8, 0.0);
}

void physics_engine::apply_velocity_to_position(double dt, physics_object &object){
    object.apply_linear_velocity(dt);
}
//add other forces here

double physics_engine::step_time(){
    double time_step = 1.0/update_frequency_hz;
    _total_time_s += time_step;
    return time_step;
}

std::string physics_engine::get_total_time(){
    snprintf(log_buffer, 256, "%.03f", _total_time_s);
    return log_buffer;
}