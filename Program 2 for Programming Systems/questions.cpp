#include "node.h"
#include "questions.h"

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
    if(info) { delete [] info; }
    if(ds) { delete [] ds; }
}

//copy constructor when inserting the data into a node
questions::questions(const questions & src){
    subject = src.subject;
    info = new char [strlen(src.info)+1];
    strncpy(info, src.info,strlen(info));                // There might be vulnerability here for overflow
    ds = new char [strlen(src.ds)+1];
    strncpy(ds,src.ds, strlen(ds));                      //Tu added in this part. Not sure if needed yet
    difficulty = src.difficulty;
    reference = src.reference;
}

//copy constructor when aggregating new data
questions::questions(int new_subject, char* new_info, char* new_ds, int new_diffculty, int new_reference){
    subject = new_subject;
    info = new char [strlen(new_info)+1];
    strncpy(info, new_info, strlen(info));
    ds = new char [strlen(new_ds)+1];
    strncpy(ds, new_ds, strlen(ds));                     //Tu added in this part
    difficulty = new_diffculty;
    reference = new_reference;
}

int questions::getReference(){
    return reference;
}
