//
//  main.cpp
//  22B_HW_5_C
//
//  Created by Natálie Stepankevyčová on 5/25/19.
//  Copyright © 2019 Natálie Stepankevyčová. All rights reserved.
//

/**
 CIS 22B: Homework 5C
 
 This program creates and processes an array of up to 100 Inventory objects.
 It also write writes a report to a file.
 
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
void printWholeTable(Inventory *list, int size);
void printSeparator();


int main()
{
    
    Inventory list[100];    // creating 100 places for items
    int sizeOfList = readFile(list);        // counter of items

    
    printOutOfStockItems(list, sizeOfList);     //  print out of stock
    isCheaperThan(list, sizeOfList);            // print less than desired price
    searchItem(list, sizeOfList);               // search for item
    printWholeTable(list, sizeOfList);          // print everything
    
    
    return 0;
}

/**************************************
This function opens and reads text file, puts the input into class members
 and keeps track of number of items in it.
 IN: Class inventory list
 OUT: number of items
***************************************/
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
    else {
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
        
        size++;          // increases counter of items
    }
    infile.close();         // close file
    }
    return size;
}
/**************************************
 This function prints items that have quantity equal to zero
 IN: Class inventory list, number of items
 OUT: nothing
 ***************************************/
void printOutOfStockItems (Inventory *list, int size){
    
    cout << "Items out of stock: " << endl;
    
    for (int i = 0; i < size; i++){
        if (list[i].getQuantity() == 0) {
            cout << setw(10) << fixed
            << setprecision(2)
            << list[i].getItemNo() << "\t"
            << list[i].getQuantity() << "\t"
            << list[i].getCost() << "\t"
            << list[i].getItemName() << endl;
        }
    }
}

/**************************************
 This function prompts user to enter desired price and returns items cheaper
 than the price.
 IN: Class inventory list, number of items
 OUT: nothing
 ***************************************/

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
            cout << setw(10)
            << setprecision(2) << fixed
            << list[i].getItemNo() << "\t"
            << list[i].getQuantity() << "\t"
            << list[i].getCost() << "\t"
            << list[i].getItemName() << endl;
        }
    }
}

/**************************************
 This function prompts user to enter desired item and all matches from the list
 IN: Class inventory list, number of items
 OUT: nothing
 ***************************************/

void searchItem (Inventory *list, int size) {
    
    string itemSearchedFor;
    cout << "Please enter a name of item that you are looking for: ";
    cin.ignore();
    getline(cin, itemSearchedFor);
    // input validation
    while (itemSearchedFor == " "){
        cout << "Please enter name again: ";
        cin >> itemSearchedFor;
    }
    // putting first character to uppercase
    itemSearchedFor[0] = toupper(itemSearchedFor[0]);
    
    // printing out items
    for (int i = 0; i < size; i++){
        
        if (list[i].getItemName().compare(itemSearchedFor) == 0 ){
            cout << setw(10)
            << setprecision(2) << fixed
            << list[i].getItemNo() << "\t"
            << list[i].getQuantity() << "\t"
            << list[i].getCost() << "\t"
            << list[i].getItemName() << endl;
        }
    }
}

/**************************************
 This function outputs whole table of all items, number of items and total price
 of all goods in the list into a file
 IN: Class inventory list, number of items
 OUT: nothing
 ***************************************/

void printWholeTable(Inventory *list, int size){
    
    ofstream myfile ("InventoryReport.txt");    // creating new file to write to
    
    
    if (myfile.is_open()){
        
    double storeTotal = 0.0;
    myfile << "Inventory report" << endl;
    
myfile << "========== ==================== ========== ========== ===============" << endl;
    
    int width1 = 10;            // width of column 1
    int width2 = 20;            // width of column 2
    
    // to get length of words
    string itemNo = "ItemNo";
    string name = "Name";
    string quantity = "Quantity";
    string cost = "Cost";
    string totalCost = "Total Cost";
    
    // centering the words
    myfile << setw((width1-(itemNo.length())/2)) << right << itemNo;
    myfile << setw((width2-(name.length())/2)) << right << name ;
    myfile << setw((width2-(quantity.length())/2)) << right << quantity ;
    myfile << setw((width1-(cost.length())/2)) << right << cost ;
    myfile << setw((width2-(totalCost.length())/2)) << right << totalCost << endl;
    
    
myfile << "========== ==================== ========== ========== ===============" << endl;
    
    // printing out items
    for (int i = 0; i < size; i++){
        myfile << setw(width1) << left << list[i].getItemNo() << " ";
        myfile << setw(width2) << left << list[i].getItemName() << " ";
        myfile << setw(width1) << right << list[i].getQuantity() << " ";
        myfile << setw(width1) << right << list[i].getCost() << " ";
        myfile << setw(width1) << right << list[i].getTotalCost() << endl;
        storeTotal+=list[i].getTotalCost();
    }
    
myfile << "========== ==================== ========== ========== ===============" << endl;
    
    myfile << "Number of items: " << size << endl;
    myfile << "Store total: $" << storeTotal << endl;
    }
}


// need to figure out how to print separator

/***************************************************************
 Save the OUTPUT below
 
 Items out of stock:
 122339    0    5.99    Ceramic Pot
 230039    0    11.99    Belt
 439123    0    9.99    Ceramic Pot
 634411    0    9.75    Slippers
 711099    0    6.25    Touch-Screen Gloves
 828824    0    7.25    Bag
 Please enter maximum price with precision to cents (i.e 9.99): 9.99
 122339    0    5.99    Ceramic Pot
 211298    25   8.00    Business Card Holder
 312378    43   9.99    Small Storage Basket
 321123    97   4.25    Hand Soap
 411234    5    8.75    Scarf
 422892    11   9.50    Makeup Brush Set
 439123    0    9.99    Ceramic Pot
 518934    20   8.00    Lip Balm
 610992    12   8.50    Cable Knit Beanie
 634411    0    9.75    Slippers
 711099    0    6.25    Touch-Screen Gloves
 812398    2    9.50    Pillow Cover
 828824    0    7.25    Bag
 921234    50   5.99    Bag
 Please enter a name of item that you are looking for: Bag
 339234    33   10.99    Bag
 621234    10   19.99    Bag
 828824    0    7.25    Bag
 921234    50   5.99    Bag
 Program ended with exit code: 0
 */
