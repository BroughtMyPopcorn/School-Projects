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
        void display(); // Wrapper for display funct
        void insert(int);
        int search(int ref); // Search function 
        int deleteItem(int del);

    private:
        node* head_; // Contains a node for insertion

        int deleteItem(node*& head_, int del);
        void display(node* head_);
        int traverse(node* head_, int ref);
};
