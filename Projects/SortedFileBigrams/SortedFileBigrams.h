/* 
SortedFileBigrams
Albert Hung 
*/
#include <string>
#include <iostream>
using namespace std;
#ifndef SORTEDFILEBIGRAMS_H
#define SORTEDFILEBIGRAMS_H
class SortedFileBigrams
{
private: //initializing the variables
    string val;
    SortedFileBigrams *left;
    SortedFileBigrams *right;
    string result = "";
    SortedFileBigrams *temp = NULL;
    int count = 1;

public: //public methods
    SortedFileBigrams(string c, SortedFileBigrams *r, SortedFileBigrams *l);
    SortedFileBigrams *buildTree(string s);             //takes a string parameter and builds a BST where each letter is a node
    SortedFileBigrams *insert(SortedFileBigrams *t, string s); //inserts a node containing the character into the tree
    string inorderTraverse(SortedFileBigrams *t);
    string print();
};
SortedFileBigrams ::SortedFileBigrams(string c = "", SortedFileBigrams *r = NULL, SortedFileBigrams *l = NULL) //constructor with default values
{
    val = c;
    right = r;
    left = l;
}
SortedFileBigrams *SortedFileBigrams::buildTree(string s) //building the tree
{
    SortedFileBigrams *root = new SortedFileBigrams(s); //creating the root node
    return root;
}
SortedFileBigrams *SortedFileBigrams ::insert(SortedFileBigrams *t, string s) //adding a node to a given tree
{
    if (t == NULL) //if the node is null, create a new noe
    {
        return new SortedFileBigrams(s);
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
string SortedFileBigrams ::inorderTraverse(SortedFileBigrams *t) //inorder traversal, completing left subtree than moving right
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
string SortedFileBigrams::print()//returning the entire word count of the tree 
{
    result += temp->val + ": " + to_string(count) + "\n";//printing the last value in the tree 
    return result;
}
#endif
