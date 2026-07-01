#include "physics/physics_engine.hpp"
#include <iostream>


// for now just make -9.8m/s to y, can refactor later if needed
Vec3 physics_engine::get_gravitational_acceleration(RigidBody &object){
    //update acceleration
    return Vec3(0.0, -9.8, 0.0);
}

//add other forces here


void physics_engine::apply_velocity_to_position(RigidBody &object){
    object.update_position(time_step);
}

void physics_engine::apply_acceleration_to_velocity_linear(Vec3 acceleration, RigidBody &object){
    object.update_velocity(acceleration, time_step);
}

void physics_engine::step_time(){
    _total_time_s += time_step;
}

std::string physics_engine::print_total_time(){
    snprintf(log_buffer, 256, "%.03f", _total_time_s);
    return log_buffer;
}