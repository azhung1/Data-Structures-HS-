// Name: Albert Hung
// SortedFileBigrams

#include "SortedFileBigrams.h" //including all of the necessary extensions
#include <iostream>
#include <fstream>
#include <string>
string fileName = "";
int main()
{
    cout << "Enter the name of the file you would like to read.  Please include the file type." << endl; //prompting the user for the file name
    cin >> fileName;                                                                                     //storing the file name
    ifstream inputFile(fileName);
    string line;
    int loopCount = 0;
    SortedFileBigrams *root = nullptr;
    if (inputFile.is_open())
    {
        while (getline(inputFile, line)) //reading each line of the file
        {
            int counter = 0; //keeping track of the position in each line
            int beg = 0;     //index of the beginning of the word
            int end = 0;     //index of the end of the word
            int pos = 0;
            string rightWord = ""; //left word
            string leftWord = "";//right word
            string bigram = "";//final bigram 
            while (counter < line.length())//traversing each line 
            {
                while (line.at(counter) != ' ' && counter < line.length() - 1) //traversing until a space or the end of the line is reached
                {
                    counter++;
                }
                if (counter == line.length() - 1 && line.at(counter) != ' ') //if counter reaches the end of the line
                {
                    end = counter;
                }
                else
                {
                    end = counter - 1; //counter is the index with the space so you have to remove 1
                }
                if (loopCount == 0) //first time running through the program
                {
                    rightWord = line.substr(beg, end - beg + 1); //storing the word
                    leftWord = rightWord;
                }
                else if (loopCount == 1)
                {
                    rightWord = line.substr(beg, end - beg + 1); //storing the word
                    bigram = leftWord + ' ' + rightWord;//assembling the bigram 
                    leftWord = rightWord;
                    root = root->buildTree(bigram); //building the tree on the first word
                }
                else
                {
                    leftWord = rightWord;
                    rightWord = line.substr(beg, end - beg + 1); //storing the word
                    bigram = leftWord + ' ' + rightWord;
                    root->insert(root, bigram);               //adding words to the tree
                }
                pos = 0;           //resetting the position variable
                beg = counter + 1; //incrementing variables so that the next word is read
                counter++;
                loopCount++;
            }
        }
    }
    inputFile.close();
    root->inorderTraverse(root);       //traversing the tree alphabetically
    ofstream outputFile("result.txt"); //printing to the output file
    outputFile << root->print() << endl;
    outputFile.close();
    return 0;
}