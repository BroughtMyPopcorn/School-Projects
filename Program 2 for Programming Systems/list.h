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
        int deleteItem(int del);

    private:
        node* head_; //contains a node for insertion

        int deleteItem(node*& head_, int del);
        void display(node* head_);
        int traverse(node* head_, int ref);
};
