#include "node.h"
#include "questions.h"
#include "threads.h"

threads::threads(){
    tc = 0; 
}

threads::~threads(){
}

threads::threads(int new_subject, char* new_info, char* new_ds, int new_difficulty, int new_reference, int new_tc): questions(new_subject, new_info, new_ds, new_difficulty, new_reference)
{
    tc = new_tc;
}

threads::threads(const threads & src){

    tc = src.tc;

}

void threads::display(){
    cout<<"For threads"<<endl;
    cout<<"The question is: "<<info<<endl;
    cout<<"The data structure: "<<ds<<endl;
    cout<<"The difficulty /5 is: "<<difficulty<<endl;
    cout<<"The thread count is: "<<endl;
    cout<<"The reference number is: "<<reference<<endl;

}

void threads::readin(){
    cout<<"The subject is threads"<<endl;
   
    cout<<"Enter a number to associate the question with"<<endl;
    cin>>reference;
    cin.ignore();

    cout<<"Enter the question"<<endl;
    info = new char[1000];
    cin.get(info, 1000, '\n');
    cin.ignore(1000,'\n');

    cout<<"Enter the data structure that would work the best"<<endl;
    ds = new char[1000];
    cin.get(ds, 1000, '\n');
    cin.ignore(1000, '\n');

    cout<<"Enter in the diffculty out of 5"<<endl;
    cin>>difficulty;
    cin.ignore();

    cout<<"How many threads does it have?"<<endl;
    cin>>tc;
    cin.ignore();
}

