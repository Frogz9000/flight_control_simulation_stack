#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

#include <string>
#include <vector>
#include "physics/rigid_body.hpp"
using namespace std;
class physics_engine{
    private:
        int update_frequency_hz = 0;
        double time_step = 1.0/update_frequency_hz;
        double _total_time_s = 0.0;
        char log_buffer[256];
    public:
        physics_engine(int update_frequency_hz) : update_frequency_hz (update_frequency_hz){}
        
        double total_time_s() const {return _total_time_s;}

        Vec3 get_gravitational_acceleration(RigidBody &object);

        void apply_acceleration_to_velocity_linear(Vec3 acceleration,  RigidBody &object);

        void apply_velocity_to_position(RigidBody &object);

        void step_time();

        std::string print_total_time();
};
#endif