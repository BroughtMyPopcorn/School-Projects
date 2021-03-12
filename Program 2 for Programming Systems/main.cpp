/*
Nelson Wong
CS202 
For this program, it allows the user to manipulate questions that are inserted in a array of doubly linked lists
The rtti is in the node constructor, dynamic binding in for insert

*/
#include "table.h"

int main(){
    bool go = true;
    int cont = 0;
    table* obj = new table;
    do{
        cout<<"1 for insert new question"<<endl;
        cout<<"2 for search for an item"<<endl;
        cout<<"3 to remove a question"<<endl;
        cout<<"4 to edit a question"<<endl;
        cout<<"5 to display questions"<<endl;
        cout<<"6 to end the prog"<<endl;
        cin>>cont;
        cin.ignore();

        if(cont == 1){
            obj->pick();
        }

        if(cont == 2){
            obj->search();
        }

        if(cont == 3){
            obj->remove();
        }

        if(cont == 4){
            obj->edit();
         }

        if(cont == 5){
            obj->display();
        }

        if(cont == 6){
            go = false;
            delete obj;
        }
        

    }while(go == true);
    
    return 0;
}