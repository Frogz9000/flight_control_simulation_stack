#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H
#include <vector>
#include <ctime>
#include <memory>
#include "physics/physics_object.hpp"
using namespace std;
void apply_forces_and_update(double dt, unique_ptr<physics_object> &object);

double get_time_step_ms();

void apply_gravitational_force(double dt, unique_ptr<physics_object> &object);

void apply_velocity_to_position(double dt, unique_ptr<physics_object> &object);
#endif