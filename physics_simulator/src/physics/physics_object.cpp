#include "physics/physics_object.hpp"
#include <cstdio>
#include <iostream>
#include <string>


void physics_object::set_position(Vec3 position){
    _physics_transform.position.x = position.x;
    _physics_transform.position.y = position.y;
    _physics_transform.position.z = position.z;
}

void physics_object::set_velocity(Vec3 velocity){
    _physics_transform.velocity.x = velocity.x;
    _physics_transform.velocity.y = velocity.y;
    _physics_transform.velocity.z = velocity.z;
}


void physics_object::translate(Vec3 delta_position){
    _physics_transform.position.x += delta_position.x;
    _physics_transform.position.y += delta_position.y;
    _physics_transform.position.z += delta_position.z;
}


void physics_object::accelerate(Vec3 delta_velocity){
    _physics_transform.velocity.x += delta_velocity.x;
    _physics_transform.velocity.y += delta_velocity.y;
    _physics_transform.velocity.z += delta_velocity.z;
}

//may need to refactor once solid idea of timescale unit to process at
//as well as applying rotational velocity
void physics_object::apply_linear_velocity(double dt){
    translate(Vec3(
        _physics_transform.velocity.x * dt,
        _physics_transform.velocity.y * dt,
        _physics_transform.velocity.z * dt));
}

std::string physics_object::report_location(){
    snprintf(log_buffer, 256, "X: %.04f Y: %.04f Z: %.04f", 
        _physics_transform.x(), _physics_transform.y(), _physics_transform.z());
    return log_buffer;
}

std::string physics_object::report_velocity(){
    snprintf(log_buffer, 256, "VX: %.04f VY: %.04f VZ: %.04f", 
        _physics_transform.vx(), _physics_transform.vy(), _physics_transform.vz());
    return log_buffer;
}
