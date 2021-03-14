#ifndef QUESTIONS_H
#define QUESTIONS_H
#include "questions.h"
#endif

/*  Threads is derived from the class 'questions'.
    It contains additional data members that is important
    to the concept of threads */
class threads: public questions
{
    public:
        threads();
        ~threads();
        threads(const threads & src); //copy for a new obj
        threads(int new_subject, char* new_info, char* new_ds, int new_difficulty, int new_tc, int new_reference); //copies data members 
        void display() const override;
        void readIn() override;
    private:
        int thread_count_; //how many threads are used;
};
