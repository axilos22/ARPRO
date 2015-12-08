#ifndef CBINARYSENSOR_H
#define CBINARYSENSOR_H
#include "isensor.h"

class CBinarySensor: public ISensor {
    bool m_state;
public:
    CBinarySensor();
    void setState(bool i_state);
    bool isActive();
    std::string show() const;
    ~CBinarySensor();
    bool operator || (CBinarySensor& _b);
    bool operator && (CBinarySensor& _b);
    CBinarySensor operator = (const CBinarySensor& _b);
    friend std::ostream& operator <<(std::ostream& _o,CBinarySensor& _b);    
};

#endif // CBINARYSENSOR_H
