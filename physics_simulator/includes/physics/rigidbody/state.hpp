#ifndef STATE_H
#define STATE_H

#include "pose.hpp"
#include "linear_velocity.hpp"
#include "angular_velocity.hpp"
#include <string>

class State
{
    private:
        Pose pose_;
        LinearVelocity linear_velocity_;
        AngularVelocity angular_velocity_;
    public:
        State(Pose pose = {}, LinearVelocity linear_velocity = {}, AngularVelocity angular_velocity = {}): 
        pose_(pose), linear_velocity_ (linear_velocity), angular_velocity_ (angular_velocity) {};
        
        void set_pose(Pose pose) { pose_ = pose; };
        void set_linear_velocity(Vec3 velocity) { linear_velocity_ = velocity; };
        void set_angular_velocity(Vec3 velocity) { angular_velocity_ = velocity; };

        const Pose& pose() const { return pose_; }
        const LinearVelocity& linear_velocity() const { return linear_velocity_; }
        const AngularVelocity& angular_velocity() const { return angular_velocity_; }
    };


#endif