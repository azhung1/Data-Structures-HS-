  /*
    ListLab 
    Creating List Nodes to be part of the Linked List
    Albert Hung
    */
    #include <iostream>//importing the necessary preprocessor directives
    #include <sstream>
    using namespace std;//choosing a namespace so I don't have to type out std 
    #ifndef LISTLAB1_H
    #define LISTLAB1_H
    class ListNode
    {
      private://private variables that represent the structure of each node
          string val;
          ListNode* nListNode;
        public://method header declarations
            ListNode(string str, ListNode* a);
            ListNode* getNext();
            void setNext(ListNode* a);
            void setValue(string str);
            string getValue();
            ListNode* copyNode(ListNode* arg);
            ListNode* copyList(ListNode* arg);
            ListNode* rest(ListNode* h);
            string first(ListNode* head);
            string second(ListNode* head);
            ListNode* pointerToLast(ListNode* head);
            ListNode* copyOfLast(ListNode* head);
            ListNode* insertFirst(ListNode* head, string arg);
            ListNode* insertLast(ListNode* head, string arg);
    };
    //implementation of the methods
    ListNode::ListNode(string str = "", ListNode* a = NULL)//constructor that takes 2 parameters or sets default values 
    {
      val = str;
      nListNode = a;
    }
    ListNode* ListNode :: getNext()//returning the address of the next node 
    {
      return nListNode;
    }
    void ListNode:: setNext(ListNode* a)//setting the address of the next node 
    {
      nListNode = a;
    }
    void ListNode:: setValue(string str)//setting the value of the string stored at a node 
    {
      val = str;
    }
    string ListNode :: getValue()//getting the valuye of the string stored at a node 
    {
      return val;
    }
    ListNode* ListNode :: copyNode(ListNode* arg)//making a new node and copying the argument node 
    {
      ListNode* temp = new ListNode(arg->getValue(), arg->getNext());//making a new node and copying over the values 
      return temp;//returning the node 
    }
    ListNode* ListNode:: copyList(ListNode* arg)//returns a new list that is a copy of the original list 
    {
      ListNode *temp;
      if(arg->getNext() == NULL)//if the pointer to the next node is NULL then the current node is the last one 
      {
        return copyNode(arg);//returning the last node 
      }
      temp = new ListNode(arg->getValue(), copyList(arg->getNext()));//creating new node with the current string and pointing to the next node 
      return temp;//returning the node 
    }
    ListNode* ListNode :: rest(ListNode* h)
    {
      ListNode *temp;
      if(h->getNext()->getNext() == NULL)//if the pointer two nodes over is NULL then the next node is the last one 
      {
        return copyNode(h->getNext());
      }
      temp = new ListNode(h->getNext()->getValue(), rest(h->getNext()));//creating the nodes such that the first one in the list is omitted 
      return temp;//returning the created node 
    }
    string ListNode :: first(ListNode* head)//returns the value of the first node or NULL if empty 
    {
      if(head == NULL)//returning null if empty 
      {
        return NULL;
      }
      return head->getValue();//returning the string stored at the node 
    }
    string ListNode :: second(ListNode* head)//returning the value of the second node
    {
      return first(rest(head));//returning the first node of the rest method, which already omits the first node 
    }
    ListNode* ListNode:: pointerToLast(ListNode* head)//returns a reference to the last node in the list 
    {
      ListNode* temp = head;
      while(temp->getNext() != NULL)//traversing the linked list to find the last node
      {
        temp = temp->getNext();
      }
      return temp;//returning a pointer to the last node 
    }
    ListNode* ListNode:: copyOfLast(ListNode* head)//returns a copy of the last node
    {
      ListNode* copy = new ListNode(pointerToLast(head)->getValue(), pointerToLast(head)->getNext());//creating a node with the value and pointer of the last node 
      return copy;//returning the last node 
    }
    ListNode* ListNode:: insertFirst(ListNode* head, string arg)//returns a lsit whose first node's value is specified by the argument and the first node's next links to the original list 
    {
      ListNode *temp = new ListNode(arg, head);//creating a new node that satisfies the criteria 
      return temp;//returning the node 
    }
    ListNode* ListNode:: insertLast(ListNode* head, string arg)//returns a reference to a list whose last node's value is specified by the argument
    {
      ListNode* temp = head;
      ListNode* newNode = new ListNode (arg, NULL);//acting as the last node with the argument as the stored value 
      while(temp->getNext() != NULL)//traversing the list to find the end 
      {
        temp = temp->getNext();
      }
      temp->setNext(newNode);//setting the previously created tail to the last node 
      return head;//returning the node 
    }
  #endif
  
