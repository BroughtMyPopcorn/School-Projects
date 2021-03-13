#include "table.h"
#include "questions.h"

/* 
Author: Nelson Wong
This file contains the functions for the list class
*/

list::list() {
    head_ = NULL;
}

list::~list() {
    node* temp = head_;
    while (head_) {
        temp = temp->getNext();
        delete head_;
        head_ = temp;
    }
}


//inserts the data into a doubly linked list
void list::insert(int choice){
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

int list::delete_item(int del){
    return delete_item(head_, del);
}

int list::delete_item(node*& head_, int del){

    if(!head_) { 
        return 1;
    }

    if(head_->getQuestionData()->getReference() == del) {
        node* temp = head_->getNext();
        node* temp2 = head_->getPrev();
        delete head_;
        head_ = temp;
        if(head_){
            head_->getPrev() = temp2;
        }
        return 1;
    }
    return delete_item(head_->getNext(), del);
}

void list::display() {
    if (!head_) {
        return;
    }

    display(head_);
}

void list::display(node* head_) {
    if (!head_) {
        return;
    }
    head_->displayQuestions();        // calls node display
    return display(head_->getNext());
}

int list::search(int ref){
    return traverse(head_, ref);
}

int list::traverse(node* head_, int ref) {

    if(!head_) {
        return 0;
    }
    if(head_->getQuestionData()->getReference() == ref) {
        head_->displayQuestions();
        return 1;
    }

    return traverse(head_->getNext(), ref);
}