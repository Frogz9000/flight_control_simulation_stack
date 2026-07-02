#ifndef LOGGER_H
#define LOGGER_H

#include <cstdio>
#include <string>
#include <iostream>
#include <ostream>

#include "math/vec3.hpp"
class Logger{
private:
    char log_buffer[256];
    bool verbose_;
public:
    //verbose bool for now, in future have diagnotics level or report flags
    Logger(bool verbose=false):verbose_(verbose){}
    void print_time_position_velocity(double total_time, const Vec3& position, const Vec3& velocity){
        snprintf(log_buffer, sizeof(log_buffer), "%.4f | X: %.4f Y: %.4f Z: %.4f | VX: %.4f VY: %.4f VZ: %.4f ",total_time, position.x, position.y, position.z, velocity.x, velocity.y, velocity.z);
        std::cout << log_buffer << std::endl;
    }

    //eventually have this move to indidual logs for each object and the above function will instead
    //be a log phsics step that calls each sub function
};


#endif