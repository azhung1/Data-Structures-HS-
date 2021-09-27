/*
    ListLab3
    Albert Hung
    Creating and altering linked lists 
*/
#include <iostream> //importing the necessary preprocessor directives
#include <sstream>
using namespace std; //choosing a namespace so I don't have to type out std
#ifndef LISTLAB3_H
#define LISTLAB3_H
class ListNode
{
private: //private variables that represent the structure of each node
    string val;
    ListNode *nListNode;
    ListNode *pListNode;
    string out = "";

public: //method header declarations
    ListNode(string str, ListNode *a, ListNode *b);
    ListNode *getNext();
    void setNext(ListNode *a);
    ListNode *getPrev();
    void setPrev(ListNode *b);
    void setValue(string str);
    string getValue();
    ListNode *copyNode(ListNode *arg);
    ListNode *copyList(ListNode *arg);
    ListNode *rest(ListNode *h);
    string first(ListNode *head);
    string second(ListNode *head);
    int count(ListNode *head);
    ListNode *pointerToLast(ListNode *head);
    ListNode *copyOfLast(ListNode *head);
    ListNode *insertFirst(ListNode *head, string arg);
    ListNode *insertLast(ListNode *head, string arg);
    ListNode *insertMiddle(ListNode *head, string arg, int position);
    ListNode *remove(ListNode *head, int position);
    ListNode *add(ListNode *head, string arg, int position);
    operator const char *();
};
//implementation of the methods
ListNode::ListNode(string str = "", ListNode *a = NULL, ListNode *b = NULL) //constructor that takes 2 parameters or sets default values
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
ListNode *ListNode::insertFirst(ListNode *head, string arg) //returns a lsit whose first node's value is specified by the argument and the first node's next links to the original list
{
    ListNode *temp1 = head;
    while (temp1->getPrev() != NULL) //traversing backwards in the linked list to find the first node
    {
        temp1 = temp1->getPrev();
    }
    ListNode *temp = new ListNode(arg, temp1, NULL); //creating a new node that satisfies the criteria
    temp1->setPrev(temp);                            //setting the previous location of the second node to the first node
    return head;                                     //returning the node
}
ListNode *ListNode::insertLast(ListNode *head, string arg) //returns a reference to a list whose last node's value is specified by the argument
{
    ListNode *temp = head;
    ListNode *newNode = new ListNode(arg, NULL); //acting as the last node with the argument as the stored value
    while (temp->getNext() != NULL)              //traversing the list to find the end
    {
        temp = temp->getNext();
    }
    temp->setNext(newNode); //setting the previously created tail to the last node
    newNode->setPrev(temp);
    return head; //returning the node
}
ListNode *ListNode::insertMiddle(ListNode *head, string arg, int position) //inserting a new node at the inputted position within an already existing linked list
{
    int counter = 0;
    ListNode *temp1 = head;
    while (temp1->getPrev() != NULL) //traversing the list to find the first node
    {
        temp1 = temp1->getPrev();
    }
    ListNode *currNode = temp1;
    while (counter < position - 1) //traversing the list until reaching the position before the intended node
    {
        currNode = currNode->getNext();
        counter++;
    }
    ListNode *newNode = new ListNode(arg, currNode->getNext()); //creating a new node with the indended values
    currNode->setNext(newNode);                                 //inserting the node into the linked list by setting the next node of the node before the insert position to the new created node
    return head;                                                //returning the head of the linked list
}
ListNode *ListNode::remove(ListNode *head, int position = 0) //removing a node at a given position within an already existing linked list
{
    int counter = 0;
    ListNode *temp = head;
    while (temp->getPrev() != NULL) //traversing the list to find the first node
    {
        temp = temp->getPrev();
    }
    ListNode *currNode = temp;
    ListNode *prevNode = temp;
    int pos = position;
    if (pos <= 0) //if a negative position or 0 is inputted, the first node will be removed
    {
        currNode->getNext()->setPrev(NULL);
        currNode->setNext(NULL);
        return head;
    }
    else if (pos >= head->count(head) - 1) //if the last node is chosen or a value greater than the length of the linked list is inputted, the last node will be removed
    {
        pos = head->count(head) - 1; //setting the position to the last node
    }
    while (counter < pos) //traversing the list until the position of the node that is going to be removed
    {
        prevNode = currNode;
        currNode = currNode->getNext();
        counter++;
    }
    if (pos == head->count(head) - 1) //if the last node is being removed
    {
        prevNode->setNext(NULL);
        currNode->setPrev(NULL);
    }
    else
    {
        prevNode->setNext(currNode->getNext()); //removing the current node at the position by setting the pointer of the previous node to the location of the node after the node being removed
        currNode->getNext()->setPrev(prevNode);
    }
    return head; //returning the head of the linked list
}
ListNode *ListNode::add(ListNode *head, string arg, int position = 0) //adding a node to the linked list
{
    if (position <= 0) //if a position of 0 or a negative value is inputted, a node will be added to the beginning of the list
    {
        head->insertFirst(head, arg);
    }
    else if (position > (head->count(head) - 1)) //if the position is greater than the length of the linked list
    {
        head->insertLast(head, arg);
    }
    else //inserting a node in the middle of the linked list
    {
        head->insertMiddle(head, arg, position);
    }
    return head;
}
int ListNode::count(ListNode *head) //counting the nodes in the linked list
{
    ListNode *temp = head;
    while (temp->getPrev() != NULL) //traversing the list to find the first node
    {
        temp = temp->getPrev();
    }
    int counter = 1;
    while (temp->getNext() != NULL)//counting all of the nodes 
    {
        temp = temp->getNext();
        counter++;
    }
    return counter;//returning the length of the linked list 
}
ListNode::operator const char *()//operator to print the linked list 
{
    ostringstream output;
    ListNode *temp = this;
    output << "[";
    out = output.str();
    while (temp->getPrev() != NULL)//traversing to the beginning of the linked list 
    {
        temp = temp->getPrev();
    }
    output << temp->getValue();//printing the first value 
    out = output.str();
    output << ", ";//seperating nodes by a comma 
    out = output.str();
    temp = temp->getNext();//traversing the linked list
    while (temp != NULL)//traversing the linked list until the end is reached
    {
        output << temp->getValue();
        out = output.str();
        temp = temp->getNext();
        if (temp != NULL)
        {
            output << ", ";
            out = output.str();
        }
    }
    output << "]";
    out = output.str();
    return out.c_str(); //returning the string
}
#endif