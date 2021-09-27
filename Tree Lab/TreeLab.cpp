// Name:
// Date:

//includes
#include "TreeLab.h" //put your class inside TreeLab.h
#include <iostream>

   int main()
   {
	   //the tree contains the letters of the string, starting at position 1
	   string s = "XCOMPUTERSCIENCE";
	   //string s = "XGNSHighSchool"; 
	   //string s = "XAComputerScienceTreeHasItsRootAtTheTop";
	   //string s = "XA";   
	   //string s = "XAF";  
	   //string s = "XAFP";  
	   //string s = "XDFZM";   
	   
      TreeNode* root = nullptr;
      root = root->buildTree(s);
      cout << root->display(root, 0) << endl;
   
      cout << "\nPreorder: " << root->preorderTraverse(root) << endl;
      cout << "Inorder: " << root->inorderTraverse(root) << endl;
      cout << "Postorder: " << root->postorderTraverse(root) << endl;
   
      cout << "\nNodes = " << root->countNodes(root) << endl;
      cout << "Leaves = " << root->countLeaves(root) << endl;
      cout << "Only children = " << root->countOnlyChildren(root) << endl;
      cout << "Grandparents = " << root->countGrandParents(root) << endl;
   
      cout << "\nHeight of tree = " << root->height(root) << endl;
      cout << "Longest path = " << root->longestPath(root) << endl;
      cout << "Min = " << root->min(root) << endl;
      cout << "Max = " << root->max(root) << endl;	
   
      cout << "\nBy Level: " << root->displayLevelOrder(root) << endl;
	  
	  return 0;
   }