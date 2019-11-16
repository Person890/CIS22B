//
//  Employee.cpp
//  HW_7_B_final
//
//  Created by Natálie Stepankevyčová on 6/15/19.
//  Copyright © 2019 Natálie Stepankevyčová. All rights reserved.
//

#include "Employee.hpp"
#include <string>
#include <iostream>

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

using namespace std;


Employee::Employee()
{
    name = "N/A";
    numb = 0;
    date = 00000000;
}
Employee::Employee(std::string nam, int num, int dat)
{
    name = nam;
    numb = num;
    date = dat;
}

void Employee::setName(string _name){
        name = _name;
}

void Employee::setNumb(int _number){
    numb = _number;
}

void Employee::setDate(int _date){
    date = _date;
}


#endif
