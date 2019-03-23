/*
Nelson wong

This class allows for insert of the Restaurants objects via file readin
This class also traverse the Restaurant nodes and calls the insertion, retrieve, and remove functions for MenuBST
 */
package com.company;

import java.io.*;
import java.util.Scanner;


public class Tree {
    private Restaurants root = null; //restaurant root for insertion of restaurant names into a bst
    private Restaurants mcd = new McD(); //creates a new mcdonalds obj and allows for allocation of a menu into it
    private Restaurants kfc = new KFC();  //creates a new kfc obj and allows for allocation of a menu into it
    private Restaurants pop = new Popeyes();  //creates a new popeye obj and allows for allocation of menu into it
    private MenuBST McDonalds = new MenuBST(); //creates a new menu obj for mcdonalads and allows data to be readin to it
    private MenuBST KFC = new MenuBST(); //creates a new menu obj for kfc and allows data to be readin to it
    private MenuBST Popeyes = new MenuBST();//creates a new menu obj for popeyes and allows data to be readin to it
    private List obj = new List(); //creates a new list for linear linked list

    //wrapper function for restaurant insert, takes in a restaurant obj
    public void insert(Restaurants to_add) {
        root = insert(root, to_add); //catch the root
    }

    //insert function that returns a restaurant obj. Takes a restaurant root and to_add and compares the data for jnsert
    private Restaurants insert(Restaurants root, Restaurants to_add) {
        if (root == null) { //if roots null, return the obj
            return to_add;
        }

        int compare = root.getRestaurantName().compareTo(to_add.getRestaurantName()); //attach the string comparison value to an int
        //System.out.print("Value: "+ compare);
        if (compare < 0) { //if the value is less than 0 , add to left side
            root.setLeft(insert(root.getLeft(), to_add)); //allocate the node to the left
        } else { //add to right
            root.setRight(insert(root.getRight(), to_add));
        }
        return root;
    }

    //wrapper to search the restaurant tree
    public void removeItem() {
        System.out.println("An item in which restaurant do you want to delete from?");
        System.out.println("Press 1 for McDonald's \n" + "2. Popeyes \n" + "3. KFC");
        Scanner read = new Scanner(System.in);
        int temp = read.nextInt();
        String compare;
        if (temp == 1) {
            compare = "McDonalds";
            removeItem(root, compare); //calls the retrieve function with the appropiate prototypes
        }
        if (temp == 2) {
            compare = "Popeyes";
            removeItem(root, compare);
        }
        if (temp == 3) {
            compare = "KFC";
            removeItem(root, compare);
        }

    }

    //traverses the restaurant nodes for the right MenuBST object
    private void removeItem(Restaurants root, String compare) {

        if (root.getRestaurantName().equals(compare)) { //if the object of the type matches
            root.getMenu().removeItem(); //calls the remove function to return the item
            return;
        }

        removeItem(root.getLeft(), compare);//traverse left
        removeItem(root.getRight(), compare); //traverse right
    }

    //deletes everything
    public void removeall(){
        removeall(root);
    }
    public void removeall(Restaurants root){
         root = null;
    }

    //Wrapper for the retrieve function
    public void getItem() {
        System.out.println("Which restaurant's menu item do you want to search for");
        System.out.println("1. McDonalds \n" + "2. Popeyes \n" + "3. KFC");
        Scanner read = new Scanner(System.in);
        int temp = read.nextInt();
        String compare;
        if (temp == 1) {
            compare = "McDonalds";
            getItem(root, compare); //calls the retrieve function with the appropiate prototypes
        }
        if (temp == 2) {
            compare = "Popeyes";
            getItem(root, compare);
        }
        if (temp == 3) {
            compare = "KFC";
            getItem(root, compare);
        }
    }

    //the retrieve function that searches the restaurant for an obj of the menu type
    private void getItem(Restaurants root, String compare) {
        if (root == null) {
            return;
        }
        if (root.getRestaurantName().equals(compare)) { //if the object of the type matches
            root.getMenu().retrieve(); //calls the retrieve function to return the item
            return;
        }

        getItem(root.getLeft(), compare); //goes left of the tree
        getItem(root.getRight(), compare); //goes right of the tree
    }


