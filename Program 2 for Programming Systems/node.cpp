#include "node.h"
#include "algos.h"
#include "threads.h"
#include "parallel.h"

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
