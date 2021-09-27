/* 
Parenthesis Match
Albert Hung 
Checking to see if an input contains matching parenthesis using stacks and reading from and writing to a text file
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class ParenMatch
{
public:
    string LEFT = "([{<";
    string RIGHT = ")]}>";
    int leftCount = 0;
    int rightCount = 0;
    int count = 0;
    bool checkParen(string s)//returns true if each opening parenthesis has a respective closing parenthesis
    {
        for (char &input : s)//for each character in the string
        {
            for (char &check : LEFT)//for each character in the opening parenthesis 
            {
                if (input == check)//if the character in the input string matches with an opening parenthesis
                {
                    push(input);//adding the opening parenthesis to the stack 
                }
            }
            for (char &checkR : RIGHT)//for each character in the closing parenthesis
            {
                if (input == checkR)//if the character in the input string matches with a closing parenthesis
                {
                    for (char &posLeft : LEFT)//checking if the opening and closing parenthesis match 
                    {
                        if (posLeft == top())//checking which type of parenthesis is in the top stack 
                        {
                            pop();
                            break;
                        }
                        else
                        {
                            leftCount++;//increasing the count, which represents which parenthesis is being used 
                        }
                    }
                    if (leftCount != rightCount)//if the parenthesis dont match 
                    {
                        return false;
                    }
                }
                leftCount = 0;
                rightCount++;
            }
            rightCount = 0;
        }
        if (count != 0)//if there are more opening parenthesis than closing ones 
        {
            return false;
        }
        return true;
    }
    class Node//defining the structure for the linked list 
    {
    public:
        char p;
        struct Node *next = NULL;
    };
    struct Node *head;//creating the head or first node 
    void push(char input)//inputting a character at the top of the stack 
    {
        struct Node *temp = new Node();//creating the new node 
        temp->p = input;//setting the designated character to the stored value 
        temp->next = head;//setting the new node as the top of the stack 
        head = temp;
        count ++;//keeping track of how many items are in the stack 
    }
    char top()//getting the first element in the stack 
    {
        return head->p;
    }
    void pop()//removing the first element in the stack 
    {
        struct Node *temp = new Node();
        temp = head;
        head = head->next;
        temp->next = NULL;
        count --;//keeping track of how many elements are in the stack 
    }
};
int main()
{
    string inputFileName = "";
    string line = "";
    int counter = 0;
    ofstream outputFile("result.txt");                                             //creating an output file called result.txt
    cout << "Please enter the file name.  Please include the file type. " << endl; //prompting the user for an input file name
    cin >> inputFileName;
    ifstream inputFile(inputFileName);
    while (getline(inputFile, line))//for each line in the text file that is to be read
    {
        ParenMatch a;
        if (a.checkParen(line))//if the parenthesis match 
        {
            outputFile << counter << ": good" << endl;
        }
        else//if they dont match 
        {
            outputFile << counter << ": bad" << endl;
        }
        counter++;//keeping track of the trial numbers 
    }
}