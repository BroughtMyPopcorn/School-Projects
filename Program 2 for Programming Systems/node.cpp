#include "node.h"
#include "algos.h"
#include "threads.h"
#include "parallel.h"

node::node()
{
    next_ = NULL;
    prev_ = NULL;
    data_ = NULL;
}

//node company constructor for data
node::node(const node &src)
{

    if (typeid(*src.data_) == typeid(parallel))
    {
        parallel *ptr = dynamic_cast<parallel *>(src.data_);
        data_ = new parallel(*(ptr));
    }

    if (typeid(*src.data_) == typeid(threads))
    {
        threads *ptr = dynamic_cast<threads *>(src.data_);
        data_ = new threads(*(ptr));
    }

    if (typeid(*src.data_) == typeid(algos))
    {
        algos *ptr = dynamic_cast<algos *>(src.data_);
        data_ = new algos(*(ptr));
    }

    data_ = src.data_;
}

node::~node()
{

    if (data_)
        delete data_;
}

/* Getters and setters */

node *&node::getNext()
{
    return next_;
}

void node::setNext(node *nextTopic)
{

    next_ = nextTopic;
}

node *&node::getPrev()
{

    return prev_;
}

void node::setPrev(node *prevTopic)
{

    prev_ = prevTopic;
}

questions *node::getQuestionData()
{
    return data_;
}

/* Operation functions */

void node::displayQuestions()
{

    data_ -> display();
}
void node::setQuestion(int choice)
{

    if (choice == 1)
    {
        data_ = new parallel;
        data_ -> readIn();
    }

    if (choice == 2)
    {
        data_ = new threads;
        data_ -> readIn();
    }
    if (choice == 3)
    {
        data_ = new algos;
        data_ -> readIn();
    }
}
