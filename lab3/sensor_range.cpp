#include <sensor_range.h>

using namespace arpro;

SensorRange::SensorRange(const double &_x, const double &_y, const double &_theta, const std::string &_name)
{
    this->Init(_x,_y,_theta,_name);
}

void SensorRange::Update(const Robot &_robot, const Environment &_envir) {
#if VERBOSE > 2
    printf("start @SensorRange::Update\n");
#endif
    double xR,yR,tR;
    double x,y,t;
    _robot.GetPosition(xR,yR,tR);
    //position of the sensor
    x = xR+x_*cos(tR)-y_*sin(tR);
    y = yR+x_*sin(tR)+y_*cos(tR);
    t = tR+theta_;
    //wall calculation
    double dMin;
    bool dMinInit = false;
    for(int wallRank=0; wallRank<_envir.walls.size();wallRank++) {
        Point currentPt=_envir.walls.at(wallRank),
            nextPt = _envir.walls.at((wallRank+1)%_envir.walls.size());
        double x1=currentPt.x, y1=currentPt.y, x2=nextPt.x, y2=nextPt.y,
                num=x1*y2-x1*y-x2*y1+x2*y+x*y1-x*y2,
                denom=x1*sin(t)-x2*sin(t)-y1*cos(t)+y2*cos(t);
        if(denom==0) {
            //dividing by zero. skip step
#if VERBOSE > 2
            printf("ZeroDiv\n");
#endif
            continue;
        } else {
            double d = num/denom;
            if(!dMinInit&&d>0) {
                dMin = d;
                dMinInit = true;
            }
            if(d<dMin&&d>0) {
                dMin = d;
            }
        }
    }
#if VERBOSE > 0
    printf("dMin=%f\n",dMin);
#endif
    s_ = dMin;
    //storing the dMin calculated
    s_history_.push_back(s_);
}
