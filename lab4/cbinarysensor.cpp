#include "cbinarysensor.h"

CBinarySensor::CBinarySensor()
{}

void CBinarySensor::setState(bool i_state)
{
    m_state = i_state;
}
/**
 * @brief CBinarySensor::isActive tells of the sensor is active or not. However we now can't distinguish of the sensor is false
 * or deactivated. Better implementation: not a pure virtual isActive().
 * @return bool if the sensor is active or not.
 */
bool CBinarySensor::isActive()
{
    return m_state;
}

std::string CBinarySensor::show() const
{
    if(m_state) {
        return "Online";
    } else {
        return "Offline";
    }
}

CBinarySensor::~CBinarySensor()
{}

bool CBinarySensor::operator ||(CBinarySensor &_b)
{
    return (m_state||_b.m_state);
}

bool CBinarySensor::operator &&(CBinarySensor &_b)
{
    return (m_state&&_b.m_state);
}

CBinarySensor CBinarySensor::operator =(const CBinarySensor &_b)
{
    this->m_state = _b.m_state;
    return *this;
}

std::ostream& operator <<(std::ostream &_o, CBinarySensor &_b)
{
    _o << _b.show();
    return _o;
}
