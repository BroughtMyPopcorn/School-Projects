/*
 *This table.h file is the top-level DS and holds a list for each question type.
 *
 */

#include "node.h"
#include "list.h"

const int NUM = 3;

//the table class manages the double ptr to the list class(array)
class table
{
    public:
        table();
        ~table();
        void display(); //calls display on selected list
        void pick(); //picks which question to insert
        int search(); //searches lists for reference number to display
        int remove(); //searches lists for reference number to remove
        int edit(); //searches lists for reference number to replace
    private:
        class list** index_; //double ptr to dynamically allocate the array
};



