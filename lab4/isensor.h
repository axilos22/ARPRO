#ifndef ISENSOR_H
#define ISENSOR_H
#include "shared.h"

class ISensor {
public:
    virtual bool isActive() = 0;
    virtual std::string show() const = 0;
    virtual ~ISensor(){}
};

#endif // ISENSOR_H
