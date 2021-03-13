/* 

Author: Nelson Wong
This file contains the definitions for the list class, whose primary
purpose is to manage the insertion of nodes

*/


class list
{
    public:
        list();
        ~list();
        void display(); //wrapper for display funct
        void insert(int);
        int search(int ref); //search function 
        int delete_item(int del);

    protected:
        node* head_; //contains a node for insertion

        int delete_item(node*& head_, int del);
        void display(node* head_);
        void remove(node*& head_);
        int traverse(node* head_, int ref);
};
