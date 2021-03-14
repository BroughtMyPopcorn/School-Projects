#include <string.h>

/*  Base class that act as hub for other derived classes.
    Any virtual functions within this class must be implement by inherited classes */
class questions
{
    public:
        questions();
        questions(int new_subject, char *new_info, char *new_ds, int new_difficulty, int new_reference); //copies the data members
        questions(const questions &src);                                                                 //copies into a new obj
        virtual ~questions();
        virtual void display() const = 0;     // Any children must implement this function
        virtual void readIn() = 0;      // Any children must implement this function
        int getReference();
    protected:
        int subject_; //subject with an int prompt
        char *info_; //question info
        char *data_structure_; //data structure
        int difficulty_; //the difficulty of the question
        int reference_; //allows user to inout a number to associate the question with
        
        
};
