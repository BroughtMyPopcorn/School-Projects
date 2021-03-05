#include "table.h"


list::list(){

    head = NULL;
    //ref = 0;

}

list::~list(){

    node* temp = head;
    if(head){
        while(head){
            temp = temp->getNext();
            delete head;
            head = temp;
        }
    }
}


//inserts the data into a doubly linked list
void list::insert(int choice){

    //    cout<<"hiiii"<<endl;
    //if there's not a list already, initialize one 
    if(!head){
        head = new node;
        head->setData(choice);
        head->setNext(NULL);
        head->setPrev(NULL);
    }
    //add the node into the list
    else{
        node * temp = head;
        head = new node;
        head->setData(choice);
        head->setNext(temp);
        temp->setPrev(head);
        // temp->setNext(NULL);
        return;
    }


}

int list::delete_item(int del){
    return delete_item(head, del);
}

int list::delete_item(node*& head, int del){

    if(!head) return 1;
    /* table* ptr;
       int del = ptr->getdel();
       */
    if(head->getData()->getReference() == del){
        node* temp = head->getNext();
        node* temp2 = head->getPrev();
        delete head;
        head = temp;
        if(head){
            head->getPrev() = temp2;
        }
        return 1;
    }
    return delete_item(head->getNext(), del);

}

void list::display(){
    if(!head) return;

    display(head);
}

void list::display(node* head){
    if(!head) return;

    head->display();        // calls node display

    return display(head->getNext());
}

void list::search(int ref){

    traverse(head, ref);
}

int list::traverse(node* head, int ref){

    if(!head) return 0;
    /*
       table* ptr;
       int ref = ptr->getref();
       */
    if(head->getData()->getReference()== ref){
        head->display();
        return 1;
    }

    return traverse(head->getNext(), ref);

}

/*
   int list::remove(){
   if(!head) return 0;

   return remove(head);

   }

   int list::remove(node* head){


   }
   */
