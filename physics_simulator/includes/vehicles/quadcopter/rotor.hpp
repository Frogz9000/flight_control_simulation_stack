#ifndef ROTOR_H
#define ROTOR_H

#include "math/vec3.hpp"
#include "physics/spin_direction.hpp"


class Rotor{
private:
    Vec3 offset_;    
    double RPM_;
    enum SpinDirection spin_direction_;

public:
    Rotor(Vec3 offset = {}, double RPM = 0.0, enum SpinDirection direction = CW): 
    offset_(offset), RPM_(RPM), spin_direction_(direction){}

    const Vec3& offset() const {return offset_;}
    const double& RPM() const {return RPM_;}
    const SpinDirection& spin_direction() const {return spin_direction_;}

    void set_positional_offset(Vec3 offset){ offset_ = offset; }
    void set_RPM(double RPM){ RPM_ = RPM; }
    void set_spin_direction(enum SpinDirection direction){ spin_direction_ = direction;}

    Vec3 get_current_force();
};

#endif