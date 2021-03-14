#ifndef QUESTIONS_H
#define QUESTIONS_H
#include "questions.h"
#endif

/* 
Author: Nelson Wong

The algos class is a class which primarily handles storing the
questions involving algorithms, which includes information
about an algorithm's Big O. This class inherits data members
and functions form the questions class.

*/

/* Questions for algorithms */
class algos: public questions
{
    public:
        algos();
        ~algos();
        algos(const algos & src); // Copy for a new obj
        algos(int new_subject, char* new_info, char* new_ds, int new_difficulty, char* new_bigO, int new_reference); //copies for new data members
        void display() const override;
        void readIn() override;
    private:
        char* big_o_; // Char * for algorithm questions
};
