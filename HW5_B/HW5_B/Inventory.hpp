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
    string getItemName() const;
    int getItemNo() const;
    int getQuantity() const;
    double getCost()const;
    double getTotalCost() const;
    
    // other functions
    void printItem(Inventory InventoryZero, Inventory InventoryOne,
                   Inventory InventoryTwo);

};
#endif
