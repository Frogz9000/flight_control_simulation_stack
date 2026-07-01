#ifndef RIGID_BODY_H
#define RIGID_BODY_H

#include "math/vec3.hpp"
#include "math/quaternion.hpp"
#include <string>

class RigidBody
{
    private:
        Vec3 position_;
        Quaternion attitude_;
        Vec3 linear_velocity_;
        Vec3 angular_velocity_;
        //mass
        //inertia tensor (moment of interia)

        char log_buffer[256];

    public:
        RigidBody(Vec3 position = {0,0,0},  Quaternion attitude = {0,0,0,0}, Vec3 linear_velocity = {0,0,0}, Vec3 angular_velocity = {0,0,0}): 
        position_ (position), attitude_ (attitude), linear_velocity_ (linear_velocity), angular_velocity_ (angular_velocity) {};
        
        void set_position(Vec3 position){ position_ = position; }
        void set_attitude(Quaternion attitude){ attitude_ = attitude; }
        void set_linear_velocity(Vec3 velocity) { linear_velocity_ = velocity; };
        void set_angular_velocity(Vec3 velocity) { angular_velocity_ = velocity; };

        const Vec3& position() const {return position_;}
        const Quaternion& attitude() const {return attitude_;}
        const Vec3& linear_velocity() const { return linear_velocity_; }
        const Vec3& angular_velocity() const { return angular_velocity_; }

        std::string report_location();
        std::string report_velocity();


        void update_velocity(Vec3 acceleration, double dt);
        void update_position(double dt);

    };
#endif