#include "node.h"


algos::algos(){
    bigO = NULL;
}

algos::~algos(){
    if(bigO) delete [] bigO;
}

algos::algos(int new_subject, char* new_info, char* new_ds, int new_difficulty, char* new_bigO, int new_reference): questions(new_subject, new_info, new_ds, new_difficulty, new_reference)
{

    bigO = new char [strlen(new_bigO)+1];
    strcpy(bigO, new_bigO);

}

algos::algos(const algos & src){
    bigO = new char [strlen(src.bigO)+1];
    strcpy(bigO, src.bigO);
}

void algos::display(){
    cout<<"For algorithms"<<endl;
    cout<<"The question is: "<<info<<endl;
    cout<<"The data structure: "<<ds<<endl;
    cout<<"The difficulty /5 is: "<<difficulty<<endl;
    cout<<"The big O is"<<bigO<<endl;
    cout<<"The reference number is: "<<reference<<endl;

}


void algos::readin(){

    cout<<"The subject is algorithms"<<endl;
    cout<<"Enter a number to associate the question with"<<endl;
    cin>>reference;
    cin.ignore();

    cout<<"Enter the question"<<endl;
    info = new char[1000];
    cin.get(info,1000, '\n');
    cin.ignore(1000,'\n');

    cout<<"Enter the data structure that would work the best"<<endl;
    ds = new char[1000];
    cin.get(ds, 1000, '\n');
    cin.ignore(1000, '\n');

    cout<<"Enter in the diffculty out of 5"<<endl;
    cin>>difficulty;
    cin.ignore();

    cout<<"What is the bigO for this algo?"<<endl;
    bigO = new char[1000];
    cin.get(bigO,1000, '\n');
    cin.ignore(1000, '\n');


}

