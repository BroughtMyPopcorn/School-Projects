#include "high.h" 


table::table(){

    index = new list *[NUM];// make a new array with 3 elements

    for(int i=0;i<NUM; i++){
        index[i] = NULL;
    }
    // ref = 0;
    arrIndex = 0;
}

table::~table(){

    //deallocates the array
    for(int i=0; i<NUM;i++){
        if(index[i]){
            delete index[i];
            index[i] = NULL;
        }
    }

    if(index){
        delete [] index;
    }
}

int table::edit(){
    int toedit;
    cout<<"enter in the question ref to edit"<<endl;
    cin>>toedit;

    for(int i = 0; i<NUM;i++){
        if(index[i]){
            index[i]->search(toedit);
            int catchh = index[i]->delete_item(toedit);
            if(catchh == 1){
                pick();
            }
        }
    }

}

int table::remove_w(){
    int del;
    cout<<"enter in a reference num to delete: "<<endl;
    cin>>del;
    cin.ignore();
    for(int i = 0; i<NUM;i++){
        if(index[i]){
            index[i]->delete_item(del);
        }
    }

    return 1;
}



void table::search(){
    int ref =0;
    cout<<"Which reference number do you want to search for"<<endl;
    cin>>ref;
    cin.ignore();

    for(int i = 0; i<NUM;i++){
        if(index[i]){
            index[i]->search(ref);
        }
    }

    return;
}

void table::pick(){
    int choice;
    cout<<"what type of question do you want to add?"<<endl;
    cout<<"Enter 1 for parallel programming"<<endl;
    cout<<"Enter 2 for threads"<<endl;
    cout<<"Enter 3 for algorithms"<<endl;
    cin>>choice;
    cin.ignore(100, '\n');
    if(index[choice-1] == NULL){
        index[choice-1] = new list();
    }

    index[choice-1]->insert(choice);
}

//--------------------------------------------

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


void table::display(){

    int pick = 0;
    // if(!head) return;
    cout<<"Which type of question do you want to display"<<endl;
    cout<<"1 for parallel programming"<<endl;
    cout<<"2 for threads"<<endl;
    cout<<"3 for algorithms"<<endl;

    cin>>pick;
    cin.ignore(100, '\n');
    if(pick == 1 && index[0]){
        index[0]->display();
    }
    else if(pick == 2 && index[1]){
        index[1]->display();
    }
    else if(pick == 3 && index[2]){
        index[2]->display();
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
