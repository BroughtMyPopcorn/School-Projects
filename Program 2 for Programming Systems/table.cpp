#include "table.h"

/* table constructor */
table::table() {
    index_ = new list * [NUM];// make a new array with 3 elements
    for (int i = 0; i < NUM; i++) {
        index_[i] = NULL;
    }
}

/* table destructor */
table::~table() {
    //deallocates the array
    for (int i = 0; i < NUM; i++) {
        if (index_[i]) {
            delete index_[i];
            index_[i] = NULL;
        }
    }

    if (index_) {
        delete [] index_;
    }
}

/* call proper display function for type of question chosen */
void table::display() {
    int pick = 0;
    std::cout << "Which type of question do you want to display?" << endl;
    std::cout << "Enter 1 for parallel programming" << endl;
    std::cout << "Enter 2 for threads" << endl;
    std::cout << "Enter 3 for algorithms" << endl;
    std::cin >> pick;
    std::cin.ignore(100, '\n');
  
    if (pick == 1 && index_[0]) {
        index_[0] -> display();
    }
    else if (pick == 2 && index_[1]) {
        index_[1] -> display();
    }
    else if (pick == 3 && index_[2]) {
        index_[2] -> display();
    }
}

/* User selects which type of question to add */
void table::pick() {
    int choice;
    std::cout << "What type of question do you want to add?" << endl;
    std::cout << "Enter 1 for parallel programming" << endl;
    std::cout << "Enter 2 for threads" << endl;
    std::cout << "Enter 3 for algorithms" << endl;
    std::cin >> choice;
    std::cin.ignore(100, '\n');

    if (index_[choice-1] == NULL) {
        index_[choice-1] = new list();
    }
    index_[choice-1] -> insert(choice);
}

/* user can search for a specific reference number to display
 * returns 0 for success, 1 for failure*/
int table::search() {
    int reference_num = 0;
    int found = 1;
    std::cout << "Which reference number do you want to search for:" << endl;
    std::cin >> reference_num;
    std::cin.ignore();

    for (int i = 0; i < NUM; i++) {
        if (index_[i]) {
            found = index_[i] -> search(reference_num);
        }
    }
    return found; //success is 0, failure is 1
}

/* user removes a question with a specific reference number
 * return 0 for success, 1 for failure. */
int table::remove() {
    int delete_num;
    int deleted = 1;
    std::cout << "Enter in a reference num to delete:" << endl;
    std::cin >> delete_num;
    std::cin.ignore();

    for (int i = 0; i < NUM; i++) {
        if (index_[i]) {
            deleted = index_[i] -> deleteItem(delete_num); //catch result
        }
    }
    return deleted; //success is 0, failure is 1
}

/* user can edit a question that already exists
 * returns 1 for success, 0 for failure*/
int table::edit() {
    int to_edit;
    int edited = 1;
    std::cout << "Enter in the question's reference number you want to edit:" << endl;
    std::cin >> to_edit;

    for (int i = 0; i < NUM; i++) {
        if (index_[i]) {
            index_[i] -> search(to_edit);
            int match = index_[i] -> deleteItem(to_edit);
            if (match == 1) {
                pick();
                edited = 0;
            }
        }
    }
    return edited; //success is 0, failure is 1
}





