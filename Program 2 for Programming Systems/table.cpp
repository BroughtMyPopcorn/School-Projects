#include "table.h"

table::table()
{

    index = new list *[NUM]; // make a new array with 3 elements

    for (int i = 0; i < NUM; i++)
    {
        index[i] = NULL;
    }
    // ref = 0;
    arrIndex = 0;
}

table::~table()
{

    //deallocates the array
    for (int i = 0; i < NUM; i++)
    {
        if (index[i])
        {
            delete index[i];
            index[i] = NULL;
        }
    }

    if (index)
    {
        delete[] index;
    }
}

int table::edit()
{
    int toedit;
    std::cout << "enter in the question ref to edit" << std::endl;
    std::cin >> toedit;

    for (int i = 0; i < NUM; i++)
    {
        if (index[i])
        {
            index[i]->search(toedit);
            int catchh = index[i]->delete_item(toedit);
            if (catchh == 1)
            {
                pick();
            }
        }
    }
    return 0;
}

int table::remove_w()
{
    int del;
    std::cout << "enter in a reference num to delete: " << std::endl;
    std::cin >> del;
    std::cin.ignore();
    for (int i = 0; i < NUM; i++)
    {
        if (index[i])
        {
            index[i]->delete_item(del);
        }
    }

    return 1;
}

void table::search()
{
    int ref = 0;
    std::cout << "Which reference number do you want to search for" << std::endl;
    std::cin >> ref;
    std::cin.ignore();

    for (int i = 0; i < NUM; i++)
    {
        if (index[i])
        {
            index[i]->search(ref);
        }
    }

    return;
}

void table::pick()
{
    int choice;
    std::cout << "what type of question do you want to add?" << std::endl;
    std::cout << "Enter 1 for parallel programming" << std::endl;
    std::cout << "Enter 2 for threads" << std::endl;
    std::cout << "Enter 3 for algorithms" << std::endl;
    std::cin >> choice;
    std::cin.ignore(100, '\n');
    if (index[choice - 1] == NULL)
    {
        index[choice - 1] = new list();
    }

    index[choice - 1]->insert(choice);
}

void table::display()
{

    int pick = 0;
    // if(!head) return;
    std::cout << "Which type of question do you want to display" << std::endl;
    std::cout << "1 for parallel programming" << std::endl;
    std::cout << "2 for threads" << std::endl;
    std::cout << "3 for algorithms" << std::endl;

    std::cin >> pick;
    std::cin.ignore(100, '\n');
    if (pick == 1 && index[0])
    {
        index[0]->display();
    }
    else if (pick == 2 && index[1])
    {
        index[1]->display();
    }
    else if (pick == 3 && index[2])
    {
        index[2]->display();
    }
}
