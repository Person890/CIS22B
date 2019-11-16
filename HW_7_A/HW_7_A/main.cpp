//
//  main.cpp
//  HW_7_A
//
//  Created by Natálie Stepankevyčová on 6/11/19.
//  Copyright © 2019 Natálie Stepankevyčová. All rights reserved.
//

#include <iostream>
#include "NumDays.hpp"


using namespace std;

int main(){
    
    // variables to save user's input
    int usersHours1;
    int usersHours2;
    
    cout << "Please enter number of hours: ";
    cin >> usersHours1;
        while (usersHours1 <0){    // input validation
            cout << "Please enter valid number of hours: ";
            cin >> usersHours1;
        }
    cout << "Please enter another number of hours: ";
    cin >> usersHours2;
    while (usersHours1 <0){
        cout << "Please enter valid number of hours: ";
        cin >> usersHours1;
    }
    
    // defining objects
    NumDays days1(usersHours1);
    NumDays days2(usersHours2);
    // defining sum
    NumDays sum = days1 + days2;
    NumDays difference = days2 - days1;
    
    
    cout << "First number of days worked: " << days1.getDays() << endl;
    cout << "Second number of days worked: " << days2.getDays() << endl;
    cout << "Number of hours worked together: " << sum.gethours() << endl <<endl;
    cout << "The difference between the two days: " << abs(difference.gethours())
    << endl <<endl;
    
    // decrementing number of hours by one
    days1--;
    days2--;
    cout << "First number of hours decremented: " << days1.gethours() << endl;
    cout << "Second number of hours decremented: " << days2.gethours() << endl;
    cout << "First number of days after decrement: " << days1.getDays() << endl;
    cout << "Second number of days after decrement: " << days2.getDays() << endl
    << endl <<endl;
    
    //incrementing number of hours for day 1 and 2 by one compared to original
    days1++;
    days1++;
    days2++;
    days2++;
    cout << "First number of hours incremented: " << days1.gethours() << endl;
    cout << "Second number of hours incremented: " << days2.gethours() << endl;
    cout << "First number of days after increment: " << days1.getDays() << endl;
    cout << "Second number of days after increment: " << days2.getDays() << endl;
    
    return 0;
}
/********************************************************
 OUTPUT BELOW
 
Please enter number of hours: 20
Please enter another number of hours: 90
First number of days worked: 2.5
Second number of days worked: 11.25
Number of hours worked together: 110

The difference between the two days: 70

First number of hours incremented: 21
Second number of hours incremented: 91
First number of days incremented: 2.625
Second number of days incremented: 11.375
Program ended with exit code: 0


*********************************************************/
