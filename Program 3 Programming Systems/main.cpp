/*
   Nelson Wong
   CS202

   This program uses a Red-Black Tree as a data structure with operator overloading. 
    The purpose of of this program is so that the user can insert apps and search for apps in a tree structure
    The external file can be modified by the user so that the user can insert data faster than using the program prompts
   The data is inserted into a red-black which is a lit data structure which that Ologn WORST CASE like wow! Such efficiency 
   Operator overloading is used in parts needed in this program, but all the operators that are required to be overloaded are overloaded 
   When inserting a new app, setting everything to an int would work fine (:

 */

#include "high.h"

void getInfo(tree*& obj); //function to get user input for an and insert it to tree

int main(){
    bool cont = true; //bool for do while loop
    int menu = 0; //for user insert
    tree* obj = new tree;//new tree* object to call functions 
    // apps* obj = new apps;
    obj->readin(); //calls the readin from external file

    do{
        cout<<"1 to insert a new app"<<endl;
        cout<<"2 to search search for an app by name"<<endl;
        cout<<"3 to display everything"<<endl;
        cout<<"4 to delete remove everything and end the program"<<endl;

        cin>>menu;
        cin.ignore();

        if(menu == 1){
            getInfo(obj); //calls function for user input

        }

        else if(menu == 2){
            char find[1000];
            cin.get(find, 1000, '\n');
            cin.ignore(1000, '\n');
            char* input  = new char [strlen(find)+1];
            strcpy(input, find);
            obj->search(input); //not working
            delete[] input;
        }

        else if(menu == 3){
            cout<<*obj;
        }

        else if(menu == 4){
            delete obj;
            cont = false;
        }
    }while(cont == true);

    return 0;
}


//function for the user insertion to the tree, need tree*& obj because it's used for operator overloading. 
void getInfo(tree*& obj){

    int choice; //used to pick which app 
    cout<<"Enter which app you want to insert"<<endl;
    cout<<"1. Business app"<<endl;
    cout<<"2. Social media app"<<endl;
    cout<<"3. Gaming app"<<endl;
    cin>>choice;
    cin.ignore();

    if(choice == 1){
        apps* ptr = new biz; //apps ptr is a new derived
        ptr->insert(); //calls the derived user insertion
        *obj+=ptr; //calls the tree insertion
    }

    if(choice == 2){
        apps* ptr = new social;
        ptr->insert();
        *obj+=ptr;
    }

    if(choice == 3){
        apps* ptr= new games;
        ptr->insert();
        *obj+=ptr;
    }

}
