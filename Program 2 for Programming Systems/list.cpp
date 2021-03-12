#include "table.h"
#include "questions.h"

/* 
Author: Nelson Wong
This file contains the functions for the list class
*/

list::list(){
    head_ = NULL;
}

list::~list(){
    node* temp = head_;
    while (head_) {
        temp = temp->getNext();
        delete head_;
        head_ = temp;
    }
}


//inserts the data into a doubly linked list
void list::insert(int choice){
    //    cout<<"hiiii"<<endl;
    //if there's not a list already, initialize one 
    if(!head){
        head = new node;
        head->setQuestion(choice);
        head->setNext(NULL);
        head->setPrev(NULL);
    }
    //add the node into the list
    else{
        node * temp = head;
        head = new node;
        head->setQuestion(choice);
        head->setNext(temp);
        temp->setPrev(head);
        // temp->setNext(NULL);
        return;
    }
}

int list::deleteItem(int del){
    return deleteItem(head_, del);
}

int list::delete_item(node*& head, int del){

    if(!head) return 1;
    /* table* ptr;
       int del = ptr->getdel();
       */
    if(head->getQuestionData()->getReference() == del){
        node* temp = head->getNext();
        node* temp2 = head->getPrev();
        delete head;
        head = temp;
        if(head){
            head->getPrev() = temp2;
        }
        return 1;
    }
    if (head_->getData()->getReference() == del) {

        node* temp = head_->getNext();
        node* temp2 = head_->getPrev();
        delete head_;
        head_ = temp;

        if (head_) {
            head_->getPrev() = temp2;
        }
        return 1;
    }
    return deleteItem(head_->getNext(), del);
}

void list::display(){
    if (!head_) {
        return;
    }

    display(head_);
}

void list::display(node* head_){
    if (!head_) {
        return;
    }
    head->displayQuestions();        // calls node display
    return display(head_->getNext());
}

void list::search(int ref){
    traverse(head_, ref);
}

int list::traverse(node* head, int ref){

    if(!head) return 0;
    /*
       table* ptr;
       int ref = ptr->getref();
       */
    if(head->getQuestionData()->getReference()== ref){
        head->displayQuestions();
        return 1;
    }

    return traverse(head_->getNext(), ref);
}