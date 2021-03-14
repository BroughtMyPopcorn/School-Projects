#include "table.h"
#include "questions.h"

/* 
Author: Nelson Wong

This file contains the functions for the list class, whose primary
function is to manage the insertion of nodes
*/

list::list() {
    head_ = NULL;
}

list::~list() {
    node * temp = head_;
    while (head_) {
        temp = temp->getNext();
        delete head_;
        head_ = temp;
    }
}


//inserts the data into a doubly linked list
void list::insert(int choice) {
    //if there's not a list already, initialize one 
    if(!head_) {
        head_ = new node;
        head_->setQuestion(choice);
        head_->setNext(NULL);
        head_->setPrev(NULL);
    }
    //add the node into the list
    else {
        node * temp = head_;
        head_ = new node;
        head_->setQuestion(choice);
        head_->setNext(temp);
        temp->setPrev(head_);
        return;
    }
}

// Wrapper function for deleting an item
int list::deleteItem(int del){
    return deleteItem(head_, del);
}

// Functon that deletes a node from the list
int list::deleteItem(node*& head_, int del) {

    if (!head_) { 
        return 1;
    }

    if (head_->getQuestionData()->getReference() == del) {
        node* temp = head_->getNext();
        node* temp2 = head_->getPrev();
        delete head_;
        head_ = temp;
        if(head_){
            head_->getPrev() = temp2;
        }
        return 1;
    }
    return deleteItem(head_->getNext(), del);
}

// Wrapper for display
void list::display() {
    if (!head_) {
        return;
    }

    display(head_);
}

// Function that runs the display functions for the children of questions
void list::display(node* head_) {
    if (!head_) {
        return;
    }
    head_->displayQuestions();        // calls node display
    return display(head_->getNext());
}

// Wrapper for the traverse function
int list::search(int ref) {
    return traverse(head_, ref);
}

// Function that searches for a specific question using an id
int list::traverse(node* head_, int ref) {
    if (!head_) {
        return 0;
    }
    if (head_->getQuestionData()->getReference() == ref) {
        head_->displayQuestions();
        return 1;
    }

    return traverse(head_->getNext(), ref);
}