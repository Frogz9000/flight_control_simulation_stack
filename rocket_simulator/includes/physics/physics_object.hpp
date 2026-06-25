#ifndef PHYSICS_OBJECT_H
#define PHYSICS_OBJECT_H

#include "physics/physics_transform.hpp"
#include <string>

class physics_object
{
    private:
        physics_transform _physics_transform;
        double    _mass_kg;
        char log_buffer[256];
    public:
        physics_object(physics_transform physics_transform, double mass_kg): _physics_transform(physics_transform), _mass_kg (mass_kg){};
        void set_position(Vec3 position);
        void set_velocity(Vec3 velocity);
        void translate(Vec3 delta_position);
        void accelerate(Vec3 delta_velocity);
        double mass() const {return _mass_kg;}
        void apply_linear_velocity(double dt);
        std::string report_location(void);
        std::string report_velocity();
    };


#endif