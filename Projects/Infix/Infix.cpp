/*
Infix
Albert Hung 
Prompts the user for the name of a file and then displays the answer to the mathematical expression that is written in infix notation
*/
#include <iostream> //importing the necessary libraries
#include <string>
#include <fstream>
#include <ctype.h>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
class infix
{
private:
    string result = "";
    bool op = false;
    string temp = "";
    stack<string> operators;
    stack<int> nums; //initializing variables
    int num = 0;
    int a, b;
    string numbers = "";
    bool numb = true;
    bool pos = true;

public:
    string infixtoPostfix(string infix)
    {
        for (int i = 0; i < infix.length(); i++)
        {
            if (infix.at(i) != ' ')//reading the characters between the spaces
            {
                temp += infix.at(i);
            }
            if (infix.at(i) == ' ' || i == infix.length() - 1)
            {
                if (temp.length() > 1 || isdigit(temp.at(0)) == true)//adding numbers to the infix string 
                {
                    result += temp + " ";
                }
                else
                {
                    if (temp == "(")//if there is a opening parenthesis, push it onto the stack 
                    {
                        operators.push(temp);
                    }
                    else if (temp == ")")//if there is a closing parenthesis 
                    {
                        while (operators.top() != "(")//pop each element of the stack until an opening parenthesis is reached 
                        {
                            result += operators.top() + " ";
                            operators.pop();
                        }
                        operators.pop();//popping the opening parenthesis 
                    }
                    else if (operators.size() == 0 || operators.top() == "(" || isLower(temp.at(0), operators.top().at(0)) == false)//pushing back operator if conditions are met 
                    {
                        operators.push(temp);
                    }
                    else
                    {
                        while (operators.size() > 0 && (isLower(temp.at(0), operators.top().at(0)) && operators.top() != "("))//popping operators until condition is met 
                        {
                            result += operators.top() + " ";
                            operators.pop();
                        }
                        operators.push(temp);
                    }
                }
                temp = "";
            }
        }
        while (operators.size() > 1)//popping all of the operators in the stack 
        {
            result += operators.top() + " ";
            operators.pop();
        }
        result += operators.top();
        operators.pop();
        return result;
    }
    bool isLower(char c1, char c2)//testing precedence
    {
        bool md1 = false;
        bool as1 = false;
        bool md2 = false;
        bool as2 = false;
        if (c1 == '+' || c1 == '-')//if the first character is addition or subtraction
        {
            as1 = true;
            md1 = false;
        }
        else
        {
            as1 = false;
            md1 = true;
        }
        if (c2 == '+' || c2 == '-')//if the second character is addition or subtraction 
        {
            as2 = true;
            md2 = false;
        }
        else
        {
            as2 = false;
            md2 = true;
        }
        if ((as1 == as2 || md2 == md1) || ((as1 == true) && (md2 == true)))//returns true if the two characters are the same precedence or if the first is lower than the second
        {
            return true;
        }
        return false;
    }
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
                    num = stoi(numbers); //converting the string to integers
                    nums.push(num);      //adding it to the top of the stack
                }
                numbers = ""; //resetting all fo the variables
            }
            numb = true;
            pos = true;
        }
        return nums.top(); //returning the result, which is the last value in the stack
    }
};
int main()
{
    string inputFileName = "";
    string line = "";
    string postfix = "";
    ofstream outputFile("result.txt");                                           //creating the output file
    cout << "Please enter the file name. Please include the file type." << endl; //prompting the user for the file name
    cin >> inputFileName;                                                        //reading the file name
    ifstream inputFile(inputFileName);
    outputFile << "infix notation          postfix notation         answer" << endl; 
    while (getline(inputFile, line)) //reading each line
    {
        infix a;
        postfix = a.infixtoPostfix(line);
        outputFile << line << "         " << postfix << "        " << a.calculate(postfix) << endl; //writing to the output file
    }
}