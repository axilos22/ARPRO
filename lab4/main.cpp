#include "shared.h"
using namespace std;
#include "isensor.h"
#include "cbinarysensor.h"
#include "ccontinuoussensor.h"
#include "ccamerasensor.h"

int main()
{
    srand(time(NULL));
    double thres = .5;

    CBinarySensor b1, b2;
    CContinuousSensor c1(thres), c2(thres);

    //Assigning the value randomly
    b1.setState(rand()%2);
    b2.setState(rand()%2);
    c1.setValue((float) rand()/(float)RAND_MAX);
    c2.setValue((float) rand()/(float)RAND_MAX);

    cout <<"### Sensor values ### "<<endl;

    cout << "Bin sensors " << b1 << ", " << b2 << endl;
    cout << "Cont. sensors " << c1 << ", " << c2 << endl;

    cout << "### logical operations ###" << endl;
    cout << "b1 && b2 " << std::boolalpha << (b1&&b2) << endl;
    cout << "b1 || b2 " << std::boolalpha << (b1||b2) << endl;

    cout << "c1 && c2 " << std::boolalpha << (c1&&c2) << endl;
    cout << "c1 || c2 " << std::boolalpha << (c1||c2) << endl;

    cout <<"### Camera sensor ### "<<endl;

    CCameraSensor cs;
    cs.fillRandomly();
    cout << cs << endl;
    cout << "Is an object present ? " << std::boolalpha << cs.isObjectPresent()<< endl;
    return 0;
}

