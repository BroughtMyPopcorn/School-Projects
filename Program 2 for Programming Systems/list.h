//the list class manages the insertion of nodes
class list
{
    public:
        list();
        ~list();
      //  void insertw(tabl); //wrapper for insert
        void display(); //wrapper for display funct
        void remove(); //remove question
        void insert(int);
        void search(int ref); //search function 
        void test();
         int delete_item(int del);

    protected:
        int delete_item(node*& head, int del);
         node* head; //contains a node for insertion
        void display(node* head);
        void remove(node*& head);
       // node* search(node* head); //search function 
        int traverse(node* head, int ref);
};
