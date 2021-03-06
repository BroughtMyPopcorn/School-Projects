/*
 * This low file is for the classes that have relation to my abstract base class
 *
 */
#include <cctype>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//manages the nodes of the doubly linked list
class node
{
    public:
        node();
        ~node();
        node(const node & src);
        node*& getNext(); //returns next ptr void setNext(node* todata); //sets the next ptr node*& getPrev(); //gets the prev ptr
        node*& getPrev();
        void setPrev(node* todata); //sets the prev ptr
        void setNext(node* todata);
        void setData(int choice); //lets the user to pick which function to call
        void edit();  //allows user to edit the list
        void change();  //allows user to change the question
        class questions* getData(); //gets the ptr to question
        void display(); //calls questions' display
    protected:
        node* next; //next ptr 
        node* prev; //prev ptr
        class questions* data; //contains an questions obj 
};



