#include "low.h"

//apps constructor to initialize everything to NULL
apps::apps(){

    type = NULL;
    name = NULL;
    des = NULL;
    review = NULL;
    cost = 0;
    history = NULL;
    left = NULL;
    right = NULL;

}


//destructors to delete dynamic memory
apps::~apps(){

    if(type) delete [] type;
    if(name) delete [] name;
    if(des) delete [] des;
    if(review) delete [] review;
    if(history) delete [] history;

}

//reads in the cost of the the app
istream& operator>>(istream& in, class apps& apps){
    in>>apps.cost;
    return in;

}

//the default display function for the base class
void apps::display(){

    cout<<"App name: "<<name<<endl;
    cout<<"Description: "<<des<<endl;
    cout<<"Review: "<<review<<endl;
    cout<<"Cost: "<<cost<<endl;
    cout<<"App history: "<<history<<endl;

}

//if strcmp is a  neg value, return true
bool apps::operator<(apps& to_compare){ 

    return strcmp(this->name, to_compare.name) < 0;

}
//strcmp positive val
bool apps::operator>(apps& to_compare){ 

    return strcmp(this->name, to_compare.name) > 0;
}

//strcmp greater or equal
bool apps::operator>=(apps& to_compare){  

    return strcmp(this->name, to_compare.name) >= 0;
}

//strcmp is a neg value
bool apps::operator<=(apps& to_compare){ 
    return strcmp(this->name, to_compare.name) <  0;
}

//when strcmp is 0
bool apps::operator==(char * compare){ 

    return strcmp(this->name, compare) ==0;
}

//when stcmp between obj is 0
bool apps::operator==(apps& to_compare){  
    return strcmp(this->name, to_compare.name)==0;
}


//compares if the char is the same as review and returns a new one if not for = operator
apps& apps::operator=(char* in){
    if(strcmp(this->review, in)==0){
        return *this;
    }

    delete [] this;
    this->review = new char [strlen(in)+1];
    strcpy(this->review, in);
    return *this;
}

//compares if the cost is the same for the = operator
apps& apps::operator=(int in){
    if(this->cost == in){
        return *this;
    }

    delete this;
    this->cost = in;
    return *this;
}


//sees if the app obj is the same and if not, make a new one
apps& apps::operator=(const apps &src){
    if(this == &src) return *this;

    else{
        type = new char [strlen(src.type)];
        strcpy(type, src.type);
        name = new char [strlen(src.name)+1];
        strcpy(name, src.name);
        des = new char [strlen(src.des)+1];
        strcpy(des, src.des);
        review = new char [strlen(src.review)+1];
        strcpy(review, src.review);
        cost = src.cost;
        history = new char [strlen(src.history)+1];
        strcpy(history, src.history);
    }

    return *this;
}


//makes a temp app obj and copes both sources into one and returns temp app

apps& apps::operator+(const apps& src){
     apps temp;
    temp.name = new char [strlen(name)+ strlen(src.name)+1];
    strcpy(temp.name, name);
    strcat(temp.name, src.name);

    temp.des = new char [strlen(des)+ strlen(src.des)+1];
    strcpy(temp.des, des);
    strcat(temp.des, src.des);

    temp.review = new char [strlen(review)+ strlen(src.review)+1];
    strcpy(temp.review, review);
    strcat(temp.review, src.review);

    temp.cost = cost + src.cost;

    temp.history = new char [strlen(history) + strlen(src.history)+1];
    strcpy(temp.history, history);
    strcat(temp.history, src.history);

    return *this;

}

//compares the data of the base class objects
bool operator !=(const class apps& apps, const class apps& apps2){

    if(apps.cost != apps2.cost){
        if((strcmp(apps.name, apps2.name) != 0) or (strcmp(apps.des, apps2.des)!= 0) or (strcmp(apps.review, apps2.review)!=0) or (strcmp(apps.history, apps2.history)!=0)){
            return true;
        }
    }
    return false;

}

