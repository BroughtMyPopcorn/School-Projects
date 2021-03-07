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
    if(head_){
        while(head_){
            temp = temp->getNext();
            delete head_;
            head_ = temp;
        }
    }
}


//inserts the data into a doubly linked list
void list::insert(int choice){

    if(!head_){
        head_ = new node;
        head_->setData(choice);
        head_->setNext(NULL);
        head_->setPrev(NULL);
    }
    else{
        node * temp = head_;
        head_ = new node;
        head_->setData(choice);
        head_->setNext(temp);
        temp->setPrev(head_);
        return;
    }


}

int list::deleteItem(int del){

    return deleteItem(head_, del);

}

int list::deleteItem(node*& head_, int del){

    if(!head_) 
        return 1;
    if(head_->getData()->getReference() == del){

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

void list::display(){
    if(!head_) 
        return;

    display(head_);
}

void list::display(node* head_){
    if(!head_) 
        return;

    head_->display();        // calls node display

    return display(head_->getNext());
}

void list::search(int ref){

    traverse(head_, ref);
}

int list::traverse(node* head_, int ref){

    if(!head_) 
        return 0;
    if(head_->getData()->getReference() == ref){
        head_->display();
        return 1;
    }

    return traverse(head_->getNext(), ref);

}