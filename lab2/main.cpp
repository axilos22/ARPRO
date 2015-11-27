#include <iostream>
#include <cstdio>
#include <math.h>

#include <boost/date_time/posix_time/posix_time_types.hpp>

namespace localTimeNs = boost::posix_time;

typedef localTimeNs::ptime mTime;

using namespace std;

void functionA() {
    boost::posix_time::ptime t1 =
            boost::posix_time::microsec_clock::local_time();
    // ... do some processing here
    boost::posix_time::ptime t2 =
            boost::posix_time::microsec_clock::local_time();
    boost::posix_time::time_duration d = t2-t1;
    long timeInMillis = d.total_milliseconds();
    cout << "time passed: " <<timeInMillis << endl;
}

int main()
{
    functionA();
    return 0;
}
