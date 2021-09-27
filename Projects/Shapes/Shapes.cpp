/*
Shapes.cpp
Calculating the areas for various polygons with user inputted dimensions
Albert Hung
*/
#include <iostream>//importing the necessary preprocessor directives
using namespace std;//choosing a namespace so I don't have to type out std 
int input;//initializing variables
bool rerun = true;
int val1, val2;
class Polygon//parent class
{
    protected:
    float a;//variable accesible by the child class
    int l, h;
    public: 
        Polygon(int length, int height)//constructor that takes the length and height of a polygon
        {
            l = length;
            h = height;
        }
        void setValues(int a, int b)//mutator method
        {
            l = a;
            h = b;
        }
    class Output//nested class that prints the output
    {
    public:
        void print();//to be initialized within the child class
    };
};
class Rectangle: public Polygon//first child class
{
    public:
      Rectangle(int length, int height)://using the parent constructor 
     Polygon(length, height)
     {
     }
    float area()//calculating the area of the rectangle
    {
        return l*h;
    }
    void print()//over writing the print method
    {
        cout << "The length of the rectangle is " << l << ". The width of the rectangle is " << h << ". The area of the rectangle is " << area() << "." << endl;
    }
};
class Triangle: public Polygon//second child class of the parent class
{
    public:
        Triangle (int length, int height)://making the traingle constructor the same as the parent class
        Polygon (length, height)
        {
        }
    float area()//calculating the area of the triangle
    {
        return (l*h)/2.0;
    }
    void print()//over writing the print method
    {
         cout << "The length of the base of the triangle is " << l << ". The height of the rectangle is " << h << ". The area of the triangle is " << area() << "." << endl;
    }
};
int main()
{
    while (rerun)//allows the user to run multiple times
    {
    cout << "Please enter the corresponding number with the menu option to create the following shapes.  \n1.Rectangle \n2.Triangle" << endl;//produces a menu for the user to select an option
    cin >> input;//reads user input
    if(input == 1)
    {
        cout<< "Please enter the length of the rectangle: " << endl;//accepting user inputs for the dimensions of the rectangle
        cin >> val1;
        cout << "Please enter the width of the rectangle: " << endl;
        cin >> val2;
        Rectangle rect (val1, val2); //creating a new rectangle object with the inputted values 
        // Rectangle rect (0,0);//creating a new rectangle object
        // rect.setValues(val1, val2);//setting the dimensions of the previously initialized rectangle object to the user inputted values 
        rect.print();//printing the final values and results of the methods 
    }
    else
    {
        cout<< "Please enter the base of the triangle: " << endl;//accepts user inputs for the dimesnions of the triangle 
        cin >> val1;
        cout << "Please enter the height of the triangle: " << endl;
        cin >> val2;
        Triangle tri (val1, val2);//creating a new triangle obejct with the user inputted values 
        // Triangle tri (0,0);//creating a new triangle object
        // tri.setValues(val1, val2);//setting the dimensions of the previously initialized triangle object with the user inputted values
        tri.print();//printing the final values 
    }
    cout << "Would you like to rerun the program? (Enter 1 for yes and 0 for no)?" << endl;//prompts the user if he or she would like to rerun the program 
    cin >> rerun;
    }
}
