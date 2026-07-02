#ifndef ROTOR_H
#define ROTOR_H

#include "math/vec3.hpp"
#include "physics/spin_direction.hpp"


class Rotor{
private:
    Vec3 positional_offset_;    
    double rotational_freq_;
    enum SpinDirection spin_direction_;

public:
    Rotor(Vec3 offset = {0,0,0}, double rotational_freq = 0.0, enum SpinDirection direction = CW): 
    positional_offset_(offset), rotational_freq_(rotational_freq), spin_direction_(direction){}
    
    const Vec3& positional_offset() const {return positional_offset_;}
    const double& rotational_freq() const {return rotational_freq_;}
    const SpinDirection& spin_direction() const {return spin_direction_;}

    void set_positional_offset(Vec3 positional_offset){ positional_offset_ = positional_offset; }
    void set_rotational_freq(double rotational_freq){ rotational_freq_ = rotational_freq; }
    void set_rotational_direction(enum SpinDirection direction){ spin_direction_ = direction;};
};

#endif