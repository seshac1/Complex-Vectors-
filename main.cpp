/*
 
 Description:
 
 Author: Sesha Chalamalasetti
 
 Date: 3/2/2022
 
 */

#include "Complex.h"
#include "ComplexVector.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


void recursive_function(ComplexVector &vec,Complex first,int n)
{
    if (n > 6)
    {
        return;
    }
    
 vec.obj[n-1]=first;
 Complex num = Complex(2*n,3*n);
 Complex denom = Complex(7,5*n*n);
 Complex end = (num/denom) * first;
 recursive_function(vec,end,n+1);
}



int main() {
    
    vector <double> v1real = {2.0, 3.0, -1.0, 8.0};
    vector <double> v1imag  = {4.0, 5.0, -3.0, 10.0};
    
    vector <double> v2real = {-10.0, 4.0, 2.0, 10.0};
    vector <double> v2imag = {3.5, 7.3, -8.0, -142.0};
    
    
    ComplexVector v1 (4, v1real, v1imag);
    ComplexVector v2 (4, v2real, v2imag);
    
    
    cout << right << setw(5) << fixed;
    
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    cout << "v1 + v2 = " << v1 + v2 << endl;
    cout << "v1 - v2 = " << v1 - v2 << endl;
    cout << "v1 * v2 = " << v1 * v2 << endl;
    cout << "v1 / v2 = " << v1 / v2 << endl;
    
    ComplexVector f = ComplexVector(6);
    Complex first = Complex(1,1);
    recursive_function(f,first,1);
    ofstream file;
    file.open("ComplexSequence.txt");
    file << f << endl;
    file.close();
    
}

