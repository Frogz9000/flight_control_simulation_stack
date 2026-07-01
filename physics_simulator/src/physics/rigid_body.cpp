#include "physics/rigid_body.hpp"
#include <cstdio>
#include <iostream>
#include <string>


std::string RigidBody::report_location(){
    snprintf(log_buffer, 256, "X: %.04f Y: %.04f Z: %.04f", 
        position().x, position().y, position().z);
    return log_buffer;
}

std::string RigidBody::report_velocity(){
    snprintf(log_buffer, 256, "VX: %.04f VY: %.04f VZ: %.04f", 
        linear_velocity().x, linear_velocity().y, linear_velocity().z);
    return log_buffer;
}

void RigidBody::update_velocity(Vec3 acceleration, double dt){
    linear_velocity_.x += acceleration.x * dt;
    linear_velocity_.y += acceleration.y * dt;
    linear_velocity_.z += acceleration.z * dt;

}

void RigidBody::update_position(double dt){
    position_.x += linear_velocity_.x * dt;
    position_.y += linear_velocity_.y * dt;
    position_.z += linear_velocity_.z * dt;


}