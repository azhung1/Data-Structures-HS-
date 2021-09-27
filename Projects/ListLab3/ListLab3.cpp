#include <iostream>

#include "ListLab3.h"
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

    h->add(h, "data struct", -1337);
    h->add(h, "blah", 9001);
    h->add(h, "help", 0);
    h->add(h, "c++ more like b-", 4);

   cout<< *h << endl; // [help, data struct, lmao, blah, c++ more like b-]

    h->remove(h, -1);
    h->remove(h, 0);
    h->remove(h, 42);

    cout<< *h << endl; // [lmao, blah]

    h->add(h, "idk", 1);
    h->add(h, "idk part 2 electric boogaloo", 2);
    h->add(h, "join programming club", 40);

    cout<< *h << endl; // [lmao, idk, idk part 2 electric boogaloo, blah, join programming club]

    h->remove(h, 2);
    h->remove(h, 2);

   cout<< *h << endl; // [lmao, idk, join programming club]

    return 0;
}