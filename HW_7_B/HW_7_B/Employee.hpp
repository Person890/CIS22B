//
//  Employee.hpp
//  HW_7_B_final
//
//  Created by Natálie Stepankevyčová on 6/15/19.
//  Copyright © 2019 Natálie Stepankevyčová. All rights reserved.
//

#ifndef Employee_hpp
#define Employee_hpp

#include <stdio.h>
#include <string>


class Employee
{
private:
    std::string name;
    int numb;
    int date;
public:
    //Constructors
    Employee();
    Employee(std::string nam, int num, int dat);
    
    //destructor
    ~Employee(){};
    
    //Mutators (public)
    void setName(std::string value);
    void setNumb(int value);
    void setDate(int value);
    
    //Accessors (public)
    std::string getName() const {return name;}
    int getNumb() const {return numb;}
    int getDate() const {return date;}
};


#endif

