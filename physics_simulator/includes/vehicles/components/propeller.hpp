#ifndef ROTOR_H
#define ROTOR_H

#include "math/vec3.hpp"
#include "physics/spin_direction.hpp"


class Propeller{
private:
    Vec3 _offset;    
    double _RPM;
    double _thrust_coeff;
    enum SpinDirection _spin_direction;

    //to add later:
    //double _wing_area = 1.0;

public:
    Propeller(Vec3 offset = {}, double RPM = 0.0, enum SpinDirection direction = SpinDirection::CW, double thrust_coeff = 1.0): 
    _offset(offset), _RPM(RPM), _spin_direction(direction), _thrust_coeff(thrust_coeff){}

    const Vec3& offset() const { return _offset; }
    const double RPM() const { return _RPM; }
    const SpinDirection spin_direction() const { return _spin_direction; }
    
    void set_positional_offset(Vec3& offset){ _offset = offset; }
    void set_RPM(double RPM){ _RPM = RPM; }
    void set_spin_direction(enum SpinDirection direction){ _spin_direction = direction; }

    double get_thrust(){
		double orientation = (_spin_direction == SpinDirection::CW) ? -1.0 : 1.0;
		return  orientation *  _RPM * _RPM * _thrust_coeff; //T(w) = k w^2
    };

};

#endif
