#include <iostream>
#include <ostream>
#include "physics/physics_engine.hpp"
#include "physics/physics_transform.hpp"

int simulation_hz = 1000;
int simulation_duration_seconds = 60;
int main(){
    physics_object rocket = physics_object(physics_transform(Vec3(0,0,0),Vec3(0,0,0),Quaternion(0,0,0,0),Vec3(0,0,0)), 1000);
    rocket.set_position(Vec3(10, 0, 0));
    physics_engine engine = physics_engine(simulation_hz);//1ms ticks

    for (int i = 0; i<=(simulation_hz * simulation_duration_seconds); i++){
        cout << engine.get_total_time()<< ": " << rocket.report_location() << " " << rocket.report_velocity() << endl;
        double time_step = engine.step_time();
        Vec3 gravity = engine.get_gravitational_acceleration(rocket);//this is in m/s
        gravity.x /= simulation_hz;//m/s -> m/ms
        gravity.y /= simulation_hz;//m/s -> m/ms
        gravity.z /= simulation_hz;//m/s -> m/ms
        Vec3 thrust = Vec3(0.001,0.002,0); //simulate thrust up and to the right
        Vec3 total_force = Vec3(0,0,0);
        total_force += gravity; 
        total_force += thrust;
        engine.apply_acceleration_to_velocity(total_force, rocket);
        engine.apply_velocity_to_position(time_step, rocket);
    }
}