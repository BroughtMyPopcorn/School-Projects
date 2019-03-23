/*
This is the node class that contains an array of type Menu.
This allows for the insertion of insertion of Menu objs into the array
 */
package com.company;

import java.util.Scanner;

public class Node {
    private Node next; //next pointer to traverse the linked list
    private Restaurants root; //allows to search the nodes within restaurant class
    private Menu[] array; //contains the menu items for the order
    private float cost; //cost of the order
    String instructions; //allows the user to set instructions for the order

    //default constructor
    public Node() {
        next = null;
        array = null;
        root = null;
        cost = 0;
    }
    //constructor that passes in the restaurant type.
    public Node(Restaurants root){
        this.root = root;
    }

    //wrapper that takes in the amount of items the user wants to put in their order
    //to_compare is for the restaurant name
    public void getItem(int itemCount, String to_compare) {
        getItem(itemCount, root, to_compare);
    }
    //has a root so that it can search the tree
    //after it gets to the right restaurant, it calls the retrieve function to store the menu items
    private void getItem(int itemCount, Restaurants root, String to_compare) {
        //if there's no tree return
        if (root == null) {
            return;
        }
        //if the restaurant is the right one
        if (root.getRestaurantName().equals(to_compare)) { //if the object of the type matches
            array = new Menu[itemCount]; //create a new menu of the amount of items the user wants
            //for the amount of items
            for (int i = 0; i < itemCount; i++) {
                System.out.println("Enter the name of the item you want to insert");
                array[i] = root.getMenu().retrieve(); //calls the retrieve function to return the item
                System.out.println(array[i].getPrice()); //gets the price of the item
                cost += array[i].getPrice(); //add up the price
                //System.out.println("The items ordered are: "+array[i].getName() +"\n");
                System.out.println();
            }
            System.out.println("Press 1 to add special instructions, 2 for no");
            Scanner foo = new Scanner(System.in);
            int temp = foo.nextInt();
            if(temp == 1) {
                Scanner read = new Scanner(System.in);
                instructions = read.nextLine();
            }
            else {
                //prints out the the ordered items and the price of the order by iterating through the array
                System.out.println("The ordered items are");
                for (int i = 0; i < itemCount; i++) {
                    System.out.println(array[i].getName());
                }
                System.out.println("The cost is: " + cost);
                System.out.println("Special instructions: " + instructions);
                return;
            }
        }

        getItem(itemCount, root.getLeft(), to_compare); //goes left of the tree
        getItem(itemCount, root.getRight(), to_compare); //goes right of the tree

    }


    public Node getNext() {
        return next;
    }

    public void setNext(Node next) {
        this.next = next;
    }

    public void setType(Restaurants root) {
        this.root = root;
    }

}
