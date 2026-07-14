#ifndef ROTOR_H
#define ROTOR_H

#include "math/vec3.hpp"
#include "physics/spin_direction.hpp"


class Rotor{
private:
    Vec3 offset_;    
    double RPM_;
    double area_;
    double lift_coeff_;
    enum SpinDirection spin_direction_;

public:
    Rotor(Vec3 offset = {}, double RPM = 0.0, enum SpinDirection direction = SpinDirection::CW, double area = 1.0, double lift_coeff = 1.0): 
    offset_(offset), RPM_(RPM), spin_direction_(direction), lift_coeff_(lift_coeff), area_(area){}

    const Vec3& offset() const {return offset_;}
    const double& RPM() const {return RPM_;}
    const SpinDirection& spin_direction() const {return spin_direction_;}

    void set_positional_offset(Vec3 offset){ offset_ = offset; }
    void set_RPM(double RPM){ RPM_ = RPM; }
    void set_spin_direction(enum SpinDirection direction){ spin_direction_ = direction;}
    Vec3 get_lift();
    Vec3 get_drag();
    Vec3 get_thrust();
    Vec3 get_current_force();
};

#endif