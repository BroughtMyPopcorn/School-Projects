#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;
//manages the nodes of the doubly linked list
class node {
public:
    node();
    ~node();
    node(const node &src);
    node *&getNext();
    node *&getPrev();
    void setPrev(node *previousTopic);
    void setNext(node *nextTopic);
    void setQuestion(int topicChoice);  // sets a question for the topic choice
    void editQuestion();                //allows user to edit the list
    class questions *getQuestionData(); //gets the ptr to question
    void displayQuestions();            //calls questions' display

    private:
    node *next_;
    node *prev_;
    class questions *data_;
};
