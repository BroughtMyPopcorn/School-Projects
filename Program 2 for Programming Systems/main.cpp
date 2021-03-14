/*
Nelson Wong
CS202 
For this program, it allows the user to manipulate questions that are inserted in a array of doubly linked lists
The rtti is in the node constructor, dynamic binding in for insert

*/
#include "table.h"

int main() {
    bool go = true;
    int actionNumber = 0;
    int result = 0;
    table * obj = new table;
    do {
       std::cout << "Enter the corresponding number for the action" << std::endl;
        std::cout << "1 to insert new question" << std::endl;
        std::cout << "2 to search for an item" << std::endl;
        std::cout << "3 to remove a question" << std::endl;
        std::cout << "4 to edit a question" << std::endl;
        std::cout << "5 to display questions" << std::endl;
        std::cout << "6 to end the program" << std::endl;
        std::cin >> actionNumber;
        std::cin.ignore();

        if(actionNumber == 1) {
            obj -> pick();
            result = 0;
        }

        if(actionNumber == 2) {
            result = obj -> search();
        }

        if(actionNumber == 3) {
            result = obj -> remove();
        }

        if(actionNumber == 4) {
            result = obj -> edit();
         }

        if(actionNumber == 5) {
            obj -> display();
            result = 0;
        }

        if(actionNumber == 6) {
            go = false;
            delete obj;
            result = 0;
        }

        if (result != 0) {
            std::cout << "That reference number is invalid." << std::endl;
        }

    } while (go == true);
    
    return 0;
}
