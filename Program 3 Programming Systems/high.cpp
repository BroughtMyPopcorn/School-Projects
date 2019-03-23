#include "high.h" 

//Operator overloading

//calls the display function
ostream& operator<<(ostream& out, const tree& s){
    s.display();
    return out;
}

//calls the insert function and uses the += op 
tree& tree::operator+=(apps *to_add){
    insert(to_add);
    
    return *this;
}


//-----------------------------


//tree constructor 
tree::tree(){
    root = NULL;
}

//destructor 
tree::~tree(){
    deleteAll(root);
}

//display wrapper function
int tree::display() const{
    return display(root);
}

//display function, by passing in root to travese throught bst and call the display
int tree::display(apps* root) const {
    if(!root) return 0;

    display(root->getLeft()); 
    root->display();

    display(root->getRight());
    return 1; 
}

//this deallocates all the nodes in the list using the root ptr to delete everythig
int tree::deleteAll(apps*& root){

    if(!root) return 0;
    deleteAll(root->getLeft());
    deleteAll(root->getRight());
    delete root;
    return 1;

}

//se
void tree::search(char* find){
   // cout<<"Which app do you want to search for"<<endl;
    
    search(root, find);
}

//search fubction, uses root to traverse the tree, and find passed in from wrapper
void tree::search(apps* root, char* find){
    if(!root) return;

    if(*root == find){ //if apps' name is equal to find
        root->display(); //calls the display
        return;
    }

    search(root->getLeft(), find);
    search(root->getRight(), find);

}



//tree insertion wrapper with to_add as a ptr ref to be passed into
void tree::insert(apps*& to_add){

    return insert(root, to_add);
}

//insertion for the tree, with a obj ptr to the base class to compare.
void tree::insert(apps*& root, apps*& to_add){ //char* name
    if(!root){
        root = to_add; //if not root, the new obj is the root
        fixWrap(root, to_add); //calls this to make root black
        return; 
    }
    if(*root > *to_add){ //if obj name is greather than inserting name go left
        insert(root->getLeft(), to_add); //recursie taverse
        root->getLeft()->getParent() = root; //makes the roots left's parent root
    }

    else if(*root <= *to_add){ //if less than or equal go right
        insert(root->getRight(), to_add);
        root->getRight()->getParent() = root; //root's left parent is now root
    }


    fixWrap(root, to_add); //fixes bst to red black

}


//rotate left function for RB tree. Need root and curr to rotate
void tree::rl(apps*& root, apps*& curr){
    apps* ptR = curr->getRight(); //makes base clss ptr to currrent right

    if(curr->getRight() != NULL){//checks if the right is null
        curr->getRight()->getParent() = curr; //make curr's right parent to curr
        ptR->getParent() = curr->getParent(); //makes curr's original right to curr's parent
    }
    if(curr->getParent() == NULL){
        root = ptR; //if there's no parent, make parent equals curr's right
    }

    else if(curr == curr->getParent()->getLeft()){ //if curr is equal to currs parent's left
        curr->getParent()->getLeft() = ptR; //assign curr's parent's left to curr's right
    }

    else{
        curr->getParent()->getRight() = ptR; //makes curr's parent's right to curr'sright
        ptR->getLeft() = curr; //make curr's left to curr
        curr->getParent() = ptR; //make curr's parent curr's right

    }
}

//rotate right funtion
void tree::rr(apps*& root, apps*& curr){
    apps* ptL = curr->getLeft(); //base class ptr ptL to curr's left

    curr->getLeft() = ptL->getRight();

    if(curr->getLeft() != NULL){ //if left is NULL
        curr->getLeft()->getParent() = curr; //curr's left's parent is curr
        ptL->getParent() = curr->getParent(); //curr's original left's parent is curr's parent
    } 

    if(curr->getParent() == NULL){
        root = ptL; //if no parent, make root curr's left
    }

    else if(curr == curr->getParent()->getLeft()){ //if curr is equal to it's parent's left
        curr->getParent()->getLeft() = ptL;//make curr's parent's left to it's currs oringal left
    }

    else{
        curr->getParent()->getRight() = ptL; //assign curr's original left to curr's parent's right
        ptL->getRight() = curr; //assign curr to curr's original left to right
        curr->getParent() = ptL;// assing curr's orignal left to curr's parent
    }

}

