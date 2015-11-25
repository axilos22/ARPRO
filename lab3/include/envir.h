#ifndef ENVIR_H
#define ENVIR_H

#include <vector>

namespace arpro
{

struct Point
{
    double x;
    double y;
};

struct Environment
{
    std::vector<Point> walls;
};

}

#endif // ENVIR_H
