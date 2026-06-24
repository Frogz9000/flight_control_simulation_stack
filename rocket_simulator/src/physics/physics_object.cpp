#include "physics/physics_object.hpp"
#include <cstdio>
#include <iostream>
#include <string>


void physics_object::set_position(double x, double y, double z){
    _physics_transform.position.x = x;
    _physics_transform.position.y = y;
    _physics_transform.position.z = z;
}

void physics_object::set_velocity(double x, double y, double z){
    _physics_transform.velocity.x = x;
    _physics_transform.velocity.y = y;
    _physics_transform.velocity.z = z;
}


void physics_object::translate(double delta_x, double delta_y, double delta_z){
    _physics_transform.position.x += delta_x;
    _physics_transform.position.y += delta_y;
    _physics_transform.position.z += delta_z;
}


void physics_object::accelerate(double delta_x, double delta_y, double delta_z){
    _physics_transform.velocity.x += delta_x;
    _physics_transform.velocity.y += delta_y;
    _physics_transform.velocity.z += delta_z;
}

//may need to refactor once solid idea of timescale unit to process at
//as well as applying rotational velocity
void physics_object::apply_linear_velocity(double dt){
    translate(_physics_transform.velocity.x * dt,
              _physics_transform.velocity.y * dt,
              _physics_transform.velocity.z * dt);
}

std::string physics_object::report_location(){
    snprintf(log_buffer, 256, "X: %.04f Y: %.04f Z: %.04f", 
        _physics_transform.x(), _physics_transform.y(), _physics_transform.z());
    return log_buffer;
}
