#ifndef PHYSICS_OBJECT_H
#define PHYSICS_OBJECT_H

#include "physics/transform.hpp"

class physics_object
{
    private:
        transform _transform;

    public:
        physics_object(transform transform): _transform(transform){};
        void translate(double new_x, double new_y, double new_z);
        //should have a rotate func as well probably

        //apply change in time to position and velocity
        void update_time(double dt);
};


#endif