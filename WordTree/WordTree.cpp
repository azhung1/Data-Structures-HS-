// Name: Albert Hung
// WordTree

#include "WordTree.h" //including all of the necessary extensions
#include <iostream>
#include <fstream>
#include <string>
string fileName = "";
int main()
{
    cout << "Enter the name of the file you would like to read.  Please include the file type." << endl; //prompting the user for the file name
    cin >> fileName;                                                                                     //storing the file name
    WordNode *a = new WordNode();
    ifstream inputFile(fileName);//reading the input file 
    a= a->buildTree(inputFile);//building the tree
    inputFile.close();//closing the input file 
    cout << "List Total: " << a->rCharCount() << endl;//printing the necessary statistics 
    cout << "Tree Total: " << a->countNodes(a) << endl;
    cout << "Savings: " << (1-(a->countNodes(a)/double(a->rCharCount()))) * 100 << endl;
    ofstream outputFile("result.txt"); //printing to the output file
    a->traverse("", a, outputFile);
     outputFile.close();//closing the output file 
    return 0;
}