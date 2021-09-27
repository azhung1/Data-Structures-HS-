/*
ComplexNumber.cpp
Performing various calculations for complex numbers 
Albert Hung
*/
#include <iostream>//importing the necessary preprocessor directives
#include <cmath>
using namespace std;//choosing a namespace so I don't have to type out std 
double x,y,val,x2,y2,addInput;//initializing all of the required variablese
int input;
bool rerun = true;
class Complex
{
    private:
        double a, b;
    public:
    Complex (double real, double imaginary)//constructor 
    {
        a = real;
        b = imaginary;
    }
    Complex operator + (Complex& other)//addition operator to add two different complex numbers 
    {
        return Complex (real()+ other.real(), imag()+other.imag());//returning the new complex number after summing the components 
    }
     Complex operator - (Complex& other)//subtraction operator to subtract the two different complex numbers 
    {
        return Complex(real()- other.real(), imag()-other.imag());//returning the new complex number after subtracting the individual components 
    }
    Complex operator * (Complex& other)//multiplication operator to multiply two different complex numbers 
    {
        return Complex((real())*(other.real()) - (imag())*(other.imag()), imag()*other.real() + other.imag()*real());//returning the complex number after foiling 
    }
    Complex operator / (Complex& other)//division operator to subtract the two different complex numbers 
    {
        Complex temp (other.conjugate().real(),other.conjugate().imag());//storing the conjugate of the denominator 
        Complex quotient (0,0);
        quotient = temp * *this;//multiplying the numberator by the conjugate 
        Complex denom = temp * other;//multiplying the denominator by the conjugate 
        return Complex(quotient.real()/denom.real(), quotient.imag() / denom.real());//dividing the complex numerator by the denomiator and returning the complex number 
    }
    bool operator == (Complex& other)//equality operator 
    {
        return (real() == other.real()) && (imag() == other.imag());//returning a boolean if the the two complex numbers are the same  
    }
    operator string()//conversion operator 
    {
        string out;//initializing output string 
        out += to_string(real());//adding the real portion 
        if(imag() > 0)//if the imaginary portion is positive, it adds a plus for the imaginary term 
        {
            out += " + " ;
        }
        else if(imag() < 0)//if the imaginary portion is negative, it adds a negative for the imaginary term
        {
            out += " - ";
        }
        out += (to_string(abs(imag())));//adding the absolute value of the imaginary number to the string 
        out += 'i';//adding the i to represent the imaginary term 
        return out;//returning the string 
    }
    Complex conjugate()//returning the conjugate of the complex number 
    {
        return Complex (real(),-1*(imag()));//returning the complex number after changing the sign of the imaginary portion of the number 
    }
    double norm()//returning the norm of the complex number, which is the magnitude of the vector 
    {
        double tempA, tempB;
        tempA = pow (a,2);//squaring the magnitude real components 
        tempB = pow (b,2);//squaring the magnitude imaginary components
        return sqrt(tempA +tempB);//returning the squareroot of the sum of the magnitude of the squares 
    }   
    double real()//returns the real portion of the complex number 
    {
        return a;
    }
    double imag()//returns the imaginary portion of the complex number 
    {
        return b;
    }
    double dotProduct(Complex other)//returns the dot product of the complex number
    {
        return (a*other.real() + b*other.imag());
    }
    Complex scalarProduct(double value)//returns the scalar product of the complex number and a double 
    {
        a *= value;//multiplying the real component by the inputted value 
        b *= value;//multiplying the imaginary component by the inputted value 
        return Complex (a,b);//returning this complex number 
    }
    double angleBetween(Complex other)//returning the angle between two complex numbers in degrees
    {
        double tan = (atan2((real()*other.imag() - other.real() * imag()), dotProduct(other)));//using arc tan to find the angle between the vectors 
        tan *= 180/M_PI;//converting from radians to degrees 
        if(tan < 0)//finding the positive angle between the two vectors 
        {
            tan += 360;
        }
        return tan;//returning the angle in degrees 
    }
};
int main()
{
    while(rerun)//allows the user to rerun the program
    {
    cout << "Please select a menu option by entering the corresponding number: \n1. Find the Norm \n2. Find the Real part \n3. Find the Imaginary part \n4. Scalar Product" <<
    "\n5. Conjugate \n6. Dot Product \n7. Angle Between \n8. Addition \n9. Subtraction \n10. Multiplication \n11. Division \n12. Equality" << endl;//reading user input
    cin >> input;
    cout << "Please enter the real component(a) of the complex number: " << endl;//prompting the user for the real portion of the complex number 
    cin >> x;
    cout << "Please enter the imaginary component(b) of the complex number: " << endl;//prompting the user for the imaginary portion of the complex number
    cin >> y;
    Complex comp (x,y);//creating the instance 
    if(input < 6)//for the menu options that do not need an additional complex number 
    {
        if(input == 1)//norm 
        {
            cout << "The norm of the complex number " << comp.operator string() << " is " << comp.norm() << endl;
        }
        if(input == 2)//return the real portion of a complex number 
        {
            cout<< "The real portion of the complex number " << comp.operator string() << " is " << comp.real() << endl;
        }
        if(input == 3)//return the imaginary portion of a complex number 
        {
            cout<< "The imaginary portion of the complex number " << comp.operator string() << " is " << comp.imag() << endl;
        }
        if(input == 4)//scalar product 
        {
            cout << "Please enter a number you want to multiply the complex number by to find the scalar product: " << endl;//prompting user for the value he or she wants to multiply the vector by 
            cin >> addInput;
            cout << "The scalar product of the complex number " << comp.operator string() << " and " << addInput << " is " << (comp.scalarProduct(addInput)).operator string() << endl;
        }
        if(input == 5)//conjugate 
        {
            cout<< "The conjugate of the complex number " << comp.operator string() << " is " << (comp.conjugate()).operator string() << endl;
        }
    }
    else    
    {
        cout << "Please enter the real component(a) of the second complex number: " << endl;//prompting the user for the real component of an additional complex number 
        cin >> x2;
        cout << "Please enter the imaginary component(b) of the second complex number: " << endl;//prompting the user for the imaginary component of an additional complex number 
        cin >> y2;
        Complex comp1 (x2,y2);
        if(input == 6)//dot product 
        {
            cout << "The dot product of the two complex numbers " << comp.operator string() << " and " << comp1.operator string() << " is " << comp.dotProduct(comp1) << endl;
        }
        if(input == 7)//angle between the two vectors
        {
            cout << "The angle(in degrees) between the two complex number " << comp.operator string() << " and " << comp1.operator string() << " is " << comp.angleBetween(comp1) << endl;
        }
        if(input == 8)//sum of the two vectors 
        {
            cout << "The sum of the two complex numbers " << comp.operator string() << " and " << comp1.operator string() << " is " << (comp + comp1).operator string() << endl;
        }
        if(input == 9)//difference of the two vectors 
        {
            cout << "The difference of the two complex numbers " << comp.operator string() << " and " << comp1.operator string() << " is " << (comp - comp1).operator string() << endl;
        }
        if(input == 10)//product of the two vectors 
        {
            cout << "The product of the two complex numbers " << comp.operator string() << " and " << comp1.operator string() << " is " << (comp * comp1).operator string() << endl;
        }
        if(input == 11)//quotient of the two vectors
        {
            cout << "The quotient of the two complex numbers " << comp.operator string() << " and " << comp1.operator string() << " is " << (comp / comp1).operator string() << endl;
        }
        if(input == 12)//equality of the two vectors
        {
            if(comp == comp1)//if they are equal 
            {
                cout << "The two complex numbers " << comp.operator string() << " and " << comp1.operator string() << " are equal." << endl;
            }
            else//if they are not equal 
            {
                cout << "The two complex numbers " << comp.operator string() << " and " << comp1.operator string() << " are not equal." << endl;
            }
        }
    }
    cout << "Would you like to rerun the program? (Enter 1 for yes and 0 for no)?" << endl;//prompts the user if he or she would like to rerun the program 
    cin >> rerun;
    }
}