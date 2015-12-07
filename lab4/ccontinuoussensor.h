#ifndef CCONTINUOUSSENSOR_H
#define CCONTINUOUSSENSOR_H
#include "shared.h"
#include "isensor.h"

class CContinuousSensor : public ISensor {
    bool m_isActive;
    float m_value,
    m_treshold;
public:
    CContinuousSensor(float i_treshold=.5);
    void setValue(float i_value);
    void setTreshold(float i_treshold);
    bool isActive();
    std::string show() const;
    ~CContinuousSensor();
    bool operator || (CContinuousSensor& _c);
    bool operator && (CContinuousSensor& _c);
    CContinuousSensor operator = (const CContinuousSensor& _c);
    friend std::ostream& operator <<(std::ostream& _o,CContinuousSensor& _c);
};

#endif // CCONTINUOUSSENSOR_H
