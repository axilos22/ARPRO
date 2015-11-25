#ifndef SENSOR_RANGE_H
#define SENSOR_RANGE_H

#include <cstdio>
#include "sensor.h"

namespace arpro
{

class SensorRange : public Sensor
{
public:
    SensorRange(const double &_x, const double &_y, const double &_theta, const std::string &_name);
    void Update(const Robot &_robot, const Environment &_envir);
};
}

#endif // SENSOR_RANGE_H
