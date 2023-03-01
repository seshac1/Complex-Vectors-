#ifndef ComplexVector_h
#define ComplexVector_h
#include "Complex.h"
#include <fstream>
#include <vector>

using namespace std;

class ComplexVector {

public:
    
    ComplexVector(int len);
    void setComplexVector(int i, const Complex& temp, const ComplexVector& temp1);
    ComplexVector(int length, vector <double> &rvec, vector <double> &ivec);
    ComplexVector operator+(const ComplexVector& temp);
    ComplexVector operator-(const ComplexVector& temp);
    ComplexVector operator*(const ComplexVector& temp);
    ComplexVector operator/(const ComplexVector& temp);
    friend ostream& operator<< (ostream &out, const ComplexVector &temp);
    
    Complex* obj;
    vector <double> real;
    vector <double> imag;
    int length;

    
};

#endif /* ComplexVector_h */

