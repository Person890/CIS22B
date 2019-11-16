
//  Created by Natálie Stepankevyčová on 5/25/19.
//  Copyright © 2019 Natálie Stepankevyčová. All rights reserved.
//

// Specification file for the Inventory class

#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>

using namespace std;

class Inventory
{
private:
    string name;
    int itemNo;
    int quantity;
    double cost;
    double totalCost;
    
    
public:
    Inventory();    //default constructor
    Inventory(int, double, int, string);
    Inventory(string, int, double, int);
    // setters
    void setItemName(string);
    void setItemNo(int);
    void setQuantity(int);
    void setCost(double);
    void setTotalCost (int, double){
        totalCost = quantity * cost;
    }
    
    
    // getters
    string getItemName() const{return name;}
    int getItemNo() const {return itemNo;}
    int getQuantity() const {return quantity;}
    double getCost()const {return cost;};
    double getTotalCost() const {return cost * quantity;}
    
    // other functions
    void printItem();
    
};



#endif


