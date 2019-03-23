/*
Nelson Wong

This class allows for the retrieval, insertion, and removal of Menu items.
 */

package com.company;

import java.util.Scanner;

public class MenuBST {
    private Menu root;

    //Inserts Menu items into tree. Each menu item has a name, price and indredient list
    public void insert(String t_name, String t_ingredients, float t_price) {
        Menu to_add = new Menu(t_name, t_ingredients, t_price); //creates a new instance of Menu with the read in data
        root = insert(root, to_add); //calls the insert function  for the insert
    }

    //inserts the new menu object into a tree
    private Menu insert(Menu root, Menu to_add) {
        if (root == null) {
            return to_add;
        }
        int compare = root.getName().compareTo(to_add.getName()); //attach the string comparison value to an int
        //System.out.print("Value: "+ compare);
        if (compare < 0) { //if the value is less than 0 , add to left side
            root.setLeft(insert(root.getLeft(), to_add));
        } else { //add to right
            root.setRight(insert(root.getRight(), to_add));
        }
        return root;
    }

    //the wrapper for the remove function
    public void removeItem() {
        System.out.println("Enter the menu item to delete");
        Scanner get = new Scanner(System.in);
        String to_remove = get.nextLine();
        root = removeItem(root, to_remove);
    }

    //deletes an item in the bst, using root the traverse the tree, to_remove is the string of the item
    private Menu removeItem(Menu root, String to_remove) {
        if (root == null) {
            return root;
        }
        if (root.getName().equals(to_remove)) { //if its equal to the item to delete
            if (root.getLeft() == null && root.getRight() == null) { //this is a leaf
                root = null;
                return root;
            }
            if (root.getRight() == null && root.getLeft() != null) { //checks case if no left
                root = root.getLeft();
                return root;

            }
            if (root.getRight() != null && root.getLeft() == null) { //no right
                root = root.getRight();
                return root;
//
            }

            if (root.getLeft() != null && root.getRight() != null) { //2 children
                System.out.println("The item deleted is: " + root.getName());
                Menu current = root.getRight().getLeft();
                Menu prev = root.getRight();
                //while loop for the IOS
                while (current.getLeft() != null) {
                    current = current.getLeft();
                    prev = prev.getLeft();
                }
                //sets the data to new
                root.setIngredients(current.getIngredients());
                root.setPrice(current.getPrice());
                root.setName(current.getName());
                prev.setLeft(current.getRight());
            }
            return root;
        }
        root.setRight(removeItem(root.getRight(), to_remove));
        root.setLeft(removeItem(root.getLeft(), to_remove));
        return root;
    }

    //wrapper to retrieve a menu item
    public Menu retrieve() {
        display();
        System.out.println("Enter the menu item to retrieve");
        Scanner get = new Scanner(System.in);
        String to_get = get.nextLine();

        return retrieve(root,to_get);
    }


    //traverses the nodes of the tree and matches the string to the menu item. returns the node
    private Menu retrieve(Menu curr, String to_get) {
        if (curr == null) return null;

        if (curr.getName().equals(to_get)) {
            System.out.printf("The item returned is: " + curr.getName()+"\n" + " item price is: " + curr.getPrice());
            System.out.println();
            //curr = new Menu(curr);
            //curr = root;
            Menu temp = new Menu(curr.getName(), curr.getIngredients(), curr.getPrice());
            curr = temp;
            return curr;
        }
        else{
           // System.out.println(curr.getName());
        }
       Menu left  = retrieve(curr.getLeft(), to_get); //need to catch the value for left
        Menu right = retrieve(curr.getRight(), to_get); //catch the value for right
       if(left != null){
           return left; //r
       }
       else{
           return right;
       }

    }

    //traverse the tree and displays the names of the items in the tree
    private void displayItem(Menu root) {
        if (root == null) return;


        System.out.println("The item name is: " + root.getName());
        System.out.println("The item price is: "+root.getPrice());
        System.out.println("Item's ingredients are: "+root.getIngredients());
        System.out.println();
        displayItem(root.getRight());
        displayItem(root.getLeft());

    }

    //wrapper for the item display function
    public void display() {
        displayItem(root);
    }


}
