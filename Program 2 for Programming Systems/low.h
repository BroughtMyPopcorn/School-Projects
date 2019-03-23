/*
 * This low file is for the classes that have relation to my abstract base class
 *
 */
#include <cctype>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//manages the nodes of the doubly linked list
class node
{
    public:
        node();
        ~node();
        node(const node & src);
        node*& getNext(); //returns next ptr void setNext(node* todata); //sets the next ptr node*& getPrev(); //gets the prev ptr
        node*& getPrev();
        void setPrev(node* todata); //sets the prev ptr
        void setNext(node* todata);
        void setData(int choice); //lets the user to pick which function to call
        void edit();  //allows user to edit the list
        void change();  //allows user to change the question
        class questions* getData(); //gets the ptr to question
        void display(); //calls questions' display
    protected:
        node* next; //next ptr 
        node* prev; //prev ptr
        class questions* data; //contains an questions obj 
};

//abstract base class that acts as a hub for my questions
class questions
{
    public:
        questions();
        questions(int new_subject, char* new_info, char* new_ds, int new_difficulty, int new_reference); //copies the data members 
        questions(const questions & src); //copies into a new obj
       virtual ~questions(); 
       virtual void display()=0; //pure virtual function for display
       virtual void readin()=0;// allows the user to read in the info
       int getReference();
    protected:
        int subject; //subject with an int prompt
        char *info; //question info
        char *ds; //data structure
        int difficulty; //the difficulty of the question
        int reference; //allows user to inout a number to associate the question with
        
        
};

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
        char* bigO; //char * for algorithm questions
};

