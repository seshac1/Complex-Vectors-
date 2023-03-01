#include "Complex.h"
#include <iostream>
#include <fstream>

using namespace std;

// a Complex object has two components a real component and an imaginary component

Complex::Complex()
{
    real = 0.0;
    imaginary = 0.0;
}

Complex::Complex(double myreal, double myimaginary)
{
    real = myreal;
    imaginary = myimaginary;
}

Complex Complex::operator+(Complex const& obj)
{
    return Complex(real + obj.real, imaginary + obj.imaginary);
}

Complex Complex::operator-(Complex const& obj)
{
    return Complex(real - obj.real, imaginary - obj.imaginary);
}

Complex Complex::operator*(Complex const& obj)
{
    //(a + bi)(c + di) = (ac −bd) + (bc + ad)i
   
    double ac = real * obj.real;
    double bd = imaginary * obj.imaginary;
    double bc = imaginary * obj.real;
    double ad = real * obj.imaginary;
    
    double rpart = ac - bd;
    double ipart = bc + ad;
    
    return Complex(rpart, ipart);
}

Complex Complex::operator/(Complex const& obj)
{
    //(a+bi)/(c+di) = ((ac + bd)/(c^2 + d^2)) + ((bc - ad)/(c^2 + d^2))i
    
    double ac = real * obj.real;
    double bd = imaginary * obj.imaginary;
    double bc = imaginary * obj.real;
    double ad = real * obj.imaginary;

    double c = obj.real;
    double d = obj.imaginary;
    
    double rpart = (ac + bd) / (c*c + d*d);
    double ipart = (bc - ad) / (c*c + d*d);
    
    return Complex(rpart, ipart);
}
