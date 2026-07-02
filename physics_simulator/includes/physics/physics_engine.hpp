#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

#include <vector>
#include "physics/rigid_body.hpp"

using namespace std;
class PhysicsEngine{
    private:
        int update_frequency_hz = 0;
        double time_step = 1.0/update_frequency_hz;
        double total_time_s_ = 0.0;
        char log_buffer[256];
    public:
        PhysicsEngine(int update_frequency_hz) : update_frequency_hz (update_frequency_hz){}
        
        double total_time_s() const {return total_time_s_;}
        
        // for now just make -9.8m/s to y, can refactor later if needed
        Vec3 get_gravitational_acceleration(RigidBody &object){ return Vec3(0.0, -9.8, 0.0); }
        
        void apply_acceleration_to_velocity_linear(Vec3 acceleration,  RigidBody &object){ object.update_velocity(acceleration, time_step); }

        void apply_velocity_to_position(RigidBody &object){ object.update_position(time_step); }
        
        void step_time(){ total_time_s_ += time_step;}

};
#endif