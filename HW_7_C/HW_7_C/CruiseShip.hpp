//
//  CruiseShip.h
//  HW_7_C
//
//  Created by Natálie Stepankevyčová on 6/15/19.
//  Copyright © 2019 Natálie Stepankevyčová. All rights reserved.
//

#ifndef CruiseShip_h
#define CruiseShip_h

#include <string>
#include "Ship.hpp"

using namespace std;

// class inherited from ship
class CruiseShip : public Ship
{

private:
    int maxPassengers;
public:
    
    CruiseShip();
    //Overloaded constructor that contains variables from ship class
    CruiseShip(string n, string y, int p): Ship(n,y){
        maxPassengers = p;
    };
    //destructor
    ~CruiseShip(){};
    
    
    //print function
    virtual void print()        // virtual function from ship.hpp
    {
        cout <<"Cruise Ship"<<endl;
        cout <<"Name: "<< getName() <<endl
        << "Year: " << getYear() << endl
        <<"Maximum Passangers: "<< maxPassengers
        << endl << endl << endl;
    }
};

#endif
