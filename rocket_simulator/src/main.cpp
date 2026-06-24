#include <iostream>
#include <ostream>
#include "physics/physics_engine.hpp"
#include "physics/physics_transform.hpp"

int simulation_hz = 1000;
int simulation_duration_seconds = 60;
int main(){
    physics_object rocket = physics_object(physics_transform(Vec3(0,0,0),Vec3(0,0,0),Quaternion(0,0,0,0),Vec3(0,0,0)), 1000);
    rocket.set_position(10, 0, 0);
    physics_engine engine = physics_engine(simulation_hz);//1ms ticks

    for (int i = 0; i<=(simulation_hz * simulation_duration_seconds); i++){
        cout << engine.get_total_time()<< ": " << rocket.report_location() << endl;
        double time_step = engine.step_time();
        engine.apply_gravitational_force(rocket);
        engine.apply_velocity_to_position(time_step, rocket);
    }
}