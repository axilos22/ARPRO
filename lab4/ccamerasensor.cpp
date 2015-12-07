#include "ccamerasensor.h"

CCameraSensor::CCameraSensor() :
    m_isActive(false)
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

bool CCameraSensor::isActive()
{
    return m_isActive;
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
    return (truePixelNb>12);
}

void CCameraSensor::fillRandomly()
{
    for(int i=0;i<m_size;i++) {
        for(int j=0;j<m_size;j++) {
            m_matrix[i][j] = rand()%2;
        }
    }
}
