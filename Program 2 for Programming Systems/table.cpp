#include "table.h"

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
            int catchh = index[i]->deleteItem(toedit);
            if(catchh == 1){
                pick();
            }
        }
    }
    return 0;
}

int table::remove_w(){
    int del;
    cout<<"enter in a reference num to delete: "<<endl;
    cin>>del;
    cin.ignore();
    for(int i = 0; i<NUM;i++){
        if(index[i]){
            index[i]->deleteItem(del);
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


void table::display(){

    int pick = 0;
    // if(!head_) return;
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