//Wrapper for tree fixing function. passes in root and curr
void tree::fixWrap(apps*& root, apps*& curr){
    apps* parent = NULL; //parent pointer
    apps* grandparent = NULL; //grand parent ptr

    return fix(root, curr, parent, grandparent);
}

//tree fixing function which transitions bst to red black. Needs these parameters for rotation and color assignment
void tree::fix(apps*& root, apps*& curr, apps* parent, apps* grandparent){


    if((curr != root) && (curr->getColor() != true) && (curr->getParent()->getColor() == false)){
        parent = curr->getParent();
        grandparent = curr->getParent()->getParent();
        // Case 1: if parent of curr is left child of grandparent

        if(parent == grandparent->getLeft()){ //if the parent is equal to the grandaparent's left 
            grandparent->setColor(false);
            parent->setColor(true);
            apps* uncle = grandparent->getRight();

            if(uncle != NULL && uncle->getColor() == false){
                grandparent->setColor(true);
                uncle->setColor(true);
                curr = grandparent;
                fix(root, curr, parent, grandparent);
            }

            else{
                //if curr is right child of parent, rotate left
                if(curr == parent->getRight()){
                    rl(root, parent);
                    curr = parent;
                    parent = curr->getParent();

                    fix(root, curr, parent, grandparent);
                }
                //if ptr is left child of parent, rotate right
                rr(root, grandparent);
                bool temp;
                temp =  parent->getColor();
                parent->setColor(grandparent->getColor());
                parent->setColor(temp);
                curr = parent;

                fix(root, curr, parent, grandparent);
            }
        }

        else{
            //parent of curr is right child of grandparent
            apps* uncle = grandparent->getLeft();
            //case: 1 the uncle of curr is red
            if((uncle != NULL) && (uncle->getColor() == false)){
                grandparent->setColor(false);
                parent->setColor(true);
                uncle->setColor(true);
                curr = grandparent;
                fix(root, curr, parent, grandparent);
            }

            else{
                //curr is left child of parent, rotate right
                if(curr == parent->getLeft()){
                    rr(root, parent);
                    curr = parent;
                    parent = curr->getParent();
                }

                //curr is right of its parent, rotate left
                rl(root, grandparent);
                bool temp;
                temp =  parent->getColor();
                parent->setColor(grandparent->getColor());
                parent->setColor(temp);
                curr = parent;  
                fix(root, curr, parent, grandparent);
            }
        }
    }

    root->setColor(true);
}



//readin for the external file
int tree::readin(){
    //stores the data readed in from external file
    char t_type[1000];
    char t_name[1000];
    char t_des[1000];
    char t_review[1000];
    int  t_cost =0;
    char t_history[1000];
    int t_stocks = 0;
    int t_followers = 0;
    int t_score = 0;
    std::ifstream in_file ("app.txt");

    // if(in_file.fail()) return 0; //if the file cant be read in, return 0

    if(in_file){ //if the read in was sucessful
        in_file.peek();

        while(in_file && !in_file.eof()){ //while it's not end of file
            in_file.get(t_type, 100, ':');
            in_file.ignore(100, ':');
            in_file.get(t_name, 100, ':');
            in_file.ignore(100, ':');
            in_file.get(t_des, 100, ':');
            in_file.ignore(100, ':');
            in_file.get(t_review, 100, ':');
            in_file.ignore(100, ':');
            in_file.get(t_history, 100, ':');
            in_file.ignore(100, ':');
            in_file >> t_cost;
            in_file.ignore(100, ':');
            if(strcmp(t_type, "biz")==0){ //if the type name in the file is the same as biz
                in_file >> t_stocks; 
                in_file.ignore(100, '\n');
                apps* ptr = new biz(t_type, t_name, t_des, t_review, t_cost, t_history, t_stocks); //make a new biz class ptr w/ the right prototypes
                insert(ptr); //calls the tree insert function
            }
            else if(strcmp(t_type, "social")==0){
                in_file >> t_followers;
                in_file.ignore(100, '\n');
                apps* ptr = new social(t_type, t_name, t_des, t_review, t_cost, t_history, t_followers);
                insert(ptr);
            }
            else if(strcmp(t_type, "games")==0){
                in_file >> t_score;
                in_file.ignore(100, '\n');
                apps* ptr = new games(t_type, t_name, t_des, t_review,t_cost, t_history,  t_score);
                insert(ptr);
            }
        }
    }
    return 1;
}

