#include "physics/physics_object.hpp"


void physics_object::translate(double new_x, double new_y, double new_z){
    _transform.position.x = new_x;
    _transform.position.y = new_y;
    _transform.position.z = new_z;
}

//may need to refactor once solid idea of timescale unit to process at
//as well as applying rotational velocity
void physics_object::apply_linear_acceleration(double dt){
    _transform.position.x += (_transform.velocity.x * dt);
    _transform.position.y += (_transform.velocity.y * dt);
    _transform.position.z += (_transform.velocity.z * dt);

}