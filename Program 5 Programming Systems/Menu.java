/*
Nelson Wong
This class acts as the tree of menu items. Each restaurant has a Menu
 */
package com.company;

import java.util.Scanner;

public class Menu {
    private Menu left; //left reference to go left
    private Menu right; //go right
    private float price; //price of the item
    private String name; //name of the item
    private String ingredients; //ingredients of the item

    public Menu() {
        left = null;
        right = null;
        name = null;
        price = 0;
        ingredients = null;
    }
    //menu copy constructor
    public Menu(Menu src) {
        name = src.name;
        ingredients = src.ingredients;
        price = src.price;
    }

    //sets the new menu information
    public Menu(String t_name, String t_ingre, float t_price) {
        name = t_name;
        ingredients = t_ingre;
        price = t_price;
        left = null;
        right = null;
    }

    //all setters and getters so that the MenuBST class can manage it's information
    public void setPrice(float price) {
        this.price = price;
    }

    public float getPrice() {
        return price;
    }

    public String getIngredients() {
        return ingredients;
    }

    public void setIngredients(String ingredients) {
        this.ingredients = ingredients;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }


    public Menu getLeft() {
        return left;
    }

    public Menu getRight() {
        return right;
    }

    public void setRight(Menu right) {
        this.right = right;
    }

    public void setLeft(Menu left) {
        this.left = left;
    }

}
