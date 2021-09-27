/*
    DuckDuckGoose
    Albert Hung
    Simulating a duck duck goose game by reading an input file and printing the winner to an output file 
*/
#include <iostream> //importing the necessary preprocessor directives
#include <string>
#include <fstream>
using namespace std; //choosing a namespace so I don't have to type out std
class ListNode
{
private: //private variables that represent the structure of each node
    int val;
    ListNode *nListNode;
    int win;

public:                                   //method header declarations
    ListNode(int participants, int cycle) //creating a circular linked list fitting the inputted parameters
    {
        ListNode *head = new ListNode(); //creating the head of the linked list
        int counter = 1;                 //keeping track of the number of nodes created
        ListNode *curr = head;
        while (counter < participants) //adding nodes to the linked list
        {
            ListNode *temp = new ListNode(); //creating the new nodes
            curr->setNext(temp);             //setting the next node of the previous node to the newly created one
            curr = temp;
            counter++;
        }
        curr->setNext(head);                           //setting the next node of the last node to the head, closing the circular linked list
        setWin(runThrough(participants, cycle, head)); //calling the method to find the winner
    }
    ListNode(int value = 0, ListNode *a = NULL) //constructor that takes 2 parameters or sets default values
    {
        val = value;
        nListNode = a;
    }
    ListNode *getNext() //returning the address of the next node
    {
        return nListNode;
    }
    void setNext(ListNode *a) //setting the address of the next node
    {
        nListNode = a;
    }
    void setValue(int value) //setting the value of the int stored at a node
    {
        val = value;
    }
    int getValue() //getting the value of the string stored at a node
    {
        return val;
    }
    void setWin(int winner) //setting the position of the winner
    {
        win = winner;
    }
    int getWin() //getting the position of the winner
    {
        return win;
    }
    int runThrough(int participants, int cycle, ListNode *head) //calculating the winner
    {
        int cycleCount = 1; //keeping track of the number in the cycle
        int parCount = 0;   //keeping track of the number of participants removed
        int counter = 0;
        ListNode *temp = head;
        ListNode *temp1 = head;
        while (participants - parCount > 1) //while the number of participants left is greater than 1
        {
            if (temp->getValue() == 0) //if the participant is remaining, the value at the node is 0
            {
                cycleCount++; //moving through the cycle
            }
            while (temp->getNext()->getValue() != 0) //moving through the linked list to the next active participant
            {
                temp = temp->getNext();
            }
            temp = temp->getNext();
            if (cycleCount == cycle) //when the cycle is reached
            {
                parCount++;
                temp->setValue(1); //participant is removed by changing the value to 1
                cycleCount = 1;    //resetting the cycleCount
            }
        }
        while (temp1->getValue() != 0) //going through the linked list until the winner is reached (the value at the node is 0)
        {
            counter++;
            temp1 = temp1->getNext();
        }
        return counter; //returning the position of the winner
    }
};
int main()
{
    string inputFileName = ""; //initializing variables
    string line;
    int part = 0;
    int cycle = 0;
    int count = 0;
    ofstream outputFile("result.txt");                                             //creating an output file called result.txt
    cout << "Please enter the file name.  Please include the file type. " << endl; //prompting the user for an input file name
    cin >> inputFileName;
    ifstream inputFile(inputFileName);
    while (getline(inputFile, line)) //reading the input file
    {
        part = stoi(line);                                 //reading the first/odd number lines and storing them as the participant as in integer
        getline(inputFile, line);                          //moving to the next line
        cycle = stoi(line);                                //reading the second/even number lines and storing them as the cycle as in integer
        ListNode a(part, cycle);                           //calling the listnode method to create the respective circular linked list
        outputFile << count << ": " << a.getWin() << endl; //printing the outputs to the text file
        count++;
    }
    outputFile.close();
    inputFile.close();
}