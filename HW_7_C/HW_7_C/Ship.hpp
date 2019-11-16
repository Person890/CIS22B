//
//  Ship.hpp
//  HW_7_C
//
//  Created by Natálie Stepankevyčová on 6/15/19.
//  Copyright © 2019 Natálie Stepankevyčová. All rights reserved.
//

#ifndef Ship_hpp
#define Ship_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Ship
{
    
private:
    string name;
    string year;
    
public:
    Ship();
    Ship(string _name, string _year){
        name = _name;
        year = _year;
    }
    //destructor
    ~Ship(){};
    
    //getters
    string getName(){return name;}
    string getYear(){return year;}
    
    //Print info for this function
    virtual void print()
    {
        cout <<"Ship"<< endl;
        cout <<"Name: "<<name<< endl
        << "Year Built: "<<year<< endl
        << endl << endl;
    }
};

#endif
