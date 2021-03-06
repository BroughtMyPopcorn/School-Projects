#include "node.h"
#include "questions.h"

/* Default Constructor */
questions::questions() {
    subject_ = 0;
    info_ = NULL;
    data_structure_ = NULL;
    difficulty_ = 0;
    reference_ = 0;
}

/* Class Destructor */
questions::~questions() {
    if (info_) { delete [] info_; }
    if (data_structure_) { delete [] data_structure_; }
}

/* Copy Constructor */
questions::questions(const questions & src) {
    subject_ = src.subject_;
    info_ = new char [strlen(src.info_)+1];
    strncpy(info_, src.info_,strlen(info_));                // There might be vulnerability here for overflow
    data_structure_ = new char [strlen(src.data_structure_)+1];
    strncpy(data_structure_,src.data_structure_, strlen(data_structure_));                      //Tu added in this part. Not sure if needed yet
    difficulty_ = src.difficulty_;
    reference_ = src.reference_;
}

/* Constructor with arguments */
questions::questions(int new_subject, char* new_info, char* new_ds, int new_difficulty, int new_reference) {
    subject_ = new_subject;
    info_ = new char [strlen(new_info)+1];
    strncpy(info_, new_info, strlen(info_));
    data_structure_ = new char [strlen(new_ds)+1];
    strncpy(data_structure_, new_ds, strlen(data_structure_));                     
    difficulty_ = new_difficulty;
    reference_ = new_reference;
}
 /* Getter function that return the data member reference */
int questions::getReference() {
    return reference_;
}
