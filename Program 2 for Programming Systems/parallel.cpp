#include "node.h"
#include "parallel.h"

parallel::parallel(){
    cores = 0;
}

parallel::~parallel() {}

//copy constructor
parallel::parallel(const parallel & src){
    cores = src.cores;
}

/* Fully utilize the initialization list */
parallel::parallel(int new_subject, char* new_info, char* new_ds, int new_difficulty, int new_cores, int new_reference): 
    questions(new_subject, new_info, new_ds, new_difficulty, new_reference), cores(new_cores) {}

/* Displaying the data members of the class */
void parallel::display() const {
    cout<<"For parallel programming"<<endl;
    cout<<"The question is: "<<info<<endl;
    cout<<"The data structure: "<<ds<<endl;
    cout<<"The difficulty /5 is: "<<difficulty<<endl;
    cout<<"It has "<<cores<<" cores"<<endl;
    cout<<"The reference number is: "<<reference<<endl;
}

/* Read in data for the data members of the class */
void parallel::readin(){
    cout<<"The subject is parallel programming"<<endl;
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

    cout<<"Enter in the difficulty out of 5"<<endl;
    cin>>difficulty;
    cin.ignore();       // Added in the safety measure for cin

    cout<<"How many cores does it have"<<endl;
    cin>>cores;
    cin.ignore();       // Added in the safety measure for cin
}