//--------------------------------------------
//insert function for user data, not from external file
void apps::insert(){
    cout<<"Enter the app name"<<endl;
    name = new char[1000];
    cin.get(name, 1000, '\n');
    cin.ignore(1000, '\n');

    cout<<"Enter the app description"<<endl;
    des = new char[1000];
    cin.get(des, 1000, '\n');
    cin.ignore(1000, '\n');

    cout<<"Enter an app review"<<endl;
    //review = new char[100];
    char* temp = new char[1000];
    cin.get(temp, 1000, '\n');
    cin.ignore(1000, '\n');
    review = temp; //uses operator overloading 
    //  cin.get(review, 1000, '\n');
    // cin.ignore(1000, '\n');

    cout<<"Enter in the app cost (int)"<<endl;
    cin>>cost;
    cin.ignore();

    cout<<"When you did you access the app"<<endl;
    history = new char[1000];
    cin.get(history, 10000, '\n');
    cin.ignore(1000, '\n');

}


//copy constrcutor for the base class
apps::apps(const apps & src){

    type = new char [strlen(src.type)];
    strcpy(type, src.type);
    name = new char [strlen(src.name)+1];
    strcpy(name, src.name);
    des = new char [strlen(src.des)+1];
    strcpy(des, src.des);
    review = new char [strlen(src.review)+1];
    strcpy(review, src.review);
    cost = src.cost;
    history = new char [strlen(src.history)+1];
    strcpy(history, src.history);
    left = NULL;
    right = NULL;

}

//copy function for the data members 
apps::apps(char* t_type, char* t_name, char* t_des, char* t_review, int t_cost, char* t_history){

    type = new char [strlen(t_type)+1];
    strcpy(type, t_type);
    name = new char [strlen(t_name)+1];
    strcpy(name, t_name);
    des = new char [strlen(t_des)+1];
    strcpy(des, t_des);
    review = new char [strlen(t_review)+1];
    cost = t_cost;
    history = new char[strlen(t_history)+1];
    strcpy(history, t_history);
    left = NULL;
    right = NULL;

}

//getters for the left and right ptrs cuz its needed in tree class
apps*& apps::getLeft(){
    return left;
}

apps*& apps::getRight(){
    return right;
}

apps*& apps::getParent(){
    return parent;
}

char* apps::getName(){
    return name;
}

bool apps::getColor(){
    return color;
}

void apps::setColor(bool new_color){
    color = new_color;
}

//--------------------------------------------

//biz class constructor 
biz::biz(){
    stocks = 0;
}

biz::~biz(){
}

//copy function for the data members w/ base class initialization 
biz::biz(char* t_type, char* t_name, char* t_des, char* t_review, int t_cost, char* t_history, int t_stocks): apps(t_type, t_name, t_des, t_review, t_cost, t_history)
{
    stocks = t_stocks; //assign the temp stock to stock
}

//calls the default insert function and lets the user enter in stock info
void biz::insert(){

    apps::insert();
    cout<<"Enter in the stock price (int)"<<endl;
    cin>>stocks;
    cin.ignore();

}
//biz class display
void biz::display(){

    cout<<"---------------------------"<<endl; 
    cout<<"This is a business app"<<endl;
    apps::display();
    cout<<"Stocks: "<<stocks<<endl;
}

//-------------------------------------

social::social(){
    followers = 0;
}

social::~social(){
}

//social class copy function
social::social(char* t_type, char* t_name, char* t_des, char* t_review, int t_cost, char* t_history, int t_followers): apps(t_type, t_name, t_des, t_review, t_cost, t_history){

    followers = t_followers;
}
//social class insert
void social::insert(){

    apps::insert();
    cout<<"Enter in the amount of followers (int)"<<endl;
    cin>>followers;
    cin.ignore();

}
//social class display
void social::display(){

    cout<<"------------------------------------"<<endl;
    cout<<"This is a social media app"<<endl;
    apps::display();
    cout<<"Number of followrs: "<<followers<<endl;
}

//--------------------------------------------

games::games(){
    score = 0;
}

games::~games(){
}

//games class insert
void games::insert(){

    apps::insert();
    cout<<"Enter in the game score (int)"<<endl;
    cin>>score;
    cin.ignore();
}

//game class copy function
games::games(char* t_type, char* t_name, char* t_des, char* t_review, int t_cost, char* t_history, int t_score): apps(t_type, t_name, t_des, t_review, t_cost, t_history){
    score = t_score;
}

//games class display
void games::display(){

    cout<<"------------------------------------------------"<<endl;
    cout<<"This is a game app"<<endl;
    apps::display();
    cout<<"Game score: "<<score<<endl;
}
