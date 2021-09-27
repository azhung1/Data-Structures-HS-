/* 
TreeLab
Albert Hung 
*/
#include <string>
#include <iostream>
using namespace std;
#ifndef TREELAB_H
#define TREELAB_H
class TreeNode
{
private://initializing the variables 
    char val;
    TreeNode *left;
    TreeNode *right;
    string preTrav = "";
    string result = "";
    string trav = "";
    string postTrav = "";
    string iTrav = "";

public://public methods
    TreeNode(char c, TreeNode *r, TreeNode *l);
    TreeNode *buildTree(string s);         //takes a string parameter and builds a BST where each letter is a node
    TreeNode *insert(TreeNode *t, char s); //inserts a node containing the character into the tree
    string display(TreeNode *t, int level);
    string preorderTraverse(TreeNode *t);
    string inorderTraverse(TreeNode *t);
    string postorderTraverse(TreeNode *t);
    int countNodes(TreeNode *t);
    int countLeaves(TreeNode *t);
    int countGrandParents(TreeNode *t);
    int countOnlyChildren(TreeNode *t);
    int height(TreeNode *t);      //returns the max of the heights to the left and the heights to the right;
    int longestPath(TreeNode *t); //return the max of the sum of the heights to the left and the heights to the right
    char min(TreeNode *t);
    char max(TreeNode *t);
    string displayCurrentLevel(TreeNode *t, int level);
    string displayLevelOrder(TreeNode *t);
};
TreeNode ::TreeNode(char c, TreeNode *r = NULL, TreeNode *l = NULL)//constructor with default values 
{
    val = c;
    right = r;
    left = l;
}
TreeNode *TreeNode::buildTree(string s)//building the tree
{
    int place = 1;
    TreeNode *root = new TreeNode(s.at(place));//creating the root node 
    place++;
    while (place < s.length())//filling the rest of the tree
    {
        char temp = s.at(place);//each character is the value stored at the node
        insert(root, temp);
        place++;
    }
    return root;
}
TreeNode *TreeNode ::insert(TreeNode *t, char s)//adding a node to a given tree 
{
    if (t == NULL)//if the node is null, create a new noe 
    {
        return new TreeNode(s);
    }
    if (s > t->val)//setting the right node if the char is greater than the value of the parent
    {
        t->right = insert(t->right, s);
    }
    else//setting the left node if the char is less than the value of the parent
    {
        t->left = insert(t->left, s);
    }
    return t;
}
string TreeNode ::display(TreeNode *t, int level)//displaying the tree
{
  string results = "";
    int h = height(t);
    for (int i = 1; i <= h; i++)
    {
        results += displayCurrentLevel(t, i) + "\n"; //printing the tree level by level 
        result = "";
    }
    return results;
}
string TreeNode ::preorderTraverse(TreeNode *t)//preorder traversal, processing root than subtrees
{
    if (t == NULL)
    {
        return "";
    }
    preTrav += t->val;//adding to the string 
    preorderTraverse(t->left);
    preorderTraverse(t->right);
    return preTrav;
}
string TreeNode ::inorderTraverse(TreeNode *t)//inorder traversal, completing left subtree than moving right 
{
    if (t == NULL)
    {
        return "";
    }
    inorderTraverse(t->left);
    iTrav += t->val;
    inorderTraverse(t->right);
    return iTrav;
}
string TreeNode ::postorderTraverse(TreeNode *t)//postorder traversal, completing subtree levels than moving up, left to right 
{
    if (t == NULL)
    {
        return "";
    }
    postorderTraverse(t->left);
    postorderTraverse(t->right);
    postTrav += t->val;
    return postTrav;
}
int TreeNode ::countNodes(TreeNode *t) // counting nodes on a tree
{
    if (t == NULL)
    {
        return 0;
    }
    return 1 + countNodes(t->left) + countNodes(t->right); //incrementing by 1 and then moving to the left and right nodes 
}
int TreeNode ::countLeaves(TreeNode *t)//counting leaves 
{
    if (t == NULL)
    {
        return 0;
    }
    if (t->left == NULL && t->right == NULL)//incremenring by 1 if it is a leaf
    {
        return 1;
    }
    else
    {
        return countLeaves(t->left) + countLeaves(t->right);//moving to left and right subtree
    }
}
int TreeNode ::countGrandParents(TreeNode *t)//count grandparent nodes 
{
    int counter = 0;
    if (t == NULL)
    {
        return 0;
    }
    if (t->left == NULL && t->right == NULL)//not a grandparent if there is no children
    {
        return 0;
    }
    else if ((t->left == NULL) && (t->right->left == NULL && t->right->right == NULL))//not a grandparent if there is no third generation 
    {
        return 0;
    }
    else if ((t->right == NULL) && (t->left->left == NULL && t->left->right == NULL))
    {
        return 0;
    }
    else
    {
        return countGrandParents(t->left) + countGrandParents(t->right) + 1;
    }
}
int TreeNode ::countOnlyChildren(TreeNode *t)//counting only children 
{
    if (t == NULL)
    {
        return 0;
    }
    if ((t->left != NULL && t->right == NULL) || (t->right != NULL && t->left == NULL))//if there are no siblings
    {
        return 1 + countOnlyChildren(t->left) + countOnlyChildren(t->right);
    }
    else
    {
        return countOnlyChildren(t->left) + countOnlyChildren(t->right);
    }
}
int TreeNode ::height(TreeNode *t)//max height of the tree
{
    if (t == NULL)
    {
        return 0;
    }
    int leftTreeHeight = height(t->left);//traversing left and right tree and getting their max height 
    int rightTreeHeight = height(t->right);
    if (leftTreeHeight > rightTreeHeight)//comparing the heights 
    {
        return leftTreeHeight + 1;//have to add 1 to the final number 
    }
    return rightTreeHeight + 1;
}
int TreeNode ::longestPath(TreeNode *t)//sum of the left and right subtrees
{
    if (t == NULL)
    {
        return 0;
    }
    int leftTreeHeight = height(t->left);
    int rightTreeHeight = height(t->right);
    return rightTreeHeight + leftTreeHeight + 1;
}
char TreeNode ::min(TreeNode *t)//min value obtained by going to the left most node 
{
    TreeNode *temp = t;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->val;
}
char TreeNode ::max(TreeNode *t)//max value obtained by going to the right most node 
{
    TreeNode *temp = t;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->val;
}
string TreeNode ::displayCurrentLevel(TreeNode *t, int level)//printing the current level 
{
    if (t == NULL)
    {
        return "";
    }
    if (level == 1)
    {
        result += t->val;//once you reach the last layer, print the value 
    }
    else if (level > 1)
    {
        displayCurrentLevel(t->left, level - 1);
        displayCurrentLevel(t->right, level - 1);
    }
    return result;
}
string TreeNode ::displayLevelOrder(TreeNode *t)//printing all levels 
{
    string results = "";
    int h = height(t);
    for (int i = 1; i <= h; i++)
    {
        results += displayCurrentLevel(t, i);//storing all the values in a string 
        result = "";
    }
    return results;
}
#endif
