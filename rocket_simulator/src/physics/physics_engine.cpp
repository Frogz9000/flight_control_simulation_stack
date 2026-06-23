#include "physics/physics_engine.hpp"
#include <bits/types/clock_t.h>

clock_t start = clock();

void apply_forces_and_update(double dt, unique_ptr<physics_object> &object){
    apply_gravitational_force(dt, object);
}
//get delta time in milliseconds
double get_time_step_ms(){
    clock_t ticks = clock() - start;
    return (double(ticks) / CLOCKS_PER_SEC) * 1000; //get time in ms
}
//in future this will need to take altitude into account to reduce gravitational pull
//for now just makje -9.8m/s to y, in future define earth COM xyz and draw 
// vector path from object COM to earth COM to get acceleration direction
void apply_gravitational_force(double dt, unique_ptr<physics_object> &object){
    //update acceleration
    object->translate(1,1,1);
}

void apply_velocity_to_position(double dt, unique_ptr<physics_object> &object){
    object->apply_linear_acceleration(dt);
}
//add other forces here
