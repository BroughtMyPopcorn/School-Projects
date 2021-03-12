#include "node.h"
#include "algos.h"

algos::algos(){
    big_o_ = NULL;
}

algos::algos(int new_subject, char* new_info, char* new_ds, int new_difficulty, char* new_bigO, int new_reference): 
    questions(new_subject, new_info, new_ds, new_difficulty, new_reference)
{
    big_o_ = new char [strlen(new_bigO)+1];
    strcpy(big_o_, new_bigO);
}

algos::algos(const algos & src){
    big_o_ = new char [strlen(src.big_o_)+1];
    strcpy(big_o_, src.big_o_);
}

algos::~algos(){
    if (big_o_) {
        delete [] big_o_;
    }
}

void algos::display(){
    cout << "For algorithms" << endl;
    cout << "The question is: " << info << endl;
    cout << "The data structure: "<< ds << endl;
    cout << "The difficulty /5 is: " << difficulty << endl;
    cout << "The big O is" << big_o_ << endl;
    cout << "The reference number is: " << reference << endl;
}


void algos::readin(){
    cout << "The subject is algorithms" << endl;
    cout << "Enter a number to associate the question with" << endl;
    cin >> reference;
    cin.ignore();

    cout << "Enter the question" << endl;
    info = new char[1000];
    cin.get(info,1000, '\n');
    cin.ignore(1000,'\n');

    cout << "Enter the data structure that would work the best" << endl;
    ds = new char[1000];
    cin.get(ds, 1000, '\n');
    cin.ignore(1000, '\n');

    cout << "Enter in the diffculty out of 5" << endl;
    cin >> difficulty;
    cin.ignore();

    cout << "What is the big_o_ for this algo?" << endl;
    big_o_ = new char[1000];
    cin.get(big_o_,1000, '\n');
    cin.ignore(1000, '\n');
}

