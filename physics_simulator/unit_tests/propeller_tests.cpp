#include "vehicles/components/propeller.hpp"
#include <iostream>
#include <ostream>


bool test_thrust(){
    Propeller test_prop = {};
    test_prop.set_RPM(10.0);
    double down_thrust = test_prop.get_thrust();
    test_prop.set_spin_direction(SpinDirection::CCW);
    double up_thrust =  test_prop.get_thrust();

    std::cout << "upward thrust: " << up_thrust << " downward thrust: " << down_thrust << std::endl;

    return (down_thrust == (-1.0 * 10.0 * 10.0) && up_thrust == (10.0 * 10.0));
}
