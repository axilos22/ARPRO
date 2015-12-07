#include "ccontinuoussensor.h"

CContinuousSensor::CContinuousSensor(float i_treshold)
{
    setTreshold(i_treshold);
}

void CContinuousSensor::setValue(float i_value)
{
    if(i_value>0&&i_value<1) {
        m_value = i_value;
    } else {
        std::cout << "Out of range value provided v=" << i_value << std::endl;
    }
}

void CContinuousSensor::setTreshold(float i_treshold)
{
    m_treshold = i_treshold;
}

bool CContinuousSensor::isActive()
{
    return m_isActive;
}

std::string CContinuousSensor::show() const
{
    std::stringstream ssVal,ssTresh;
    ssVal << m_value;
    ssTresh << m_treshold;
    std::string strVal = ssVal.str(), strTreshold = ssTresh.str();
    return "val= "+strVal+"; Tresh= "+strTreshold;
}

CContinuousSensor::~CContinuousSensor(){
//    delete &m_value,&m_treshold,&m_isActive;
}

bool CContinuousSensor::operator ||(CContinuousSensor &_c)
{
    return ((m_value<m_treshold)||(_c.m_value<_c.m_treshold));
}

bool CContinuousSensor::operator &&(CContinuousSensor &_c)
{
    return ((m_value<m_treshold)&&(_c.m_value<_c.m_treshold));
}

CContinuousSensor CContinuousSensor::operator =(const CContinuousSensor &_c)
{
    m_value = _c.m_value;
    m_treshold = _c.m_treshold;
    m_isActive = _c.m_isActive;
    return *this;
}
/**
  * We have to declare this function out the the scope of CContinuousSensor because in this scope the argument
  * provided is implicit (one CContinuousSensor object, referenced by "this" keyword). As we want to be able
  * to provide an object to this operator, we declare it out of the scope. The other problem is, as this function is out of the
  * scope, it won't be able to see our object functions and attribute. This is why we added the "friend" keyword, which allow
  * a function to access all private/protected element of our object (here it is the show function).
  */
//out of class
std::ostream& operator <<(std::ostream &_o, CContinuousSensor &_c)
{
    _o << _c.show();
    return _o;
}
