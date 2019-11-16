 //
//  NumDays.hpp
//  HW_7_A
//
//  Created by Natálie Stepankevyčová on 6/11/19.
//  Copyright © 2019 Natálie Stepankevyčová. All rights reserved.
//
#ifndef NUM_DAYS_H
#define NUM_DAYS_H

class NumDays{
    
    private:
        int hours;
        double days;
    
    public:
    NumDays();      // default constructor
    NumDays(int _hours);    // overloaded constructor
    
    // setters
    void sethours(int _hours){
        hours = _hours;
    }
    void setDays(double _days){
        days = _days;
    }
    
    //getters
    int gethours(){
        return hours;
    }
    double getDays(){
        return days;
    }
    
    // other functions
    NumDays operator+(const NumDays & overloaded);
    NumDays operator-(const NumDays & overloaded);
    NumDays operator++(int);
    NumDays operator--(int);

    ~NumDays();     // destructor
    

};

#endif
