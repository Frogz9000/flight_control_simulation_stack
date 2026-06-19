#ifndef ROCKET_H
#define ROCKET_H
#include "physics/rocket_transform.hpp"

class rocket
{
    private:
        rocket_transform _transform;

    public:
        void translate(double new_x, double new_y, double new_z);
        
        //may need to refactor once solid idea of timescale unit to process at
        //as well as applying rotational velocity
        void update(double time_seconds);
};
#endif