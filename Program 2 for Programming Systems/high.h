/*
 *This high.h file is for the classes for the functions for the array and the linked list manipulation
 *
 */

#include "low.h"

const int NUM = 3;

//the table class manages the double ptr to the list class(array)
class table
{
    public:
        table();
        ~table();
        // void insert();
        void display();
        void pick();//picks which question to insert
        void search();
       // int getref();
        int getdel();
        int remove_w();
        int edit();
    protected: 
        class list** index; //double ptr to dynamically allocate the array
       // int ref;
       // int del; //user inputs which number to delete
        void search_w(int &arrIndex);
        int arrIndex; //index traverser for arr
        //int choice; //allows user to pick which question to insert
        //int dis; //int that allows user to choose which type of question to display
};

//the list class manages the insertion of nodes
class list
{
    public:
        list();
        ~list();
      //  void insertw(tabl); //wrapper for insert
        void display(); //wrapper for display funct
        void remove(); //remove question
        void insert(int);
        void search(int ref); //search function 
        void test();
         int delete_item(int del);

    protected:
        int delete_item(node*& head, int del);
         node* head; //contains a node for insertion
        void display(node* head);
        void remove(node*& head);
       // node* search(node* head); //search function 
        int traverse(node* head, int ref);
};


