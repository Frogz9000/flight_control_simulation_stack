#include <cstdlib>
#include <iostream>
#include <ostream>
#include <getopt.h>

#include "physics/physics_engine.hpp"
#include "vehicles/quadcopter/quadcopter.hpp"
#include "logger.hpp"
#include "unit_tests.hpp"

#define no_argument 0
#define required_argument 1 
#define optional_argument 2

int main(int argc, char *argv[]){
    const struct option longopts[] = {
        {"sim_speed_hz", required_argument, 0, 's'},
        {"speed",        required_argument, 0, 's'},
        {"time_to_run",  required_argument, 0, 't'},
        {"time",         required_argument, 0, 't'},
        {"help",         no_argument      , 0, 'h'},
        {"verbose",      no_argument      , 0, 'v'},
        {"test_bench",   no_argument      , 0, 'b'},
        {0,0,0,0},
    };
    int index;
    int iarg=0;

    //turn off getopt error message
    opterr=1; 

    int simulation_hz = 1000;
    int simulation_duration_seconds = 60;
    bool verbose = false;
    bool test_bench = false;
    while(iarg != -1){
        iarg = getopt_long(argc, argv, "s:t:hv", longopts, &index);

        switch (iarg)
        {
        case 's':
            simulation_hz = atoi(optarg);
            std::cout << "Speed: " << simulation_hz << "hz" << std::endl;
            break;

        case 't':
            simulation_duration_seconds = atoi(optarg);
            std::cout << "Time: " << simulation_duration_seconds << "s" << std::endl;
            break;

        case 'v':
            verbose = true;
            break;

        case 'b':
            test_bench = true;
            break;

        case 'h':
            std::cout << "(s)im_(speed)_hz simulation tick speed in hz" << std::endl;
            std::cout << "((t)ime)_to_run number of seconds to simulate" << std::endl;
            std::cout << "(v)erbose output log" << std::endl;
            std::cout << "exmaple: './ROCKET_SIM -speed 1000 -time 60' runs simulation at 1000hz for 60s" << std::endl;
            return 0;
        }
    }
    
    if (test_bench){
        //return run_all_tests();
    }

    PhysicsEngine engine = PhysicsEngine(simulation_hz);
    Quadcopter test_object = Quadcopter(RigidBody(), Propellers());
    Logger log = Logger(verbose);
    for (int i = 0; i<=(simulation_hz * simulation_duration_seconds); i++){
        log.print_time_position_velocity(engine.total_time_s(),test_object.rigid_body().position(), test_object.rigid_body().linear_velocity());
        engine.step_time();
        Vec3 total_force = engine.get_gravitational_acceleration(test_object.rigid_body());//this is in m/s
        total_force += test_object.get_force_from_current_state();
        engine.semi_euler_integrate(total_force, test_object.rigid_body());
    }
    return 0;
}
