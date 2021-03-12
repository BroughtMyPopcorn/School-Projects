#ifndef QUESTIONS_H
#define QUESTIONS_H
#include "questions.h"
#endif

/*  Parallel is derived from the class 'questions'.
    It contains additional data members that is important
    to the concept of parallel programming */
class parallel: public questions
{
    public:
        parallel();     
        ~parallel();
        parallel(const parallel & src); // copies into a new obj
        parallel(int new_subject, char* new_info, char* new_ds, int new_difficulty, int new_cores, int new_reference); 
        void display() const override;         // Override the display function from parent class
        void readin() override;

    private:
        int cores; //user inserts how many cores are used 
};
