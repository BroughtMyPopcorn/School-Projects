#ifndef QUESTIONS_H
#define QUESTIONS_H
#include "questions.h"
#endif

//questions about threads
class threads: public questions
{
    public:
        threads();
        ~threads();
        threads(const threads & src); //copy for a new obj
        threads(int new_subject, char* new_info, char* new_ds, int new_difficulty, int new_tc, int new_reference); //copies data members 
        void display() const override;
        void readin() override;
    private:
        int tc; //how many threads are used;
};
