#ifndef Complex_h
#define Complex_h
#include <fstream>


using namespace std;


class Complex
{
    
public:
    
    Complex();
    Complex(double r, double im);
    Complex operator+ (const Complex& obj);
    Complex operator- (const Complex& obj);
    Complex operator* (const Complex& obj);
    Complex operator/ (const Complex& obj);
    double real;
    double imaginary;
    friend ostream& operator<< (ostream &out, const Complex &temp);

    
};


#endif /* Complex_h */
