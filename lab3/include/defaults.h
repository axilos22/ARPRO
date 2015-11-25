#ifndef DEFAULTS_H
#define DEFAULTS_H

#include <envir.h>

namespace arpro
{


// defines the default environment
arpro::Environment DefaultEnvironment()
{
    arpro::Environment envir;
    // 4 walls at +- 10 m
    envir.walls.resize(4);
    envir.walls[0].x = envir.walls[1].x = envir.walls[1].y = envir.walls[2].y = -10;
    envir.walls[2].x = envir.walls[3].x = envir.walls[0].y = envir.walls[3].y = 10;

    return envir;
}




// default trajectory in XY-Theta
void DefaultCartesianSetpoint(const unsigned int &_i, double &_vx, double &_vy, double &_omega)
{
    _vx = .1;
    _vy = 0;
    _omega = 0;
}


// default trajectory in local frame
void DefaultVelocitySetpoint(const unsigned int &_i, double &_v, double &_omega)
{
    _v = .4;
    _omega = .1 + .05*cos(_i/600.);
}


// default trajectory in wheel frame
void DefaultWheelSetpoint(const unsigned int &_i, double &_omega_left, double &_omega_right)
{
    _omega_left = 8 + 2*cos(_i/100.);
    _omega_right = 7;
}






}



#endif // DEFAULTS_H
