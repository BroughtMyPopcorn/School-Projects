/*
Nelson Wong
CS202 
For this program, it allows the user to manipulate questions that are inserted in a array of doubly linked lists
The rtti is in the node constructor, dynamic binding in for insert

*/
#include "table.h"

int main() {
    bool go = true;
    int cont = 0;
    int result = 0;
    table * obj = new table;
    do {
        cout << "Enter 1 to insert a new question" << endl;
        cout << "Enter 2 to search for an item" << endl;
        cout << "Enter 3 to remove a question" << endl;
        cout << "Enter 4 to edit a question" << endl;
        cout << "Enter 5 to display questions" << endl;
        cout << "Enter 6 to end the program" << endl;
        cin >> cont;
        cin.ignore();

        if(cont == 1) {
            obj -> pick();
            result = 0;
        }

        if(cont == 2) {
            result = obj -> search();
        }

        if(cont == 3) {
            result = obj -> remove();
        }

        if(cont == 4) {
            result = obj -> edit();
         }

        if(cont == 5) {
            obj -> display();
            result = 0;
        }

        if(cont == 6) {
            go = false;
            delete obj;
            result = 0;
        }

        if (result != 0) {
            cout << "That reference number is invalid." << endl;
        }

    } while (go == true);
    
    return 0;
}