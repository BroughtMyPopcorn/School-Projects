#include "node.h"
#include "parallel.h"

parallel::parallel() {
    cores_ = 0;
}

parallel::~parallel() {}

//copy constructor
parallel::parallel(const parallel & src) {
    cores_ = src.cores_;
}

/* Fully utilize the initialization list */
parallel::parallel(int new_subject, char* new_info, char* new_ds, int new_difficulty, int new_cores, int new_reference): 
    questions(new_subject, new_info, new_ds, new_difficulty, new_reference), cores_(new_cores) {}

/* Displaying the data members of the class */
void parallel::display() const {
    cout << "For parallel programming" << endl;
    cout << "The question is: " << info_ << endl;
    cout << "The data structure: " << data_structure_ << endl;
    cout << "The difficulty /5 is: " << difficulty_ << endl;
    cout << "It has " << cores_ << " cores" << endl;
    cout << "The reference number is: " << reference_ << endl;
}

/* Read in data for the data members of the class */
void parallel::readIn() {
    cout << "The subject is parallel programming" << endl;
    cout << "Enter a number to associate the question with" << endl;
    cin >> reference_;
    cin.ignore();

    cout << "Enter the question" << endl;
    info_ = new char[1000];
    cin.get(info_, 1000, '\n');
    cin.ignore(1000,'\n');

    cout << "Enter the data structure that would work the best" << endl;
    data_structure_ = new char[1000];
    cin.get(data_structure_, 1000, '\n');
    cin.ignore(1000, '\n');

    cout << "Enter in the difficulty out of 5" << endl;
    cin >> difficulty_;
    cin.ignore();       // Added in the safety measure for cin

    cout << "How many cores does it have" << endl;
    cin >> cores_;
    cin.ignore();       // Added in the safety measure for cin
}
