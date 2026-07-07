#include "physics/physics_engine.hpp"
#include "physics/rigid_body.hpp"
#include <iostream>
#include <ostream>

bool test_constant_acceleration(){
    int simulation_hz = 1000;
    int simulation_length = 60;
    PhysicsEngine engine = PhysicsEngine(1000);
    RigidBody test_object = RigidBody();
    Vec3 total_force = {10,0,0};
    for (int i = 0; i<=(simulation_hz * simulation_length); i++){
        engine.step_time();
        engine.apply_acceleration_to_velocity_linear(total_force, test_object);
        engine.apply_velocity_to_position(test_object);
    }
    double predicted_final_position = 0.5 * total_force.x * simulation_length * simulation_length;//s = ut + 1/2*a*t^2
    double predicted_final_velocity = total_force.x * simulation_length;//v = at
    
    if (predicted_final_position != test_object.position().x || predicted_final_velocity != test_object.linear_velocity().x){
        std::cout << "Final Position Expected: "  << predicted_final_position <<" Got: " << test_object.position().x << std::endl;
        std::cout << "Final Velocity Expected: "  << predicted_final_velocity <<" Got: " << test_object.linear_velocity().x << std::endl;
        return false;
    }

    std::cout << "Constant Acceleration Test Passed" << std::endl;
    return true;
}