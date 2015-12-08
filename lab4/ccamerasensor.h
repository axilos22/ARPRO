#ifndef CCAMERASENSOR_H
#define CCAMERASENSOR_H
#define DEFAULT_SIZE 8
#define OBJECT_PRESENT_VALUE 12
#include "isensor.h"
#include "shared.h"

class CCameraSensor : public ISensor
{
    int m_size;
    bool **m_matrix;
public:    
    CCameraSensor();    
    bool isActive();
    std::string show() const;
    ~CCameraSensor();
    bool isObjectPresent();
    void fillRandomly();
    friend std::ostream& operator <<(std::ostream& _o,CCameraSensor& _cs);
};

#endif // CCAMERASENSOR_H
