/* 
WordTree
Albert Hung 
*/
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#ifndef WORDTREE_H
#define WORDTREE_H
class WordNode
{
private:
    WordNode *children[26];
    bool endOfWord = false;
    int tempCount = 0;

public:
    WordNode();
    WordNode *buildTree(ifstream &file);
    void insert(WordNode *w, string s);
    void traverse(string prefix, WordNode *w, ofstream &file);
    int countNodes(WordNode *w);
    int rCharCount();
    bool getEndOfWord();
};
WordNode ::WordNode()//constructor 
{
    for (int i = 0; i < 26; i++)//array of chars default to null 
    {
        children[i] = NULL;
    }
    endOfWord = false;
}
WordNode *WordNode ::buildTree(ifstream &file)
{
    WordNode *root = new WordNode();
    string line;
    while (getline(file, line)) //reading each line of the file
    {
        insert(root, line);//calling insert for each word 
    }
    return root;
}
void WordNode ::insert(WordNode *w, string s)
{
    WordNode *temp = w;
    w->tempCount += s.length();//counting the chars in each word and summing them to get the sum for the entire document
    for (int i = 0; i < s.length(); i++)
    {
        int ascVal = s.at(i) - 'a';//getting the corresponding numerical value for each char 
        if (temp->children[ascVal] == NULL)
        {
            temp->children[ascVal] = new WordNode();
        }
        temp = temp->children[ascVal];//traversing the tree
    }
    temp->endOfWord = true;//changing the boolean once we reach the last char 
}
void WordNode ::traverse(string prefix, WordNode *w, ofstream &file)//traversing and printing the tree
{
    if (w != NULL)
    {
        if (w->endOfWord)//once we have all of the chars, we add the final word to the 
        {
            file << prefix << endl;
        }
        for (int i = 0; i < 26; i++)
        {
            if (w->children[i] != NULL)
            {
                char temp = 'a' + i;//piecing the word together 
                w->traverse(prefix + temp, w->children[i], file);
            }
        }
    }
}
int WordNode ::countNodes(WordNode *w)//counting the nodes on the tree
{
    int counter = 0;
    for (int i = 0; i < 26; i++)
    {
        if (w->children[i])
        {
            counter += 1 + countNodes(w->children[i]);//incrementing each time there is a char 
        }
    }
    return counter;
}
int WordNode ::rCharCount()//returning the number of chars in the entire input file 
{
    return tempCount;
}
#endif
