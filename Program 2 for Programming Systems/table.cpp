#include "table.h"

table::table() {
    index = new list *[NUM];// make a new array with 3 elements
    for(int i=0;i<NUM; i++) {
        index[i] = NULL;
    }
    arrIndex = 0;
}

table::~table() {
    //deallocates the array
    for(int i=0; i<NUM;i++) {
        if(index[i]) {
            delete index[i];
            index[i] = NULL;
        }
    }

    if(index) {
        delete [] index;
    }
}

void table::display() {
    int pick = 0;
    cout<<"Which type of question do you want to display?"<<endl;
    cout<<"Enter 1 for parallel programming"<<endl;
    cout<<"Enter 2 for threads"<<endl;
    cout<<"Enter 3 for algorithms"<<endl;
    cin>>pick;
    cin.ignore(100, '\n');

    if(pick == 1 && index[0]) {
        index[0]->display();
    }
    else if(pick == 2 && index[1]) {
        index[1]->display();
    }
    else if(pick == 3 && index[2]) {
        index[2]->display();
    }
}

void table::pick() {
    int choice;
    cout<<"What type of question do you want to add?"<<endl;
    cout<<"Enter 1 for parallel programming"<<endl;
    cout<<"Enter 2 for threads"<<endl;
    cout<<"Enter 3 for algorithms"<<endl;
    cin>>choice;
    cin.ignore(100, '\n');

    if(index[choice-1] == NULL) {
        index[choice-1] = new list();
    }
    index[choice-1]->insert(choice);
}

int table::search() {
    int ref = 0;
    int found = 1;
    cout<<"Which reference number do you want to search for:"<<endl;
    cin>>ref;
    cin.ignore();

    for(int i = 0; i<NUM;i++) {
        if(index[i]) {
            found = index[i]->search(ref);
        }
    }
    return found; //success is 0, failure is 1
}

int table::remove() {
    int del;
    int deleted = 1;
    cout<<"Enter in a reference num to delete:"<<endl;
    cin>>del;
    cin.ignore();

    for(int i = 0; i<NUM;i++) {
        if(index[i]) {
            deleted = index[i]->delete_item(del); //catch result
        }
    }
    return deleted; //success is 0, failure is 1
}

int table::edit() {
    int toedit;
    int edited = 1;
    cout<<"Enter in the question's reference number you want to edit:"<<endl;
    cin>>toedit;

    for(int i = 0; i<NUM;i++) {
        if(index[i]) {
            index[i]->search(toedit);
            int match = index[i]->delete_item(toedit);
            if(match == 1) {
                pick();
                edited = 0;
            }
        }
    }
    return edited; //success is 0, failure is 1
}





