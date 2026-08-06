#ifndef ROTOR_H
#define ROTOR_H

#include "math/vec3.hpp"
#include "physics/spin_direction.hpp"


class Propeller{
private:
    Vec3 _offset;    
    double _RPM;
    double _lift_coeff;
    double _drag_coeff;
    enum SpinDirection _spin_direction;

    //to add later:
    ////double area_;

public:
    Propeller(Vec3 offset = {}, double RPM = 0.0, enum SpinDirection direction = SpinDirection::CW, double lift_coeff = 1.0, double drag_coeff = 1.0): 
    _offset(offset), _RPM(RPM), _spin_direction(direction), _lift_coeff(lift_coeff), _drag_coeff(drag_coeff){}

    const Vec3& offset() const {return _offset;}
    const double RPM() const {return _RPM;}
    const SpinDirection spin_direction() const {return _spin_direction;}

    void set_positional_offset(Vec3& offset){ _offset = offset; }
    void set_RPM(double RPM){ _RPM = RPM; }
    void set_spin_direction(enum SpinDirection direction){ _spin_direction = direction;}
};

#endif