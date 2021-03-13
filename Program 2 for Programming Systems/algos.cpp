#include "node.h"
#include "algos.h"

/* 
Author: Nelson Wong

The algos class is a class which primarily handles storing the
questions involving algorithms, which includes information
about an algorithm's Big O. This class inherits data members
and functions form the questions class.

*/

algos::algos() {
    big_o_ = NULL;
}

algos::algos(int new_subject, char* new_info, char* new_ds, int new_difficulty, char* new_bigO, int new_reference): 
    questions(new_subject, new_info, new_ds, new_difficulty, new_reference)
{
    big_o_ = new char [strlen(new_bigO)+1];
    strcpy(big_o_, new_bigO);
}

algos::algos(const algos & src) {
    big_o_ = new char [strlen(src.big_o_)+1];
    strcpy(big_o_, src.big_o_);
}

algos::~algos() {
    if (big_o_) {
        delete [] big_o_;
    }
}

// Displays the question
void algos::display() const {
    std::cout << "For algorithms" << endl;
    std::cout << "The question is: " << info << endl;
    std::cout << "The data structure: "<< ds << endl;
    std::cout << "The difficulty /5 is: " << difficulty << endl;
    std::cout << "The big O is" << big_o_ << endl;
    std::cout << "The reference number is: " << reference << endl;
}
// Reads in information from the user
void algos::readin() {
    info = new char[1000];
    ds = new char[1000];
    big_o_ = new char[1000];

    std::cout << "The subject is algorithms" << endl;
    std::cout << "Enter a number to associate the question with" << endl;
    std::cin >> reference;
    std::cin.ignore();

    std::cout << "Enter the question" << endl;
    std::cin.get(info,1000, '\n');
    std::cin.ignore(1000,'\n');

    std::cout << "Enter the data structure that would work the best" << endl;
    std::cin.get(ds, 1000, '\n');
    std::cin.ignore(1000, '\n');

    std::cout << "Enter in the diffculty out of 5" << endl;
    std::cin >> difficulty;
    std::cin.ignore();

    std::cout << "What is the big O for this algo?" << endl;
    std::cin.get(big_o_,1000, '\n');
    std::cin.ignore(1000, '\n');
}

