/*
BigMath.cpp
Adding and Subtracting various BigMath object
Albert Hung 
*/
#include <iostream> //importing the necessary preprocessor directives
#include <sstream>
#include <bits/stdc++.h>
using namespace std; //choosing a namespace so I don't have to type out std
int menu;            //initializing various variables for input values
string input1 = "";
string input2 = "";
bool rerun = true;
class BigMath
{
private: //private variable for each BigMath object
    int value;
    BigMath *nBigMath;
    BigMath *head;
    bool negative = false;
    string out = "";

public:
    BigMath(int val = 0, BigMath *a = NULL) //constructor for the linked list for the BigMath object with default values
    {
        value = val;
        nBigMath = a;
    }
    BigMath(string input) //taking a input string and creating its respective linked list
    {
        string temp = input;
        string finalDigit = temp.substr(temp.length() - 1, 1); //getting the last character of the inputted string
        int lastNum = stoi(finalDigit);                        //converting the last number of the string to an integer
        BigMath *temp1 = new BigMath(lastNum, NULL);           //this acts as the first node
        setHead(temp1);                                        //saving the location of the first node
        while (temp.length() > 1)                              //going through the input string and saving each number as a new node
        {
            string sfinalDigit = temp.substr(temp.length() - 2, 1); //getting the second to last digit in the string since we already have the value of the last digit
            int sLastNum = stoi(sfinalDigit);                       //converting the second to last character in the string to an integer
            BigMath *temp2 = new BigMath(sLastNum, NULL);           //creating a new BigMath object with the new values
            temp1->setNext(temp2);                                  //setting the next node value
            temp.pop_back();                                        //removing the last character of the input string
            temp1 = temp2;                                          //allows to move forward in the list
        }
    }
    BigMath *getNext() //returning the address of the next node
    {
        return nBigMath;
    }
    void setNext(BigMath *a) //setting the address of the next node
    {
        nBigMath = a;
    }
    int getVal() //returning the value stored at the node
    {
        return value;
    }
    void setVal(int v) //setting the value stored at the node
    {
        value = v;
    }
    void setHead(BigMath *a) //setting the location of the first node
    {
        head = a;
    }
    BigMath *getHead() //getting the location of the first node
    {
        return head;
    }
    bool getNeg() //boolean to see if the BigMath object is negative
    {
        return negative;
    }
    void setNeg(bool j) //setting the boolean if this BigMath object is negative
    {
        negative = j;
    }
    BigMath *operator+(BigMath *other) //addition operator to add two different BigMath objects
    {
        int mod = 0;
        int carry = 0;
        string result = "";
        BigMath *val1 = getHead(); //getting the first node of each BigMath objects
        BigMath *val2 = other->getHead();
        while (val1 != NULL && val2 != NULL) //while not at the end of the linked list up to the last node
        {
            mod = ((val1->getVal() + val2->getVal()) + carry) % 10;   //adding the corresponding places starting from the ones place
            carry = ((val1->getVal() + val2->getVal()) + carry) / 10; //if the sum of the values is greater than 9, 1 has to be carried over to the next place
            result.insert(0, to_string(mod));                         //adding the previously calculated values to a string
            val1 = val1->getNext();                                   //moving forward in the linked list
            val2 = val2->getNext();
        }
        if (carry != 0) //if the first number in the sum has a value that needs to be carried over(i.e. 1)
        {
            result.insert(0, to_string(carry)); //adding the value to the string
        }
        BigMath *a = new BigMath(result); //creating a new BigMath object with the previously saved string(sum)
        return a;                         //returning the BigMath object
    }
    BigMath *operator-(BigMath *other) //subtraction operator to subtract two different BigMath objects
    {
        int mod = 0;
        int carry = 0;
        string result = "";
        BigMath *val1 = getHead(); //getting the first node of each BigMath objects
        BigMath *val2 = other->getHead();
        while (val1 != NULL && val2 != NULL) //while not at the end of the linked list up to the last node
        {
            mod = (val1->getVal() - val2->getVal()) - carry; //subtracting the corresponding places starting from the ones place
            if (mod < 0)                                     //if there is a need to carry over a 1 from the following place
            {
                mod = 10 + mod;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            result.insert(0, to_string(mod)); //adding the value to the string
            val1 = val1->getNext();           //advancing through the linked list
            val2 = val2->getNext();
        }
        BigMath *a = new BigMath(result); //creating a new BigMath object with the previously saved result string
        return a;                         //returning the BigMath object
    }
    operator const char *() //printing a BigMath object
    {
        ostringstream outputf;
        BigMath *c = getHead();      //getting the first node of the object
        while (c->getNext() != NULL) //while not at the end of the list, excluding the last node
        {
            outputf << c->getVal(); //getting the value at the node
            out = outputf.str();    //adding it to the output string
            c = c->getNext();       //advancing to the next node
        }
        outputf << c->getVal(); //getting the value for the final node
        out = outputf.str();    //adding it to the output string
        if (getNeg())           //if the BigMath object is negative
        {
            outputf << "-"; //adding a negative sign to the output
            out = outputf.str();
        }
        reverse(out.begin(), out.end()); //reversing the string since the output is read from the ones place moving right to left
        return out.c_str();              //returning the final value of the BigMath object
    }
};
string append(string a, int n) //appending the input values, adding 0s to the beginning of a BigMath object so that both BigMath objects are the same length
{
    while (a.length() < n)
    {
        a.insert(0, "0");
    }
    return a;
}
int maxLength(string input1, string input2) //calculating the largest length of both input strings
{
    if (input1.length() >= input2.length())
    {
        return input1.length();
    }
    return input2.length();
}
int main()
{
    while (rerun) //boolean that allows user to rerun the program
    {
        cout << "Would you like to 1)add or 2) subtract two numbers?" << endl; //prompting the user for a choice to add or subtract two BigMath objects
        cin >> menu;                                                           //reading the input
        cout << "Please enter the first number: " << endl;                     //prompting the user for a input for their first BigMath object
        cin >> input1;                                                         //reading the user input
        cout << "Please enter the second number: " << endl;                    //prompting the user for a second input for thier second BigMath object
        cin >> input2;                                                         //reading the user input
        BigMath *a = new BigMath(append(input1, maxLength(input1, input2)));   //creating a new BigMath object with the appended input values
        BigMath *b = new BigMath(append(input2, maxLength(input1, input2)));
        BigMath *c;    //creating a new BigMath object for the final output
        if (menu == 1) //if the user chose to add two BigMath objects
        {
            c = a->operator+(b);                                                  //adding two BigMath objects and setting it to c
            cout << "The sum of " << *a << " and " << *b << " is " << *c << endl; //printing the output
        }
        if (menu == 2) //if the user chose to subtract two BigMath objects
        {
            if (input1.length() > input2.length()) //if the first input is larger than the second
            {
                c = a->operator-(b);
            }
            else //if the second input is larger than the first
            {
                c = b->operator-(a);
                c->setNeg(true); //final output will be negative
            }
            cout << "The difference of " << *a << " and " << *b << " is " << *c << endl; //printing the output
        }
        delete c; //deleting pointers
        delete a;
        delete b;
        cout << "Would you like to rerun the program? Enter 0 for no and 1 for yes" << endl; //prompting the user if he or she would like to rerun the program
        cin >> rerun;                                                                        //reading the user input
    }
}