#include "physics/physics_engine.hpp"
#include <iostream>


// for now just make -9.8m/s to y, in future define earth COM xyz and draw 
// vector path from object COM to earth COM to get direction and gravitational strength
Vec3 physics_engine::get_gravitational_acceleration(physics_object &object){
    //update acceleration
    return Vec3(0.0, -9.8, 0.0);
}

void physics_engine::apply_velocity_to_position(double dt, physics_object &object){
    object.apply_linear_velocity(dt);
}
//add other forces here

void physics_engine::apply_acceleration_to_velocity(Vec3 acceleration, physics_object &object){
    object.accelerate(acceleration);

}

double physics_engine::step_time(){
    double time_step = 1.0/update_frequency_hz;
    _total_time_s += time_step;
    return time_step;
}

std::string physics_engine::get_total_time(){
    snprintf(log_buffer, 256, "%.03f", _total_time_s);
    return log_buffer;
}