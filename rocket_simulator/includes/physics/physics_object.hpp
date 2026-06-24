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
        void set_position(double x, double y, double z);
        void set_velocity(double x, double y, double z);
        void translate(double delta_x, double delta_y, double delta_z);
        void accelerate(double delta_x, double delta_y, double delta_z);
        double mass() const {return _mass_kg;}
        void apply_linear_velocity(double dt);
        std::string report_location(void);
    };


#endif