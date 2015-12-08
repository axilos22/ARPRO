#include "ccamerasensor.h"

CCameraSensor::CCameraSensor()
{
    m_size = DEFAULT_SIZE;
    m_matrix = new bool*[m_size];
    for(int i=0;i<m_size;i++) {
        m_matrix[i] = new bool[m_size];
    }
    for(int i=0;i<m_size;i++) {
        for(int j=0;j<m_size;j++) {
            m_matrix[i][j] = false;
        }
    }
}
/**
 * @brief CCameraSensor::isActive Here we consider that if all the pixels of the camera are false it is deactivated.
 * only problem with this implementation, we cannot differentiate if the the camera is inactive or not detecting anything.
 * Solution would be that isActive won't be pure virtual and the mother class would handle activation fo all daughters.
 * @return boolean telling of sensor is active or not.
 */
bool CCameraSensor::isActive()
{
    bool allFalse = true;
    for(int i=0;i<m_size;i++) {
        for(int j=0;j<m_size;j++) {
            if(m_matrix[i][j]!=false) {
                allFalse = false;
            }
        }
    }
    return allFalse;
}

std::string CCameraSensor::show() const
{
    std::string output;
    for(int i=0;i<m_size;i++) {
        for(int j=0;j<m_size;j++) {
            if(m_matrix[i][j]) {
                output+="|1";
            }else {
                output+="|0";
            }
        }
        output+="\n";
    }
    return output;
}

CCameraSensor::~CCameraSensor()
{
    for(int i=0;i<m_size;i++) {
        delete [] m_matrix[i];
    }
    delete m_matrix;

}

bool CCameraSensor::isObjectPresent()
{
    int truePixelNb = 0;
    for(int i=0;i<m_size;i++) {
        for(int j=0;j<m_size;j++) {
            if(m_matrix[i][j]) {
                truePixelNb++;
            }
        }
    }
    return (truePixelNb>OBJECT_PRESENT_VALUE);
}

void CCameraSensor::fillRandomly()
{
    for(int i=0;i<m_size;i++) {
        for(int j=0;j<m_size;j++) {
            m_matrix[i][j] = rand()%2;
        }
    }
}

std::ostream& operator <<(std::ostream &_o, CCameraSensor &_cs)
{
    _o << _cs.show();
    return _o;
}
