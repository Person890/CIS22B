//
//  ProductionWorker.hpp
//  HW_7_B_final
//
//  Created by Natálie Stepankevyčová on 6/15/19.
//  Copyright © 2019 Natálie Stepankevyčová. All rights reserved.
//

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Employee.hpp"
#include <string>

class ProductionWorker : public Employee{
    
private:
    int shift;
    double hourlyPayRate;
    
public:
    // getters
    int getShift() const {return shift;}
    double getHourlyPayRate() const {return hourlyPayRate;}
    //setters
    void setShift(int _shift);
    void setHourlyPayRate(double _payRate);
    
    //default constructor
    ProductionWorker();
    
    //overloaded constructor
    ProductionWorker(int _shift, double _hourlyPayRate);
    
    // destructor
    ~ProductionWorker(){};
    
};

#endif
