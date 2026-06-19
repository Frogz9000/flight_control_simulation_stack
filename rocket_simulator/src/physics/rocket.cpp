#include "physics/rocket.hpp"


void rocket::translate(double new_x, double new_y, double new_z){
    _transform.position.x = new_x;
    _transform.position.y = new_y;
    _transform.position.z = new_z;
}

//may need to refactor once solid idea of timescale unit to process at
//as well as applying rotational velocity
void rocket::update(double time_seconds){
    _transform.position.x += (_transform.velocity.x * time_seconds);
    _transform.position.y += (_transform.velocity.y * time_seconds);
    _transform.position.z += (_transform.velocity.z * time_seconds);

}