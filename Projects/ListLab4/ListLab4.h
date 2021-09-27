/*
    ListLab4
    Albert Hung
    Creating and altering linked lists 
*/
#include <iostream> //importing the necessary preprocessor directives
#include <sstream>
using namespace std; //choosing a namespace so I don't have to type out std
#ifndef LISTLAB4_H
#define LISTLAB4_H
class ListNode
{
private: //private variables that represent the structure of each node
    string val;
    ListNode *nListNode;
    ListNode *pListNode;
    string out = "";
    bool front = true;
    bool back = false;

public: //method header declarations
    ListNode(string str, ListNode *a = NULL, ListNode *b = NULL);
    ListNode *getNext();
    void setNext(ListNode *a);
    ListNode *getPrev();
    void setPrev(ListNode *b);
    void setValue(string str);
    string getValue();
    int count(ListNode *head);
    ListNode *getLast(ListNode *head);
    ListNode *insertOrigin(ListNode *head, string arg);
    ListNode *insertMiddle(ListNode *head, string arg, int position);
    ListNode *remove(ListNode *head, int position);
    ListNode *add(ListNode *head, string arg, int position);
    void printForward(ListNode *head, int position);
    void printBackward(ListNode *head, int position);
    operator const char *();
};
//implementation of the methods
ListNode::ListNode(string str = "", ListNode *a, ListNode *b) //constructor that takes 2 parameters or sets default values
{
    val = str;
    nListNode = a;
    pListNode = b;
}
ListNode *ListNode ::getNext() //returning the address of the next node
{
    return nListNode;
}
void ListNode::setNext(ListNode *a) //setting the address of the next node
{
    nListNode = a;
}
ListNode *ListNode ::getPrev() //returning the address of the previous node
{
    return pListNode;
}
void ListNode::setPrev(ListNode *b) //setting the address of the previous node
{
    pListNode = b;
}
void ListNode::setValue(string str) //setting the value of the string stored at a node
{
    val = str;
}
string ListNode ::getValue() //getting the valuye of the string stored at a node
{
    return val;
}
ListNode *ListNode::insertOrigin(ListNode *head, string arg) //returns a reference to a list with an added node at the "last" position of the list
{
    ListNode *temp = head;
    ListNode *newNode = new ListNode(arg, head, getLast(head)); //acting as the last node with the argument as the stored value
    head->setPrev(newNode);//setting the previous node of the first node to the new node 
    newNode->getPrev()->setNext(newNode);//setting the next node of the second to last node to the last node 
    return newNode; //returning the node
}
ListNode *ListNode::insertMiddle(ListNode *head, string arg, int position) //inserting a new node at the inputted position within an already existing linked list
{
    int counter = 0;
    ListNode *temp1 = head;
    ListNode *currNode = temp1;
    while (counter < position - 1) //traversing the list until reaching the position before the intended node
    {
        currNode = currNode->getNext();
        counter++;
    }
    ListNode *newNode = new ListNode(arg, currNode->getNext(), currNode); //creating a new node with the indended values
    currNode->setNext(newNode);
    newNode->getNext()->setPrev(newNode); //inserting the node into the linked list by setting the next node of the node before the insert position to the new created node
    return head;                          //returning the head of the linked list
}
ListNode *ListNode::remove(ListNode *head, int position = 0) //removing a node at a given position within an already existing linked list
{
    int counter = 0;
    ListNode *temp = head->getNext();
    ListNode *temp1 = temp;
    ListNode *currNode = head;
    ListNode *prevNode = head;
    int pos = position;
    if (pos == 0 || pos == count(head)) //if the first node is chosen to be removed 
    {
        currNode->getNext()->setPrev(getLast(head));//setting the second node to the first 
        getLast(head)->setNext(currNode->getNext());
        return temp;
    }
    while (counter < pos) //traversing the list until the position of the node that is going to be removed
    {
        prevNode = currNode;
        currNode = currNode->getNext();
        counter++;
    }
    prevNode->setNext(currNode->getNext()); //removing the current node at the position by setting the pointer of the previous node to the location of the node after the node being removed
    currNode->getNext()->setPrev(prevNode);
    return head; //returning the head of the linked list
}
ListNode *ListNode::add(ListNode *head, string arg, int position = 0) //adding a node to the linked list
{
    ListNode *temp = head;
    if (position <= 0 || position > (count(head) - 1)) //if a position of 0 or a negative value is inputted, a node will be added to the beginning of the list
    {
        head->insertOrigin(head, arg);
    }
    else //inserting a node in the middle of the linked list
    {
        head->insertMiddle(head, arg, position);
    }
    return head;
}
ListNode *ListNode::getLast(ListNode *head)//getting the last node of the linked list 
{
    ListNode *temp = head;
    while (temp->getNext() != head && count(head) > 1) //traversing the list to find the last node
    {
        temp = temp->getNext();
    }
    return temp;
}
int ListNode::count(ListNode *head) //counting the nodes in the linked list
{
    ListNode *temp = head;
    int counter = 1;
    while (temp->getNext() != head && temp->getNext() != NULL) //traversing the list to find the first node
    {
        temp = temp->getNext();
        counter++;
    }
    return counter; //returning the length of the linked list
}
void ListNode::printForward(ListNode *head, int position)//printing the circular linked list forwards
{
    int counter = 0;
    ListNode *temp = head;
    while (counter < position)//traversing to the position inputted to start printing 
    {
        temp = temp->getNext();
        counter++;
    }
    front = true;//changing the boolean values for the operator 
    back = false;
    cout << *temp << endl;//printing the linked list
}
void ListNode::printBackward(ListNode *head, int position)//printing the circular linked list backwards 
{
    int counter = 0;
    ListNode *temp = head;
    while (counter < position)//traversing to the position inputted to start printing 
    {
        temp = temp->getNext();
        counter++;
    }
    front = false;//chaning the boolean values for the operator 
    back = true;
    cout << *temp << endl;//printing the linked list 
}
ListNode::operator const char *() //operator to print the linked list
{
    ostringstream output;
    ListNode *temp = this;
    ListNode *original = this;
    output << "[";
    out = output.str();
    output << temp->getValue(); //printing the first value
    out = output.str();
    output << ", "; //seperating nodes by a comma
    out = output.str();
    if (front)//if the user wants to print forward 
    {
        temp = temp->getNext(); //traversing the linked list

        while (temp != original) //traversing the linked list until the end is reached
        {
            output << temp->getValue();//printing the string stored at the node 
            out = output.str();
            temp = temp->getNext();
            if (temp != original)
            {
                output << ", ";
                out = output.str();
            }
        }
    }
    else if (back)//if the user wants to print the list backwards
    {
        temp = temp->getPrev();  //traversing the linked list
        while (temp != original) //traversing the linked list until the end is reached
        {
            output << temp->getValue();
            out = output.str();
            temp = temp->getPrev();
            if (temp != original)
            {
                output << ", ";
                out = output.str();
            }
        }
    }
    output << "]";
    out = output.str();
    return out.c_str(); //returning the string
}
#endif