//
//  main.cpp
//  HW_7_C
//
//  Created by Natálie Stepankevyčová on 6/15/19.
//  Copyright © 2019 Natálie Stepankevyčová. All rights reserved.
//

#include <iostream>
#include "Ship.hpp"
#include "CruiseShip.hpp"
#include "CargoShip.hpp"

void print(const Ship *);

int main()
{

    /*      Attempt to make array of Ships
     
    Ship ships[3] =
    {    Ship ("Titanic", "1918"),
         CruiseShip("Queen Mary", "1990", 250),
         CargoShip("Queen Elisabeth", "2000", 300)
    };
    
    */
    
    //creating objects
    Ship one ("Titanic", "1918");
    CruiseShip two ("Queen Elisabeth", "2000", 300);
    CargoShip three ("Queen Mary", "1990", 250);
    
     
     
    Ship * ptrOne = &one;
    Ship * ptrTwo = &two;
    Ship * ptrThree = &three;
    
    
    //calling print functions using pointers
    ptrOne->print();
    ptrTwo->print();
    ptrThree->print();


    return 0;
}

/***************************************************************
 OUTPUT BELOW
 
 Ship
 Name: Titanic
 Year Built: 1918
 
 
 Cruise Ship
 Name: Queen Elisabeth
 Year: 2000
 Maximum Passangers: 300
 
 
 Cargo Ship
 Name: Queen Mary
 Year: 1990
 Cargo Capacity: 250
 Program ended with exit code: 0
 
 ********************************************************/
