//questions about threads
class threads: public questions
{
    public:
        threads();
        ~threads();
        threads(const threads & src); //copy for a new obj
        threads(int new_subject, char* new_info, char* new_ds, int new_difficulty, int new_tc, int new_reference); //copies data members 
        virtual void display();
        void readin();
    protected: 
        int tc; //how many threads are used;
};