    //allows the insert of a new restaurant item
    public void userInsert() {
        String new_name; //temp string to store the new item name
        float new_price; //temp for a new item price
        String new_ingredients; //temp string for new ingredients
        System.out.println("Which item do you want to insert");
        System.out.println("Enter 1 for McDonalds item\n" + "Enter 2 for Popeyes item\n" + "Enter 3 for new KFC item");
        Scanner reader = new Scanner(System.in);
        int temp = reader.nextInt();

        if (temp == 1) { //if the user enters one, it reads in the mcdonalds item and calls the insert function to the tree
            Scanner name = new Scanner(System.in); //creates a scanner class obj to readin
            System.out.println("Enter in a McDonalds item");
            new_name = name.nextLine(); //assign the read-in data to the new item name
            Scanner price = new Scanner(System.in);
            System.out.println("Enter in the price (float)");
            new_price = price.nextFloat(); //assign read-in data to the new item price
            Scanner ingred = new Scanner(System.in);
            System.out.println("Enter in the ingredients");
            new_ingredients = ingred.nextLine(); //assign read-in data to the new item's ingredients
            McDonalds.insert(new_name, new_ingredients, new_price); //calls the insert function for the MenuBST class with right variables
        }
        if (temp == 2) {
            Scanner name = new Scanner(System.in);
            System.out.println("Enter in a Popeyes item");
            new_name = name.nextLine();
            Scanner price = new Scanner(System.in);
            System.out.println("Enter in the price (float)");
            new_price = price.nextFloat();
            Scanner ingred = new Scanner(System.in);
            System.out.println("Enter in the ingredients");
            new_ingredients = ingred.nextLine();
            Popeyes.insert(new_name, new_ingredients, new_price);
        }
        if (temp == 3) {
            Scanner name = new Scanner(System.in);
            System.out.println("Enter in a KFC item");
            new_name = name.nextLine();
            Scanner price = new Scanner(System.in);
            System.out.println("Enter in the price (float)");
            new_price = price.nextFloat();
            Scanner ingred = new Scanner(System.in);
            System.out.println("Enter in the ingredients");
            new_ingredients = ingred.nextLine();
            KFC.insert(new_name, new_ingredients, new_price);
        }
    }

    //this displays the restaurants that are in the tree. Use root to recurse
    private void displayRestaurants(Restaurants root) {
        if (root == null) return;

        displayRestaurants(root.getLeft()); //go left

        System.out.println("Restaurant names: " + root.getRestaurantName()); //prints out the restaurant names
        displayRestaurants(root.getRight());
    }

    //display wrapper function
    public void displayRestaurants() {
        displayRestaurants(root);
    }

    //wrapper for the display item function. The option is which the restaurant the user chooses to display
    public void displayItem(int option) {
        displayItem(root, option);
    }

    //displays the menu items in the menu, option to choose which restaurant
    private void displayItem(Restaurants root, int option) {
        if (root == null) return;
        if (root.getMenu() != null) { //when there are menu items corresponding to the MenuBST obj

            if (option == 1) {
                if (root.getMenu().equals(McDonalds)) { //if the MenuBST obj is McDonald's
                    root.getMenu().display(); //displays the menu items in McDonalds
                }
            }
            if (option == 2) {
                if (root.getMenu().equals(Popeyes)) {
                    root.getMenu().display();
                }
            }
            if (option == 3) {
                if (root.getMenu().equals(Popeyes)) {
                    root.getMenu().display();
                }
            }

        }
        displayItem(root.getLeft(), option); //goes left of tree
        displayItem(root.getRight(), option); //goes right
    }

    //-------------------------------------------
    //List operations

    //prompt function for the linked list of arrays insert
    public void insertList(){
        int pick;
        System.out.println("Pick which restaurant order do you want");
        System.out.println("1. McDonalds \n" + "2. Popeyes \n" +"3. KFC");
        Scanner read = new Scanner(System.in);
        pick = read.nextInt();
        String to_compare = null;
        if(pick == 1){
            to_compare = "McDonalds";
            obj.insert(mcd, to_compare); //calls the function w/ the correct restaurant name
        }
        if(pick == 2){
            to_compare = "Popeyes";
            obj.insert(pop, to_compare);
        }
        if(pick ==3){
            to_compare = "KFC";
            obj.insert(kfc, to_compare);
        }
    }


    //the readin function that allows data to be read in from an external file
    public void readin() throws FileNotFoundException {
        // Scanner read = new Scanner (new File("data.txt"));
        //String fileName = "data.txt";
        File file = new File("data.txt");
        if (!file.isFile()) {
            throw new FileNotFoundException("doesnt work");
        }
        Scanner read = null;
        read = new Scanner(file);
        read.useDelimiter("/|\\r|\\n");
        String name; //temp for item name
        String ingred; //for ingeredients
        float price; //for item price
        int counter = 0; //counter that allows separation of lines
        String line;
        if (file.exists()) {
            while ((read.hasNextLine())) {
                counter++;
                if (counter == 1) {
                    mcd.setRestaurantName(read.nextLine());
                    insert(mcd);
                } else if (counter == 2) {
                    kfc.setRestaurantName(read.nextLine());
                    insert(kfc);
                } else if (counter == 3) {
                    pop.setRestaurantName(read.nextLine());
                    insert(pop);
                } else if (counter >= 4 && counter <=12) {
                    name = read.next(); //reads in the item name
                    price = read.nextFloat(); //price
                    ingred = read.next(); //the ingreds
                    McDonalds.insert(name, ingred, price); //calls the insert function for the MenuBST
                    System.out.println(name + ingred + price);
                    mcd.setMenu(McDonalds); //assign the new menu obj to the restaurant protoype
                }

            else if (counter > 12 && counter <= 21) {
                name = read.next();
                price = read.nextFloat();
                ingred = read.next();
                Popeyes.insert(name, ingred, price);
                System.out.println(name + ingred + price);
                pop.setMenu(Popeyes); //assign the new menu obj to the restaurant protoype
                }

            else if (counter > 22 && counter <= 30) {
                name = read.next();
                price = read.nextFloat();
                ingred = read.next();
                KFC.insert(name, ingred, price);
                System.out.println(name + ingred + price);
                kfc.setMenu(KFC); //assign the new menu obj to the one in protoype
            }
                else {
                    read.nextLine();
                }
            }
        }
    }
}
