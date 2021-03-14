#include "node.h"
#include "parallel.h"

/* Default Constructor */
parallel::parallel() {
    cores_ = 0;
}

/* Class Destructor */
parallel::~parallel() {}

/* Copy Constructor */
parallel::parallel(const parallel & src) {
    cores_ = src.cores_;
}

/* Constructor with arguments */
parallel::parallel(int new_subject, char* new_info, char* new_ds, int new_difficulty, int new_cores, int new_reference): 
    questions(new_subject, new_info, new_ds, new_difficulty, new_reference), cores_(new_cores) {}

/* Displaying the data members of the class */
void parallel::display() const {
    std::cout << "For parallel programming" << std::endl;
    std::cout << "The question is: " << info_ << std::endl;
    std::cout << "The data structure: " << data_structure_ << std::endl;
    std::cout << "The difficulty /5 is: " << difficulty_ << std::endl;
    std::cout << "It has " << cores_ << " cores" << std::endl;
    std::cout << "The reference number is: " << reference_ << std::endl;
}

/* Read in data for the data members of the class */
void parallel::readIn() {
    std::cout << "The subject is parallel programming" << std::endl;
    std::cout << "Enter a number to associate the question with" << std::endl;
    std::cin >> reference_;
    std::cin.ignore();

    std::cout << "Enter the question" << std::endl;
    info_ = new char[1000];
    std::cin.get(info_, 1000, '\n');
    std::cin.ignore(1000,'\n');

    std::cout << "Enter the data structure that would work the best" << std::endl;
    data_structure_ = new char[1000];
    std::cin.get(data_structure_, 1000, '\n');
    std::cin.ignore(1000, '\n');

    std::cout << "Enter in the difficulty out of 5" << std::endl;
    std::cin >> difficulty_;
    std::cin.ignore();       

    std::cout << "How many cores does it have" << std::endl;
    std::cin >> cores_;
    std::cin.ignore();       
}
