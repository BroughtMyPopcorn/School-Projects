#include "low.h"

//node constructor to set data
node::node(){
    next = NULL;
    prev = NULL;
    data = NULL;
}

//node company constructor for data
node::node(const node & src){
 
  if(typeid(*src.data) == typeid(parallel)){
        parallel* ptr = dynamic_cast<parallel*>(src.data);
        data = new parallel(*(ptr));
    }

    if(typeid(*src.data) == typeid(threads)){
        threads* ptr = dynamic_cast<threads*>(src.data);
        data = new threads(*(ptr));
    }

    if(typeid(*src.data) == typeid(algos)){
        algos* ptr = dynamic_cast<algos*>(src.data);
        data = new algos(*(ptr));
    }

    data = src.data;

}


//node destructor to deallocate data
node::~node(){
    /*
    if(next) delete next;
    if(prev) delete prev;
    */
    if(data) delete data;
}

node*& node::getNext(){
    return next;
}


void node::setNext(node* todata){

    next = todata;
}

node*& node::getPrev(){

    return prev;
}

void node::setPrev(node* todata){

    prev = todata;
}

questions* node::getData(){
    return data;
}

void node::display(){
    
    data->display();
}
void node::setData(int choice){

    if(choice == 1){
        data = new parallel;
        data->readin();
    }

    if(choice == 2){
        data = new threads;
        data->readin();
    }
    if(choice == 3){
        data = new algos;
        data->readin();
    }

}


//---------------------------------------------------

//constructor for base class
questions::questions(){

    subject = 0;
    info = NULL;
    ds = NULL;
    difficulty = 0;
    reference = 0;
}

//destructor 
questions::~questions(){

    if(info) delete [] info;
    if(ds) delete [] ds;
}

//copy constructor when inserting the data into a node
questions::questions(const questions & src){
    subject = src.subject;
    info = new char [strlen(src.info)+1];
    strcpy(info, src.info);
    ds = new char [strlen(src.ds)+1];
    difficulty = src.difficulty;
    reference = src.reference;
}

//copy constructor when aggregating new data
questions::questions(int new_subject, char* new_info, char* new_ds, int new_diffculty, int new_reference){

    subject = new_subject;
    info = new char [strlen(new_info)+1];
    strcpy(info, new_info);
    ds = new char [strlen(new_ds)+1];
    difficulty = new_diffculty;
    reference = new_reference;

}
int questions::getReference(){
    return reference;
}
//---------------------------------------------------------

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

//------------------------------------------------------

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



//-----------------------------------------------------

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

