// Implementation file for the Inventory class.

#include "Inventory.hpp"
#include <iostream>      
#include <string>

using namespace std;

Inventory::Inventory(){
    name = "0";
    itemNo = 0;
    quantity = 0;
    cost = 0.0;
    totalCost = 0.0;
}

Inventory::Inventory(string _name, int _itemNo, double _cost, int _quantity ){
    name = _name;
    itemNo = _itemNo;
    cost = _cost;
    quantity = _quantity;
}

Inventory::Inventory(int itemNo, double cost, int quantity, string name){
    itemNo = getItemNo();
    cost = getCost();
    quantity = getQuantity();
    name = getItemName();
    setTotalCost(quantity, cost);
}

// setters
void Inventory::setItemName (string _name){
    name  = _name;              // fix to check if input isn't empty
}

void Inventory::setItemNo (int _itemNo){
    if (itemNo >= 0)
        itemNo = _itemNo;
    else
    {
        cout << "Invalid value for item number\n";
        exit(EXIT_FAILURE);
    }
}

void Inventory::setQuantity (int _quantity){
    if (_quantity >= 0)
        quantity = _quantity;
    else
    {
        cout << "Invalid value for item quantity\n";
        exit(EXIT_FAILURE);
    }
}

void Inventory::setCost (double _cost){
    if (_cost >= 0.0)
        cost = _cost;
    else
    {
        cout << "Invalid value for item number\n";
        exit(EXIT_FAILURE);
    }
    
}

// getters

string Inventory::getItemName() const {
    return name;
}
int Inventory::getItemNo() const {
    return itemNo;
}
int Inventory::getQuantity() const {
    return quantity;
}
double Inventory::getCost() const {
    return cost;
}
double Inventory::getTotalCost() const {
    return totalCost;
}
