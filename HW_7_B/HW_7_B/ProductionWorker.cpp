//
//  ProductionWorker.cpp
//  HW_7_B_final
//
//  Created by Natálie Stepankevyčová on 6/15/19.
//  Copyright © 2019 Natálie Stepankevyčová. All rights reserved.
//

#include "ProductionWorker.hpp"


#include "ProductionWorker.hpp"
#include "Employee.hpp"
#include <iostream>
#include <iomanip>
#include <stdio.h>

//default constructor
ProductionWorker::ProductionWorker(){
    shift = 0;
    hourlyPayRate = 0.0;
}

//overloaded constructor
ProductionWorker::ProductionWorker(int _shift, double _hourlyPayRate){
    shift = _shift;
    hourlyPayRate = _hourlyPayRate;
}

void ProductionWorker::setShift(int _shift){
    shift = _shift;
}

void ProductionWorker::setHourlyPayRate(double _hourlyPayRate){
    hourlyPayRate = _hourlyPayRate;
}

