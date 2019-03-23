/*
Nelson wong
This is the abstract class for a restaurants. Can create an object of it's derived classes.
Doesn't have much of a purpose than to act as a node
 */
package com.company;

abstract class Restaurants{
    private String RestaurantName; //string for the restaurant name
    private Restaurants left; //left reference to go left within the tree
    private Restaurants right; //to go right
    private MenuBST menu; //contains a MenuBST object

    public Restaurants(){
        left = null;
        right = null;
        menu = null;
    }

//getters and setters
    public Restaurants getLeft(){
        return left;
    }

    public Restaurants getRight(){
        return right;
    }

    public void setLeft(Restaurants left) {
        this.left = left;
    }

    public void setRight(Restaurants right) {
        this.right = right;
    }

    public void setRestaurantName(String t_name){
        RestaurantName = t_name;
    }

    public String getRestaurantName() {
        return RestaurantName;
    }

    public MenuBST getMenu(){
        return menu;
    }

    public void setMenu(MenuBST obj){
        this.menu = obj;
    }
}
