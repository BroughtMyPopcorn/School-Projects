#include "node.h"


parallel::parallel(){
    cores = 0;
}

parallel::~parallel(){
}

//copy constructor
parallel::parallel(const parallel & src){

    cores = src.cores;

}

//copies the parallel data members 
parallel::parallel(int new_subject, char* new_info, char* new_ds, int new_difficulty, int new_cores, int new_reference): questions(new_subject, new_info, new_ds, new_difficulty, new_reference)
{
    cores = new_cores;
}

//display the contents for parallel 
void parallel::display(){
    cout<<"For parallel programming"<<endl;
    cout<<"The question is: "<<info<<endl;
    cout<<"The data structure: "<<ds<<endl;
    cout<<"The difficulty /5 is: "<<difficulty<<endl;
    cout<<"It has "<<cores<<" cores"<<endl;
    cout<<"The reference number is: "<<reference<<endl;
}

//allows the user to insert the data 
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

    cout<<"Enter in the diffculty out of 5"<<endl;
    cin>>difficulty;

    cout<<"How many cores does it have"<<endl;
    cin>>cores;

}
