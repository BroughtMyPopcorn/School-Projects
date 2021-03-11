/*
Nelson Wong
CS202 
For this program, it allows the user to manipulate questions that are inserted in a array of doubly linked lists
The rtti is in the node constructor, dynamic binding in for insert

*/
#include "table.h"

int main()
{
    bool go = true;
    int cont = 0;
    table *obj = new table;
    do
    {
        std::cout << "1 for insert new question" << std::endl;
        std::cout << "2 for search for an item" << std::endl;
        std::cout << "3 to remove a question" << std::endl;
        std::cout << "4 to edit a question" << std::endl;
        std::cout << "5 to display questions" << std::endl;
        std::cout << "6 to end the prog" << std::endl;
        std::cin >> cont;
        std::cin.ignore();

        if (cont == 1)
        {
            obj->pick();
        }

        if (cont == 2)
        {
            obj->search();
        }

        if (cont == 3)
        {
            obj->remove_w();
        }

        if (cont == 4)
        {
            obj->edit();
        }

        if (cont == 5)
        {
            obj->display();
        }

        if (cont == 6)
        {
            go = false;
            delete obj;
        }

    } while (go == true);

    return 0;
}