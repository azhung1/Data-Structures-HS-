#include <iostream>//importing the necessary preprocessor directives
#include <string>
#include <math.h>

using namespace std;//choosing a namespace so I don't have to type out std 
int d, b, resultInt, remain, counter, inputVal;//initializing int variables
string num, result;//initializing string variables

string toBase(int decimal, int base)//converting from base 10 to base of users choice
{
    result = "";//final result string 
    while(decimal != 0)
    {
        result = to_string(decimal % base) + result;//using to_string to convert the integer into a string and adding it to the beginning of the result string
        decimal /= base; //doing integer division
    }
    return result;//return the final number after conversion as a string
}
string toBase16(int decimal)//converting from base 10 to base 16
{
    result = "";//final result string 
    remain = 0;//keeps track of the remainder 
    while(decimal != 0)
    {
        remain = decimal % 16;//finding the remainder of a number when divided by 16
        if(remain >= 10)//if the remainder is greater or equal to 10, characters have to be used to represent the number
        {
            remain = (decimal % 16) + 55;//adding 55 to get the corresponding capital letters on the ascii table
            result = static_cast<char>(remain) + result;//converting the ascii numbers to their respective characters and additing it to the beginning of the number 
        }
        else//if the remainder is less than 10, it can just be added to the beginning of the number
        {
            result = to_string(decimal % 16) + result;//using to_string to convert the integer into a string and adding it to the beginning of the result string
        }
        decimal /= 16;//performing integer division
    }
    return result;//returing the hexadecimal number after conversion as a string 
}
int toInteger(string number, int base)//converting a number in a given base to base 10
{
    resultInt = 0;//final output
    counter = 0;//represents the length of the string, with the first digit being 0, and the second digit being 1 etc. 
    while(number.length() > 0)
    {
        resultInt += (((int)(number.at(number.length()-1)))-48) * pow(base, counter);//taking the last digit in a number, converting it from a char to an int with the 
        //use of the ascii table and multiplying it by the base raised to the counter
        number.pop_back();//removing the last character of the input string  
        counter++;
    }
    return resultInt;//returning the number in base 10 as an integer 
}
int toInteger16(string number)//converting a given number in hexademical to base 10 
{
    resultInt = 0;//final result
    counter = 0;//represents the length of the string, with the first digit being 0, and the second digit being 1 etc. 
    while(number.length() > 0)
    {
        if((int)(number.at(number.length()-1)) > 58)//if the last character in the string is a letter 
        {
            resultInt += (((int)(number.at(number.length()-1)))-55) * pow(16, counter);//converting the letters in hexadecimal from ascii to their respective numerical value 
        }
        else
        {
            resultInt += (((int)(number.at(number.length()-1)))-48) * pow(16, counter);//converting the ascii values to their respective numerical values
        }
            number.pop_back();//removing the last character of the input string 
            counter++;
    }
    return resultInt;//return the final number in base 10 as an integer 
}
int main()
{
    bool repeat = true;//keeping track if the user woulf like to run the program again
    while (repeat)
    {
    cout <<" Please enter a number corresponding to the following menu: \n1. Covert decimal to base(2-9) of choice" 
    "\n2. Convert decimal to hexadecimal \n3. Convert a number in base(2-9) to decimal  \n4. Convert hexadecimal to decimal" << endl; //outputting a menu for the user
    //to select the function he or she would like to perform
    cin >> inputVal;//reading the input of the user 
    while (inputVal > 4 || inputVal <1)//ensuring that the inputted value is between 1-4
    {
    cout << "Please enter a number 1-4: " << endl; //prompting the user for a valid value 
    cin >> inputVal;//reading the input of the user     
    }
    if (inputVal == 1)
    {
    cout << "Enter the base: " << endl;//prompting the user for a number that will represent the base he or she would like to change change to 
    cin >> b;//reading the input and storing it as an integer 
    cout << "What number(from base 10) do you want to convert to base " << b << " ? "<< endl;//prompting the user for a number in base 10 that he or she would like to convert 
    //to the previously inputted base
    cin >> d;//reading the input and storing it as an integer 
    cout << d << " in base " << b << " is " << toBase(d, b) << endl;//printing the output 
    }  
    else if (inputVal == 2)
    {
    cout << "Enter a number(in base 10) you want to convert to hexadecimal: " << endl;//prompting the user for a number that he or she would like to convert to hexadecimal
    cin >> d;//reading the input and storing it as an integer
    cout << d << " converted to hexadecimal(base 16) is " << toBase16(d) << endl;//printing the output
    }
    else if (inputVal == 3)
    {
    cout << "Enter the base: " << endl;//prompting the user for a base
    cin >> b;//reading the input and storing it as an integer 
    cout << "What number do you want to convert from base " << b << " to base 10? "<< endl;//prompting a user for a number in the given base 
    cin >> num;//reading the input and storing it as a string 
    cout << num << " in base " << b << " converted to base 10 is " << toInteger(num, b) << endl;//printing the output 
    }
    else if (inputVal == 4)
    {
    cout << "Enter an hexadecimal number you want to convert to base 10: " << endl;//prompting the user for a hexadecimal number that will be converted to base 10
    cin >> num;//reading the input and storing it as a string 
    cout << num << " in base 10 is " << toInteger16(num) << endl;//printing the output
    }
    cout << "Would you like to run the program again? (Enter 1 for yes or 0 for no)"<<endl;//asking the user if he or she would like to run the program again
    cin >> repeat;//reading the input such that if the user wants to run the program again, the program will reprompt the user from the beginning 
    }
    return 0;
}
