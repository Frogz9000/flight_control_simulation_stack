#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

#include <vector>
#include "physics/rigid_body.hpp"

using namespace std;
class PhysicsEngine{
    private:
        int update_frequency_hz = 0;
        double time_step = 1.0/update_frequency_hz;
        double _total_time_s = 0.0;
        //world frame NED (North East Down)

        void update_velocity(RigidBody& rigid_body, Vec3 acceleration, double dt){
            rigid_body.linear_velocity().x += acceleration.x * dt;
            rigid_body.linear_velocity().y += acceleration.y * dt;
            rigid_body.linear_velocity().z += acceleration.z * dt;
        }
        
        void update_position(RigidBody& rigid_body, double dt){
            rigid_body.position().x += rigid_body.linear_velocity().x * dt;
            rigid_body.position().y += rigid_body.linear_velocity().y * dt;
            rigid_body.position().z += rigid_body.linear_velocity().z * dt;
        }

    public:
        PhysicsEngine(int update_frequency_hz) : update_frequency_hz (update_frequency_hz){}
        
        double total_time_s() const {return _total_time_s;}
        
        // for now just make -9.8m/s downward, move to environment class later
        // then have this take in arg of rigid body and environment to get gravity force
        Vec3 get_gravitational_acceleration(RigidBody &object){ return Vec3(0.0, 0.0, -9.8); }


        void semi_euler_integrate(Vec3 acceleration,  RigidBody &object){
            update_velocity(object, acceleration, time_step);
            update_position(object, time_step);
        };
        
        void step_time(){ _total_time_s += time_step; }

};
#endif