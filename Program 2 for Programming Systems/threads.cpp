#include "node.h"
#include "threads.h"

/* threads constructor */
threads::threads() {
    thread_count_ = 0; 
}

/* threads destructor */
threads::~threads() {}

/* threads copy constructor */
threads::threads(int new_subject, char* new_info, char* new_ds, int new_difficulty, int new_reference, int new_tc):
questions(new_subject, new_info, new_ds, new_difficulty, new_reference), thread_count_(new_tc) {}

/* threads copy constructor */
threads::threads(const threads & src) {
    thread_count_ = src.thread_count_;
}

/* display all the threads questions */
void threads::display() const {
    std::cout << "For threads" << endl;
    std::cout << "The question is: " << info_ << endl;
    std::cout << "The data structure: " << data_structure_ << endl;
    std::cout << "The difficulty /5 is: " << difficulty_ << endl;
    std::cout << "The thread count is: " <<  thread_count_  <<  endl;
    std::cout << "The reference number is: " << reference_ << endl;
}

/* read in user inputs for question details */
void threads::readIn() {
    std::cout << "The subject is threads" << endl;
   
    std::cout << "Enter a number to associate the question with" << endl;
    std::cin >> reference_;
    std::cin.ignore();

    std::cout << "Enter the question" << endl;
    info_ = new char[1000];
    std::cin.get(info_, 1000, '\n');
    std::cin.ignore(1000,'\n');

    std::cout << "Enter the data structure that would work the best" << endl;
    data_structure_ = new char[1000];
    std::cin.get(data_structure_, 1000, '\n');
    std::cin.ignore(1000, '\n');

    std::cout << "Enter in the difficulty out of 5" << endl;
    std::cin >> difficulty_;
    std::cin.ignore();

    std::cout << "How many threads does it have?" << endl;
    std::cin >> thread_count_;
    std::cin.ignore();
}

