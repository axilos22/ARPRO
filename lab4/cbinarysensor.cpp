#include "cbinarysensor.h"

CBinarySensor::CBinarySensor(bool i_state)
{
    setState(i_state);
}

void CBinarySensor::setState(bool i_state)
{
    m_state = i_state;
}

bool CBinarySensor::isActive()
{
    return m_isActive;
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
{
//    delete &m_isActive;
}

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
