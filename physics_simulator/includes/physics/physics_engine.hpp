#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

#include <string>
#include <vector>
#include "physics/physics_object.hpp"
using namespace std;
class physics_engine{
    private:
        int update_frequency_hz;
        double _total_time_s = 0.0;
        char log_buffer[256];
    public:
        physics_engine(int update_frequency_hz) : update_frequency_hz (update_frequency_hz){}
        void apply_forces_and_update(double dt, physics_object &object);
        
        double total_time_s() const {return _total_time_s;}

        Vec3 get_gravitational_acceleration(physics_object &object);

        void apply_acceleration_to_velocity(Vec3 acceleration,  physics_object &object);

        void apply_velocity_to_position(double dt, physics_object &object);

        double step_time();
        std::string get_total_time();
};
#endif