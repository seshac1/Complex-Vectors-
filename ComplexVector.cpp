#include "Complex.h"
#include "ComplexVector.h"
#include <fstream>
#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;

ComplexVector::ComplexVector(int len)
{
    length = len;
    obj = new Complex [length];
}

ComplexVector::ComplexVector(int len, vector <double> &rvec, vector <double> &ivec)
{
    length = len;
    real = rvec;
    imag = ivec;
    obj = new Complex [length];
    
    for (int i = 0; i < real.size(); i++)
    {
        obj[i] = Complex (rvec[i], ivec[i]);
    }
    
}

void ComplexVector::setComplexVector(int i, const Complex& temp, const ComplexVector& temp1)
{
    temp1.obj[i] = temp;
}

ComplexVector ComplexVector::operator+(const ComplexVector& temp)
{
    ComplexVector res = ComplexVector(length);
    
    for (int i = 0; i < length; i++)
    {
       res.obj[i] = obj[i] + temp.obj[i];
    }
    
    return res;
}

ComplexVector ComplexVector::operator-(const ComplexVector& temp)
{
    ComplexVector res = ComplexVector(length);
    
    for (int i = 0; i < length; i++)
    {
       res.obj[i] = obj[i] - temp.obj[i];
    }
    
    return res;
}


ComplexVector ComplexVector::operator*(const ComplexVector& temp)
{
    ComplexVector res = ComplexVector(length);
    
    for (int i = 0; i < length; i++)
    {
        res.obj[i] = obj[i] * temp.obj[i];
    }
    
    return res;
}

ComplexVector ComplexVector::operator/(const ComplexVector& temp)
{
    ComplexVector res = ComplexVector(length);
    
    for (int i = 0; i < length; i++)
    {
       res.obj[i] = obj[i] / temp.obj[i];
    }
    
    return res;
}


ostream& operator<< (ostream &out, const ComplexVector &temp)
{
    out << "{ ";
    
    for (int i = 0; i < temp.length; i++)
    {
        if (temp.obj[i].imaginary > 0)
        {
            out << setprecision(15) << setprecision(1) << fixed << temp.obj[i].real << " + " << temp.obj[i].imaginary << "i";
        }
        else
        {
            out << setprecision(15) << setprecision(1) << fixed << temp.obj[i].real << " - " << (-1 * temp.obj[i].imaginary) << "i";
        }
      
        if( i + 1 != temp.length)
        {
            out << " , ";
        }
    }
    
    out << " }";
    
    return out;
}

