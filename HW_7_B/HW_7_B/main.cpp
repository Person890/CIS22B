//
//  main.cpp
//  HW_7_B_final
//
//  Created by Natálie Stepankevyčová on 6/15/19.
//  Copyright © 2019 Natálie Stepankevyčová. All rights reserved.
//

#include <iostream>
#include "Employee.hpp"
#include "ProductionWorker.hpp"
#include <string>
#include <iomanip>

using namespace std;

int main() {
    
    string name;
    int number;
    int hireDate;
    int shift;
    double hourlyPayRate;
    
    ProductionWorker employee;
    
    cout << "Please enter information about an employee. \n";
    
    cout << "Name: ";
    getline(cin, name);
    while (name == ""){
        cout << "Please enter valid name: ";
        getline(cin, name);
    }
    employee.setName(name);
    
    cout << "Employee number: ";
    cin >> number;
    while (number <= 0){
        cout << "Please enter valid number: ";
        cin >> number;
    }
    employee.setNumb(number);
    
    cout << "Hire Date (MMDDYYYY): ";
    cin >> hireDate;
    while(hireDate == 00000001){
        cout << "Please enter valid date: ";
        cin >> hireDate;
    }
    employee.setDate(hireDate);
    
    cout << "Shift: ";
    cin >> shift;
    while (shift != 1 && shift !=2) {
        cout << "Please enter valid shift (1 or 2): ";
        cin >> shift;
    }
    employee.setShift(shift);
    
    cout << "Hourly Pay Rate: ";
    cin >> hourlyPayRate;
    while (hourlyPayRate <= 0) {
        cout << "Please enter valid hourly pay rate:";
        cin >> hourlyPayRate;
    }
    employee.setHourlyPayRate(hourlyPayRate);
    

    cout << "\n\n\n";
    cout << setw(30) << left << "Information about employee:\n";
    cout << "==============================\n";
    cout << setw(20) << left << "Name: "
    << setw(20) << fixed << employee.getName() << endl;
    cout << setw(20) << left << "Employee number: "
    << setw(20) << fixed << employee.getNumb() << endl;
    cout << setw(20) << left << "Hire Date: "
    << setw(20) << fixed << employee.getDate() << endl;
    cout << setw(20) << left << "Shift: "
    << setw(20) << fixed << employee.getShift() << endl;
    cout << setw(20) << left << "Hourly pay rate: "
    << setw(20) << fixed << employee.getHourlyPayRate() << endl << endl;
   
    cout << "The end. Thank you for using my program.\n";
  

    
    return 0;
}


/***********************************************************
 
 OUTPUT BELOW
 
 Please enter information about an employee.
 Name: John Snow
 Employee number: 902030
 Hire Date (MMDDYYYY): 05091999
 Shift: 3
 Please enter valid shift (1 or 2): 2
 Hourly Pay Rate: 10.50
 
 
 
 Information about employee:
 ==============================
 Name:               John Snow
 Employee number:    902030
 Hire Date:          5091999
 Shift:              2
 Hourly pay rate:    10.500000
 
 The end. Thank you for using my program.
 Program ended with exit code: 0
 
***********************************************************/
