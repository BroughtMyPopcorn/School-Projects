#ifndef QUESTIONS_H
#define QUESTIONS_H
#include "questions.h"
#endif

//questions for parallel programming
class parallel: public questions
{
    public:
        parallel();
        ~parallel();
        parallel(const parallel & src); //copies into a new obj
        parallel(int new_subject, char* new_info, char* new_ds, int new_difficulty, int new_cores, int new_reference); //copies the data members
        virtual void display(); 
        void readin();
    protected:
        int cores; //user inserts how many cores are used 


};
