/*
PostFix
Albert Hung 
Prompts the user for the name of a file and then displays the answer to the mathematical expression that is written in postfix notation
*/
#include <iostream> //importing the necessary libraries
#include <string>
#include <fstream>
#include <ctype.h>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
class PostFix
{
private:
    stack<int> nums; //initializing variables
    int num = 0;
    int a, b;
    string numbers = "";
    bool numb = true;
    bool pos = true;

public:
    int calculate(string s) //method to calculate postfux expressions
    {
        for (int i = 0; i < s.length(); i++) //traversing the entire input string
        {
            if (s.at(i) != ' ') //reading the characters by reading what is between the spaces
            {
                numbers.push_back(s.at(i));
            }
            if (s.at(i) == ' ' || i == s.length() - 1) //at the end of each part of the expression marked by a space or the last character in the string
            {
                for (char inputs : numbers) //traversing the characters between spaces
                {
                    if (!isdigit(inputs)) //checking if the characters between spaces are all numbers
                    {
                        numb = false;
                    }
                }
                if (numb == false) //means characters in string are either a negative number or just an operator
                {
                    if (numbers.length() > 1) //if number is negative
                    {
                        int len = numbers.length();
                        numbers = numbers.substr(1, len - 1); //getting the number without the negative sign
                        num = stoi(numbers) * (-1);
                        nums.push(num); //adding it to the stack
                    }
                    else //if it is an operator
                    {
                        if (numbers == "!") //factorial
                        {
                            a = nums.top(); //getting the top value in the stack
                            nums.pop();     //removing the top value in the stack
                            int temp = 1;
                            while (a > 1)
                            {
                                temp *= a;
                                a--;
                            }
                            nums.push(temp); //adding the new computed value to the top of the stack
                        }
                        else //if the operator is not a factorial
                        {
                            a = nums.top(); //getting the top value in the stack
                            nums.pop();
                            b = nums.top(); //getting the second value in the stack
                            nums.pop();
                            if (numbers == "+") //if addition
                            {
                                nums.push(b + a);
                            }
                            else if (numbers == "-") //if subtraction
                            {
                                nums.push(b - a);
                            }
                            else if (numbers == "*") //if multiplication
                            {
                                nums.push(b * a);
                            }
                            else if (numbers == "/") //if division
                            {
                                nums.push(b / a);
                            }
                            else if (numbers == "^") //if exponential
                            {
                                nums.push(pow(b, a));
                            }
                            else if (numbers == "%") //if modulus
                            {
                                nums.push(b % a);
                            }
                        }
                    }
                }
                else //if the string between spaces are all numbers
                {
                    num = stoi(numbers);//converting the string to integers 
                    nums.push(num);//adding it to the top of the stack 
                }
                numbers = "";//resetting all fo the variables 
            }
            numb = true;
            pos = true;
        }
        return nums.top();//returning the result, which is the last value in the stack
    }
};
int main()
{
    string inputFileName = "";
    string line = "";
    ofstream outputFile("result.txt");                                           //creating the output file
    cout << "Please enter the file name. Please include the file type." << endl; //prompting the user for the file name
    cin >> inputFileName;                                                        //reading the file name
    ifstream inputFile(inputFileName);
    while (getline(inputFile, line)) //reading each line
    {
        PostFix a;
        outputFile << line << ": " << a.calculate(line) << endl; //writing to the output file
    }
}
