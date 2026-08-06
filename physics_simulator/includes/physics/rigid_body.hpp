#ifndef RIGID_BODY_H
#define RIGID_BODY_H

#include "math/vec3.hpp"
#include "math/quaternion.hpp"
#include "frame.hpp"
#include <string>

class RigidBody
{
    private:
        Frame _body_frame;
        Vec3 _linear_velocity;
        Vec3 _angular_velocity;
        double _mass;
        //inertia tensor (moment of interia)

    public:
        RigidBody(Vec3 position = {},  Quaternion attitude = {}, Vec3 linear_velocity = {}, Vec3 angular_velocity = {}, double mass = 0.0): 
        _body_frame(Frame(position, attitude)), _linear_velocity (linear_velocity), _angular_velocity (angular_velocity), _mass(mass) {};
        
        void set_position(Vec3 position){ _body_frame.position() = position; }
        void set_attitude(Quaternion attitude){ _body_frame.attitude() = attitude; }
        void set_linear_velocity(Vec3 velocity) { _linear_velocity = velocity; }
        void set_angular_velocity(Vec3 velocity) { _angular_velocity = velocity; }
        //immutable accessors
        const Vec3& position() const { return _body_frame.position(); }
        const Quaternion& attitude() const { return _body_frame.attitude(); }
        const Vec3& linear_velocity() const { return _linear_velocity; }
        const Vec3& angular_velocity() const { return _angular_velocity; }
        const double mass() const { return _mass; }

        //mutable accessors
        Vec3& position() { return _body_frame.position(); }
        Quaternion& attitude() { return _body_frame.attitude(); }
        Vec3& linear_velocity() { return _linear_velocity; }
        Vec3& angular_velocity() { return _angular_velocity; }
        double mass() { return _mass; }
    };
#endif