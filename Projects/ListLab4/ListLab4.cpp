#include <iostream>

#include "ListLab4.h"
using namespace std;

void printMe(ListNode* head) {
    cout << "[";
    while (head != NULL) {
        cout << head->getValue();
        head = head->getNext();
        if (head != NULL)
            cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    ListNode* h = new ListNode("lmao");
    printMe(h); // [lmao]

    h->add(h, "data struct", 0);
     
    h->add(h, "blah", 1);
   
    h->add(h, "help", 1);
    h->add(h, "c++ more like b-", 4);

   cout<< *h << endl; // [help, data struct, lmao, blah, c++ more like b-]

    h = h->remove(h, 0);
     h->printBackward(h,1); // [lmao, blah]
    h = h->remove(h, 0);
    h->remove(h, 1);

    cout<< *h << endl; // [lmao, blah]

    h->add(h, "idk", 1);

    h->add(h, "idk part 2 electric boogaloo", 2);
    h->add(h, "join programming club", 1);

    cout<< *h << endl; // [lmao, idk, idk part 2 electric boogaloo, blah, join programming club]

    h->remove(h, 2);
    h->remove(h, 2);

   cout<< *h << endl; // [lmao, idk, join programming club]

    return 0;
}