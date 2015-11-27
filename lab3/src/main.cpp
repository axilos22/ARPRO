#include <iostream>
#include <math.h>
#include <cmath>

#include <robot.h>

// default environment and motions
#include <defaults.h>

#include <sensor_range.h>

using namespace std;
using namespace arpro;

double roundMinToRadSec(double rpm) {
    return rpm/((2.0*M_PI)*60);
}

int main()
{    
    // init robot at (0,0,0)
    Robot robot(0,0,0);
    //init sensor
    SensorRange sensorForRange(.1,0,0,"s1");
    robot.InitWheel(.05,.3,roundMinToRadSec(80));
    // set sampling time
    robot.SetSamplingTime(.01);

    // init environment
    Environment envir = DefaultEnvironment();

    /* move robot with:
    - (vx, vy, omega) (Cartesian)
    - or (v, omega) (local frame)
    - or (omega_left, omega_right) (wheel velocities)
    */
    double vx, vy, v, omega_left, omega_right, omega;    
    for(unsigned int i=0;i<10000;++i)
    {        
        sensorForRange.Update(robot,envir);
        // use cartesian setpoint
        /*DefautCartesianSetPoint sets the variables vx,vy,omega to a default value by reference
         * (i.e. we provied their address and the function changes the inner value).
         * it does not use i parameter for now. The i parameter cannot be modified because it is a const.
         * The vx paramter can be modified from main since we're providing their adress.
         */
        DefaultCartesianSetpoint(i, vx, vy, omega);

        // use robot frame velocity
        DefaultVelocitySetpoint(i, v, omega);
        robot.MoveVW2(v, omega);

        // use wheels
        DefaultWheelSetpoint(i, omega_left, omega_right);
        //robot.RotateWheels(omega_left, omega_right);

    }

    // plot trajectory
    robot.PlotTraj(envir);
    sensorForRange.Plot();
}
