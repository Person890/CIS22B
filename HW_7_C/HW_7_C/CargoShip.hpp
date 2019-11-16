//
//  CargoShip.h
//  HW_7_C
//
//  Created by Natálie Stepankevyčová on 6/15/19.
//  Copyright © 2019 Natálie Stepankevyčová. All rights reserved.
//

#ifndef CargoShip_h
#define CargoShip_h


#include "Ship.hpp"
#include<string>

// class inherited from ship
class CargoShip : public Ship
{
    int capacity;
public:
    CargoShip();
    //Overloaded constructor that has variables from ship class
    CargoShip(string n, string y, int t):Ship(n,y)
    {
        capacity = t;
    }
    //destructor
    ~CargoShip(){};

    //Print info for this class
    virtual void print()        // virtual function from ship.hpp
    {
        std::cout <<"Cargo Ship"<<std::endl;
        std::cout <<"Name: "<<getName()<<std::endl
        << "Year: " << getYear() << endl
        <<"Cargo Capacity: "<<capacity<<std::endl;
    }
    
};


#endif
