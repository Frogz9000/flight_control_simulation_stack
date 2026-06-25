#include <cstdlib>
#include <iostream>
#include <ostream>
#include "physics/physics_engine.hpp"
#include "physics/physics_transform.hpp"
#include <getopt.h>

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
        {0,0,0,0},
    };
    int index;
    int iarg=0;

    //turn off getopt error message
    opterr=1; 

    int simulation_hz = 1000;
    int simulation_duration_seconds = 60;

    while(iarg != -1){
        iarg = getopt_long(argc, argv, "s:t:h", longopts, &index);

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

        case 'h':
            std::cout << "(s)im_(speed)_hz simulation tick speed in hz" << std::endl;
            std::cout << "(s)im_(speed)_hz simulation tick speed in hz" << std::endl;
            std::cout << "((t)ime)_to_run number of seconds to simulate" << std::endl;
            std::cout << "exmaple: './ROCKET_SIM -speed 1000 -time 60' runs simulation at 1000hz for 60s" << std::endl;
            break;
        }
    }


    physics_object rocket = physics_object(physics_transform(Vec3(0,0,0),Vec3(0,0,0),Quaternion(0,0,0,0),Vec3(0,0,0)), 1000);
    rocket.set_position(Vec3(10, 0, 0));
    physics_engine engine = physics_engine(simulation_hz);//1ms ticks

    for (int i = 0; i<=(simulation_hz * simulation_duration_seconds); i++){
        cout << engine.get_total_time()<< ": " << rocket.report_location() << " " << rocket.report_velocity() << endl;
        double time_step = engine.step_time();
        Vec3 total_force = engine.get_gravitational_acceleration(rocket) + Vec3(1,10,0);//this is in m/s
        total_force.x /= simulation_hz;//m/s -> m/ms
        total_force.y /= simulation_hz;//m/s -> m/ms
        total_force.z /= simulation_hz;//m/s -> m/ms
        
        engine.apply_acceleration_to_velocity(total_force, rocket);
        engine.apply_velocity_to_position(time_step, rocket);
    }
}