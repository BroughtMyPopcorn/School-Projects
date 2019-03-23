/*
 * Nelson Wong
   Low.h is for the base class and it's derived classes 
   App is the base class, which has biz, social, and games as it's child

 */
#include <cctype>
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <ostream>
using namespace std;

//the base class for the different apps
class apps
{
    public:
        apps();
        virtual ~apps(); //virtual destructor virtual void display(); //virtual display function
        virtual void insert(); //virtual insert
        virtual void display(); //display funct
        apps(const apps &src); //copy constructor 
        apps(char* t_type, char* t_name, char* t_des, char* t_review, int t_cost, char* t_history); //constructor for new info
        //getters and setters for the obj pointers
        apps*& getLeft();
        apps*& getRight();
        apps*& getParent();
        bool getColor();
        void setColor(bool new_color);
        char* getName();
        //---------------------------------------------------------------

        friend istream & operator>>(istream& in, class apps& app); //reads in the cost of the app
        bool operator<(apps& to_compare); //strcmp for two apps objs for neg value
        bool operator>(apps& to_compare);  //for greater than 0
        bool operator>=(apps& to_compare); //for greater or equal than 0
        bool operator==(apps& to_compare); //for strcmp 0
        bool operator<=(apps& to_compare); //less than or eqaul to 0
        bool operator==(char * compare); //compares just the apps obj and char*
        apps&operator=(char* in); //assignment for new review
        apps& operator=(int in); //assignment for int 
        apps& operator=(const apps& obj); //assignment for base class obj
        apps& operator+(const apps& src); //adds the data into one
        friend bool operator !=(const class apps& apps, const class apps& apps2); //compares two base clas types
            
    protected:
        char* type; //type of app
        char* name; //name of the apps
        char* des; //description of the apps
        char* review; //apps review
        int cost; //cost of the apps
        char* history; //apps history
        apps* left;//left ptr for tree
        apps* right; //right ptr for tree
        apps* parent;//ptr to the parent node
        bool color; //red is false, black is true;
};

//business apps 
class biz: public apps
{
    public:
        biz();
        ~biz();
        void insert();
        biz(char* t_temp, char* t_name, char* t_des, char* t_review, int t_cost, char* t_history, int t_stocks); //kick start the parents base class constructor 
        void display();
    protected:
        int stocks; //stocks is unique to biz class. Price of the stock 
};

//social media apps
class social: public apps
{
    public: 
        social();
        ~social();
        social(char* t_type, char* t_name, char* t_des, char* t_review, int t_cost, char* t_history, int t_followers);
        void display();
        void insert();
    protected:
        int followers; //how many followers the user has
};

//game apps
class games: public apps
{
    public: 
        games();
        ~games();
        void insert();
        games(char* t_type, char* t_name, char* t_des, char* t_review, int t_cost, char* t_history, int t_score);
        void display();
    protected:
        int score; //game score

};


