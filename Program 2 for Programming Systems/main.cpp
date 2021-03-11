/*
Nelson Wong
CS202 
For this program, it allows the user to manipulate questions that are inserted in a array of doubly linked lists
The rtti is in the node constructor, dynamic binding in for insert

*/
#include "table.h"

int main()
{
    // For the do while menu selection 
    bool go = true;
    int actionNumber = 0;
    table *obj = new table;
    do
    {
        std::cout << "Enter the corresponding number for the action" << std::endl;
        std::cout << "1 to insert new question" << std::endl;
        std::cout << "2 to search for an item" << std::endl;
        std::cout << "3 to remove a question" << std::endl;
        std::cout << "4 to edit a question" << std::endl;
        std::cout << "5 to display questions" << std::endl;
        std::cout << "6 to end the program" << std::endl;
        std::cin >> actionNumber;
        std::cin.ignore();

        if (actionNumber == 1)
        {
            obj->pick();
        }

        if (actionNumber == 2)
        {
            obj->search();
        }

        if (actionNumber == 3)
        {
            obj->remove_w();
        }

        if (actionNumber == 4)
        {
            obj->edit();
        }

        if (actionNumber == 5)
        {
            obj->display();
        }

        if (actionNumber == 6)
        {
            go = false;
            delete obj;
        }

    } while (go == true);

    return 0;
}