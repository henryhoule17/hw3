#include <iostream>
#include <fstream>
#include <functional>
//#include "llrec.h"
#include "llrec.cpp"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        cout << head->val;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------

struct Comp{
    bool operator()(int val)
    {
    if(val%2 == 0)
        return false;
    else
        return true;
    }
};



int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    // Test out your linked list code

    Node* smaller;
    Node* larger;
    Comp comp;

   /* llpivot(head, smaller, larger, 8);
    cout << "Larger: ";
    print(larger);
    cout << "Smaller: ";
    print(smaller);*/


    larger = llfilter(head, comp);
    print(larger);
   // smaller = llfilter(smaller, comp);
    //print(smaller);

    //dealloc(smaller);
    dealloc(larger);
	//dealloc(head);

    return 0;

}
