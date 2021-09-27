/*
PointerFunctions
Using pointers to perform an array of options includign swapping integer, couting the vowels and consonants in a string, and obtaining array information
Albert Hung
*/
#include <iostream>//importing the necessary preprocessor directives
#include <string>
#include <cstring>
using namespace std;//choosing a namespace so I don't have to type out std 
int x = 0;//intializing variables 
int y = 0;
int counter;
int value = 0;
int menu,size;
int* ptrInt;
const char *letter;
string input;
void swap(int* a, int* b)//swapping two integers
{
    int temp = *a;//storing the address of one of the integers in a temporary variable
    *a = *b;//setting the address of one of the integers to the other one
    *b = temp;//setting the address of the other integer to the value stored in the temporary variable 
}
void letterCount(string s, int* const numVowels, int* const numConsonants)//counting the vowels and consonants in an user inputed string 
{
    letter = s.c_str();//converts the inputted string to a char pointer
    for (int i = 0; i< strlen(letter); i++)
    {
        if(*(letter + i) == 65 || *(letter + i) == 69 || *(letter + i) == 73 || *(letter + i) == 79 || *(letter + i) == 85)//checking if the char at each position is a vowel
        {
            (*numVowels) ++ ;//incrementing the number of vowels when one is in the string 
        }
        else//for consonants 
        {
            (*numConsonants)++;
        }
    }
}
void arrayInfo(int* arrPtr, int length)
{
    *(ptrInt + counter) = *arrPtr;//sets value the user inputted to the correct element 
    counter++;//incrementing/acting as a placeholder
}
int main()
{
    bool rerun = true;
    while(rerun)
    {
    x = 0;//resets all of the variables 
    y = 0;
    value = 0;
    counter = 0;
    cout<< "Please enter a number corresponding with the following menu: \n1. Swap \n2. Letter Count \n3. Array Info" << endl;//prompting the user with a menu
    cin >> menu;
    if(menu == 1)
    {
    cout<<"Enter two numbers you want to swap(x): " << endl;//prompting the user for 2 inputs that he/she wants to swap 
    cin >> x;
    cout << "Enter another number(y): " << endl;
    cin >> y;
    swap(x,y);//calls the method to swap them using pointers 
    cout <<"Now x is " << x << " and y is " << y << endl;//prints the swapped variables
    }
    else if(menu == 2)
    {
    cout <<"Enter a string: " << endl;//prompts the user for a string input
    cin >> input;
    letterCount(input, &x, &y);//calls the method to count the number of consonants and vowels
    cout << "The string " << input << " has " << dec << x << " vowels and has " << dec << y << " consonants." << endl;//printing the output 
    }
    else if(menu == 3)
    {
    cout << "Input a value to be the length of the array: " << endl;//prompts user for a length for the array 
    cin >> size;
    ptrInt = new int [size];//creating an array with the input value size 
    for(int k = 0; k<size;k++)
    {
    cout <<"Enter a value for the " << k << " element of the array: " << endl;//prompts user for the input elements 
    cin >> value;
    arrayInfo (&value, size);//calls the method 
    }
    for(int j = 0; j< size; j++)
    {
        cout << "The element at " << j << " is "<< *(ptrInt +j) <<" and the memory location is " <<  hex <<(ptrInt + j) << endl;//printing filled array with memory location 
    }
    }
    cout << "Would you like to rerun the program? Enter 1 for yes, and 0 for no. " << endl;//asks the user if he or she would like to rerun the program
    cin >> rerun;//reads input value 
    }
    delete[] ptrInt;//deletes pointers 
}