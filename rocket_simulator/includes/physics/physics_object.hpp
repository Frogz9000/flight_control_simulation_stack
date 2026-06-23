#ifndef PHYSICS_OBJECT_H
#define PHYSICS_OBJECT_H

#include "physics/transform.hpp"

class physics_object
{
    private:
        transform _transform;
        double    _mass_kg;
    public:
        physics_object(transform transform, double mass_kg): _transform(transform), _mass_kg (mass_kg){};
        void translate(double new_x, double new_y, double new_z);
        double mass() const {return _mass_kg;}
        void apply_linear_acceleration(double dt);
};


#endif