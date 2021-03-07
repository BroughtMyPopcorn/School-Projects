#ifndef QUESTIONS_H
#define QUESTIONS_H
#include "questions.h"
#endif

//questions for algorithms
class algos: public questions
{
    public:
        algos();
        ~algos();
        algos(const algos & src); //copy for a new obj
        algos(int new_subject, char* new_info, char* new_ds, int new_difficulty, char* new_bigO, int new_reference); //copies for new data members
        virtual void display();
        void readin();
    protected:
        char* big_o_; //char * for algorithm questions
};
