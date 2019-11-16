
//  Created by Natálie Stepankevyčová on 5/25/19.
//  Copyright © 2019 Natálie Stepankevyčová. All rights reserved.
//

// Implementation file for the Inventory class.

#include "Inventory.hpp"
#include <iostream>      
#include <string>

using namespace std;
// default constructor
Inventory::Inventory(){
    name = "";
    itemNo = 0;
    quantity = 0;
    cost = 0.0;
    totalCost = 0.0;
}

// setters
void Inventory::setItemName (string _name){
    name  = _name;
}

void Inventory::setItemNo (int _itemNo){
    itemNo = _itemNo;
}

void Inventory::setQuantity (int _quantity){
    quantity = _quantity;
    
}

void Inventory::setCost (double _cost){
        cost = _cost;
}
