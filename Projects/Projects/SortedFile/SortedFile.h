/* 
SortedFile
Albert Hung 
*/
#include <string>
#include <iostream>
using namespace std;
#ifndef SORTEDFILE_H
#define SORTEDFILE_H
class SortedFile
{
private: //initializing the variables
    string val;
    SortedFile *left;
    SortedFile *right;
    string result = "";
    SortedFile *temp = NULL;
    int count = 1;

public: //public methods
    SortedFile(string c, SortedFile *r, SortedFile *l);
    SortedFile *buildTree(string s);             //takes a string parameter and builds a BST where each letter is a node
    SortedFile *insert(SortedFile *t, string s); //inserts a node containing the character into the tree
    string inorderTraverse(SortedFile *t);
    string print();
};
SortedFile ::SortedFile(string c = "", SortedFile *r = NULL, SortedFile *l = NULL) //constructor with default values
{
    val = c;
    right = r;
    left = l;
}
SortedFile *SortedFile::buildTree(string s) //building the tree
{
    SortedFile *root = new SortedFile(s); //creating the root node
    return root;
}
SortedFile *SortedFile ::insert(SortedFile *t, string s) //adding a node to a given tree
{
    if (t == NULL) //if the node is null, create a new noe
    {
        return new SortedFile(s);
    }
    if (s > t->val) //setting the right node if the char is greater than the value of the parent
    {
        t->right = insert(t->right, s);
    }
    else //setting the left node if the char is less than the value of the parent
    {
        t->left = insert(t->left, s);
    }
    return t;
}
string SortedFile ::inorderTraverse(SortedFile *t) //inorder traversal, completing left subtree than moving right
{
    if (t == NULL)//breaks if the node is null 
    {
        return "";
    }
    inorderTraverse(t->left);//traversing the left subtree
    if (temp != NULL)
    {
        if (temp->val == t->val)//incrementing count if adjascent words are the same 
        {
            count++;
        }
        else
        {
            result += temp->val + ": " + to_string(count) + "\n";//printing the final word count of a word 
            count = 1;
        }
    }
    temp = t;//moving along the tree
    inorderTraverse(t->right);
    return "";
}
string SortedFile::print()//returning the entire word count of the tree 
{
    result += temp->val + ": " + to_string(count) + "\n";//printing the last value in the tree 
    return result;
}
#endif
