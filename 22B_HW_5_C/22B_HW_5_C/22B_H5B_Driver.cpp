/*
//  Created by Natálie Stepankevyčová on 5/25/19.
//  Copyright © 2019 Natálie Stepankevyčová. All rights reserved.

 CIS 22B: Homework 5B
 
 This program is a test driver for the Inventory class.

 NAME:  Natalie Stepankevycova
 IDE:   Xcode
 ===================================== */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include "Inventory.hpp"

using namespace std;

// function prototypes
int readFile(Inventory *list);
void printOutOfStockItems (Inventory *list, int size);
void isCheaperThan (Inventory *list, int size);
void searchItem (Inventory *list, int size);



int main()
{

    Inventory list[100];
    int sizeOfList = readFile(list);
    

    
    //printOutOfStockItems(list, sizeOfList);
    //isCheaperThan(list, sizeOfList);
    searchItem(list, sizeOfList);


    
   return 0;
}


int readFile(Inventory *list){
    
    int size = 0;
    int _itemNo;
    string _itemName;
    int _quantity;
    double _cost;
    
    ifstream infile;            // creating file
    infile.open("inventory.txt");
    

    
    if (!infile){       // validating if file is open
        cout << "File " << "inventory.txt could not be opened." << endl;
    }
    else cout << "I OPENED THE FILE" << endl;
    while(!infile.eof()){
        infile >> _itemNo;
        list[size].setItemNo(_itemNo);
        infile >> _quantity;
        list[size].setQuantity(_quantity);
        infile >> _cost;
        list[size].setCost(_cost);
        infile.ignore();
        getline(infile, _itemName);
        list[size].setItemName(_itemName);
        
        size++;          // increase the counter/size
    }
     infile.close();         // close file

    return size;
}

void printOutOfStockItems (Inventory *list, int size){
    
    for (int i = 0; i < size; i++){
        if (list[i].getQuantity() == 0) {
            cout << setw(10) << fixed
                 << list[i].getItemNo()
                 << list[i].getQuantity()
                 << list[i].getCost()
                 << list[i].getItemName() << endl;
        }
    }
}



void isCheaperThan (Inventory *list, int size){
    
    double desiredPrice;
    cout << "Please enter maximum price with precision to cents (i.e 9.99): ";
    cin >> desiredPrice;
    
    while (desiredPrice < 0.25 || desiredPrice > 99.99){
        cout << "Invalid price. Please enter price in range from $0.25 to $99.99:";
        cin >>desiredPrice;
    }
    for (int i = 0; i < size; i++){
        if (list[i].getCost() <= desiredPrice) {
            cout << setw(9)
                 << setprecision(2) << fixed
                 << list[i].getItemNo() << "\t"
                 << list[i].getQuantity() << "\t"
                 << list[i].getCost() << "\t"
                 << list[i].getItemName() << endl;
        }
    }
}


void searchItem (Inventory *list, int size) {
    
    string itemSearchedFor;
    cout << "Please enter a name of item that you are looking for: ";
    getline(cin, itemSearchedFor);
    itemSearchedFor[0] = toupper(itemSearchedFor[0]);


    for (int i = 0; i < size; i++){
        
        if (list[i].getItemName().compare(itemSearchedFor) == 0 ){
            cout << setw(9)
            << setprecision(2) << fixed
            << list[i].getItemNo() << "\t"
            << list[i].getQuantity() << "\t"
            << list[i].getCost() << "\t"
            << list[i].getItemName() << endl;
        }
    }
    
}
/***************************************************************
 Save the OUTPUT below
 
 
*/
