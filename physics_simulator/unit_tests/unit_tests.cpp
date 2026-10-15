#include "physics_tests/constant_acceleration_test.cpp"
#include "unit_tests.hpp"
bool run_all_tests(){
    bool success = true;
    success &= test_constant_acceleration();
    return success;
}
