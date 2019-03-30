/*
Nelson Wong
This program allows for the insertion, search and removal of menu items
Restaurants is an Abstract base class that has mcdonalds, popeyes, and kfc as it's children
There is a binary search tree of Restaurants, and each restaurant has a object of a MenuBST
MenuBST is a node for menu items

For program 5, I added on the linear linked list of arrays in the list and node files
The user can order items by picking 5
The data type of the the node is a restaurant type, and it contains an array of Menu Objects
User picks the amount of items to order and type in the food associated with the restaurant.

On the text file: 4-12 is McDonalds, 12-21 is Popeyes, 21-30 is KFC


 */
package com.company;

import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        boolean cont = true; //boolean for the while loop
        Tree obj = new Tree(); //create a new tree ref
        obj.readin(); //calls the readin file from the tree class
        //do while loop for user prompt
        do {
            System.out.println();
            System.out.printf("Here are the restaurant options \n");
            obj.displayRestaurants();
            System.out.println("Here are the options \n");
            System.out.println("Press 1 to insert a new food item based on restaurant name \n" + "Press 2 to display a menu");
            System.out.println("Press 3 to retrieve an item \n" + "Press 4 to remove a menu item \n" + "Press 5 to make an order \n" + "Press 6 end the program");
            Scanner option = new Scanner(System.in);
            int pick = option.nextInt();

            if (pick == 1) {
                obj.userInsert();
            } else if (pick == 2) {
                System.out.println("Enter a number to display a Restaurant Menu");
                System.out.println("1. McDonalds \n" + "2. Popeyes \n" + "3. KFC");
                Scanner menu = new Scanner(System.in);
                int search = menu.nextInt();
                obj.displayItem(search);
            } else if (pick == 3) {
                obj.getItem();
            } else if (pick == 4) {
                obj.removeItem();
            } else if (pick == 5) {
                obj.insertList();
            } else if (pick == 6) {
                obj.removeall();
                cont = false;
            }
        } while (cont == true);
    }
}
