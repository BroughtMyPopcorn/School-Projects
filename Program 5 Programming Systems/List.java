/*
This class is to manage the linked list node. In supports the insertion of nodes

 */

package com.company;

import java.util.Scanner;

public class List {
    private Node head; //head of the node class
    private int itemCount; //the number of items the user wants to order

    //default constructor
    public List() {
        head = null;
        itemCount = 0;
    }

    //wrapper for node insert, to compare is for the restaurant name
    public void insert(Restaurants type, String to_compare) {
        insert(head, type, to_compare);
    }

    //insertion function for the linked list
    //create a new node that has a restaurant type as it's data, pass in to_compare for later use
    private Node insert(Node head, Restaurants type, String to_compare) {
        if (head == null) {
            head = new Node(type); // add node copy constructor, sets the restaurant type as it's data
            head.setNext(null); //set next to null
        } else {
            Node temp = new Node(type); //creates a new node
            temp.setNext(insert(head.getNext(), type, to_compare)); //inserts new node
        }
        return insertArray(head, to_compare); //calls the insertArray function, catching head as well
    }

    //needs the return value of head, so called up top. pass in to_compare
    public Node insertArray(Node head, String to_compare) {
        System.out.println("How many items do you want to order");
        Scanner read = new Scanner(System.in);
        itemCount = read.nextInt(); //sets item count
        head.getItem(itemCount, to_compare); //calls the getItem function in node;
        return head;
    }

}


