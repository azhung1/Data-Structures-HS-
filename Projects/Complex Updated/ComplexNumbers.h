    /*
    Complex
    Allowing the user to perform various operations of Duration
    Albert Hung
    */
    #include <iostream>//importing the necessary preprocessor directives
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;//choosing a namespace so I don't have to type out std 
double x,y,val,x2,y2,addInput;//initializing all of the required variablese
int input;
bool rerun = true;
  #ifndef COMPLEXNUMBERS_H
    #define COMPLEXNUMBERS_H
class Complex
{
    private:
        double a, b;
        string out = "";//initializing output string 
    public:
    Complex(double real, double imaginary);
    Complex operator + (Complex& other);
    Complex operator - (Complex& other);
    Complex operator * (Complex& other);
    Complex operator / (Complex& other);
    bool operator == (Complex& other);
    Complex conjugate();
    double norm();
    double real();
    double imag();
    double dotProduct(Complex other);
    Complex scalarProduct(double value);
    double angleBetween(Complex other);
    operator const char*();
};
    Complex::Complex (double real, double imaginary)//constructor 
    {
        a = real;
        b = imaginary;
    }
    Complex Complex :: operator + (Complex& other)//addition operator to add two different complex numbers 
    {
        return Complex (real()+ other.real(), imag()+other.imag());//returning the new complex number after summing the components 
    }
     Complex Complex:: operator - (Complex& other)//subtraction operator to subtract the two different complex numbers 
    {
        return Complex(real()- other.real(), imag()-other.imag());//returning the new complex number after subtracting the individual components 
    }
    Complex Complex:: operator * (Complex& other)//multiplication operator to multiply two different complex numbers 
    {
        return Complex((real())*(other.real()) - (imag())*(other.imag()), imag()*other.real() + other.imag()*real());//returning the complex number after foiling 
    }
    Complex Complex:: operator / (Complex& other)//division operator to subtract the two different complex numbers 
    {
        Complex temp (other.conjugate().real(),other.conjugate().imag());//storing the conjugate of the denominator 
        Complex quotient (0,0);
        quotient = temp * *this;//multiplying the numberator by the conjugate 
        Complex denom = temp * other;//multiplying the denominator by the conjugate 
        return Complex(quotient.real()/denom.real(), quotient.imag() / denom.real());//dividing the complex numerator by the denomiator and returning the complex number 
    }
    bool Complex:: operator == (Complex& other)//equality operator 
    {
        return ((other - *this).norm()<= 0.0001);//returning a boolean if the the two complex numbers are the same  
    }
    Complex Complex:: conjugate()//returning the conjugate of the complex number 
    {
        return Complex (real(),-1*(imag()));//returning the complex number after changing the sign of the imaginary portion of the number 
    }
    double Complex:: norm()//returning the norm of the complex number, which is the magnitude of the vector 
    {
        double tempA, tempB;
        tempA = pow (a,2);//squaring the magnitude real components 
        tempB = pow (b,2);//squaring the magnitude imaginary components
        return sqrt(tempA +tempB);//returning the squareroot of the sum of the magnitude of the squares 
    }   
    double Complex:: real()//returns the real portion of the complex number 
    {
        return a;
    }
    double Complex:: imag()//returns the imaginary portion of the complex number 
    {
        return b;
    }
    double Complex:: dotProduct(Complex other)//returns the dot product of the complex number
    {
        return (a*other.real() + b*other.imag());
    }
    Complex Complex:: scalarProduct(double value)//returns the scalar product of the complex number and a double 
    {
        a *= value;//multiplying the real component by the inputted value 
        b *= value;//multiplying the imaginary component by the inputted value 
        return Complex (a,b);//returning this complex number 
    }
    double Complex:: angleBetween(Complex other)//returning the angle between two complex numbers in degrees
    {
        double tan = (atan2((real()*other.imag() - other.real() * imag()), dotProduct(other)));//using arc tan to find the angle between the vectors 
        tan *= 180/M_PI;//converting from radians to degrees 
        if(tan < 0)//finding the positive angle between the two vectors 
        {
            tan += 360;
        }
        return tan;//returning the angle in degrees 
    }
     Complex:: operator const char* ()//conversion operator 
    {
        ostringstream outputf;
        if(real() != 0)
        {
        outputf << real();
        out = outputf.str();//adding the real portion 
        }
        if(imag() != 0)
        {
        if(imag() > 0)//if the imaginary portion is positive, it adds a plus for the imaginary term 
        {
            outputf << " + ";
            out = outputf.str();
        }
        else if(imag() < 0)//if the imaginary portion is negative, it adds a negative for the imaginary term
        {
            outputf << " - ";
            out = outputf.str();
        }
        outputf << abs(imag()) << "i";
        out = outputf.str();
        }
        return out.c_str();//returning the string 
    }
#endif