/**
 CIS 22B: Homework 5B
 
 This program is a test driver for the Inventory class.

 NAME:  Natalie Stepankevycova
 IDE: Xcode
 ===================================== */

#include <iostream>
#include <iomanip>
#include "Inventory.hpp"
using namespace std;

void printItem (Inventory InventoryZero, Inventory InventoryOne,
                Inventory InventoryTwo);

int main()
{
    string name;
    int itemNo;
    int quantity;
    double cost;
    
                  
    cout << "Please enter name of item: " << endl;
    getline(cin, name);
    cout << "Please enter item number: " << endl;
    cin >> itemNo;
    cout << "Please enter quantity of items: " << endl;
    cin >> quantity;
    cout << "Please enter price per unit: " << endl;
    cin >> cost;
    
    
    // instance of a class using default constructor
    Inventory InventoryZero = {};
    
    // instance of a class using overloaded constructor
    Inventory InventoryOne = {"Bag", 103040, 20.2, 10};
    
    Inventory InventoryTwo;
    
    InventoryTwo.setItemName(name);
    InventoryTwo.setItemNo(itemNo);
    InventoryTwo.setQuantity(quantity);
    InventoryTwo.setCost(cost);
    
    printItem(InventoryZero, InventoryOne, InventoryTwo);
    
   return 0;
}



// this function prints out inventory of three classes 
void printItem(Inventory InventoryZero, Inventory InventoryOne,
               Inventory InventoryTwo){
    
        // print item 1
        cout << "ITEM ONE: " << endl;
        cout << InventoryZero.getItemName() << endl;
        cout << InventoryZero.getItemNo() << endl;
        cout << InventoryZero.getQuantity() << endl;
        cout << InventoryZero.getCost() << endl;
        
        
        // print item 2
        cout << "ITEM TWO: " << endl;
        cout << InventoryOne.getItemName() << endl;
        cout << InventoryOne.getItemNo() << endl;
        cout << InventoryOne.getQuantity() << endl;
        cout << InventoryOne.getCost() << endl;
        
        
        // print item 3
        cout << "ITEM THREE: " << endl;
        cout << InventoryTwo.getItemName() << endl;
        cout << InventoryTwo.getItemNo() << endl;
        cout << InventoryTwo.getQuantity() << endl;
        cout << InventoryTwo.getCost() << endl;
        
        
        
}

/***************************************************************
 Save the OUTPUT below
 
 Please enter name of item:
 Slippers
 Please enter item number:
 101020
 Please enter quantity of items:
 2
 Please enter price per unit:
 9.99
 ITEM ONE:
 0
 0
 0
 0
 ITEM TWO:
 Bag
 103040
 10
 20.2
 ITEM THREE:
 Slippers
 101020
 2
 9.99
 Program ended with exit code: 0
*/
