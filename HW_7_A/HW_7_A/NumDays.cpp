//
//  NumDays.cpp
//  HW_7_A
//
//  Created by Natálie Stepankevyčová on 6/11/19.
//  Copyright © 2019 Natálie Stepankevyčová. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "NumDays.hpp"

NumDays::NumDays(){     // default constructor;
    hours = 0;
    days = 0;
}

/****************************************************************
 This overloaded constructor takes int from a user and calculates number of hours worked
 as number of days.
 IN - _hours from user
 ****************************************************************/
NumDays::NumDays(int _hours){
    hours = _hours;
    days = (hours / 8.0);
}


// overloading + operator
NumDays NumDays::operator+(const NumDays & overloaded){
    NumDays sum(hours + overloaded.hours);
    return sum;
}

// overloading - operator
NumDays NumDays::operator-(const NumDays & overloaded){
    NumDays difference(hours - overloaded.hours);
    return difference;
}

// overloading ++
NumDays NumDays::operator++(int){
    NumDays temp(hours);
    hours++;
    days = (hours / 8.0);
    return temp;
}

// overloading --
NumDays NumDays::operator--(int){
    NumDays temp(hours);
    hours--;
    days = (hours / 8.0);
    return temp;
}


//Destructor
NumDays::~NumDays()
{
}

