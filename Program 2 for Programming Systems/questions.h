//abstract base class that acts as a hub for my questions
class questions
{
    public:
        questions();
        questions(int new_subject, char *new_info, char *new_ds, int new_difficulty, int new_reference); //copies the data members
        questions(const questions &src);                                                                 //copies into a new obj
        virtual ~questions();
        virtual void display() = 0; //pure virtual function for display
        virtual void readin() = 0;  // allows the user to read in the info
        int getReference();
    protected:
        int subject; //subject with an int prompt
        char *info; //question info
        char *ds; //data structure
        int difficulty; //the difficulty of the question
        int reference; //allows user to inout a number to associate the question with
        
        
};
