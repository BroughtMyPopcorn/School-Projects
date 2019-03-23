/*
    Nelson Wong
   This h file is for classes that have a containing relationship
   this is nice so that the file structure can have some seperation

 */
#include "low.h"

//this class allows the manipulation of app in a tree data structure
class tree
{
    public:
        tree();
        ~tree();
        void insert(apps*& to_add);  //insert wrapper
        int display()const; //display wrapper
        void search(char* find); //search wrapper
       // void userInsert(); //allows user insert to tree
        int readin(); //read in from external file
        void fixWrap(apps*& root, apps*& curr); //fixes the bst into a Red-Black 
        //Operator Overloading--------------------------
        
        friend ostream& operator<<(ostream& out, const tree& s);
        tree& operator+=(apps *to_add);
       // tree& operator+(const apps *to_add); 
         
    protected:
        int display(apps* ptr) const; 
        void insert(apps*& root, apps*& to_add); //insertion into the bst
        void search(apps* root, char* find); //search functiom
        void rl(apps*& root, apps*& curr); //rotate left
        void rr(apps*& root, apps*& curr); //rotate right
        void fix(apps*& root, apps*& curr, apps* parent, apps*  grandparent); //fixes the RB tree
        int deleteAll(apps*& root);  //deletes all the nodes

    private:
        apps* root; //contains an app class ptr as root

};


