#ifndef CCAMERASENSOR_H
#define CCAMERASENSOR_H
#define DEFAULT_SIZE 8
#include "isensor.h"
#include "shared.h"

class CCameraSensor : public ISensor
{
    bool m_isActive;
    int m_size;
    bool **m_matrix;
public:    
    CCameraSensor();
    bool isActive();
    std::string show() const;
    ~CCameraSensor();
    bool isObjectPresent();
    void fillRandomly();
};

#endif // CCAMERASENSOR_H
