//
//  main.cpp
//  HW2_1A
//
//  Created by Natálie Stepankevyčová on 4/17/19.
//  Copyright © 2019 Natálie Stepankevyčová. All rights reserved.
//

/**
 CIS 22B: Homework 2A
 2D Arrays
 
 This program prints a 2D array as a table, one row per line.
 It compiles and runs, but it provides an unexpected output.
 
 Find and fix errors. Run the program and save the output
 as a comment at the end of the program.
 
 NAME: Natalie Stepankevycova
 */

#include <iostream>

using namespace std;

const int ROWS = 10;  // maximum number of rows
const int COLS = 5;   // maximum number of columns

int main (void)
{
    int table [ROWS] [COLS] =
    {
        {112, 90, 50, 60, 20},
        {223, 15, 25, 45, 35},
        {334, 49, 89, 29, 59},
        {445, 82, 92, 52, 12}
    };
    
    int n_rows = 4; // actual number of rows
    int n_cols = 5; // actual number of columns
    
    // print the table
    for( int r = 0; r <= n_rows-1; r++ )
    {
        for (int a = 0; a < n_cols; a++){
            cout << table [r] [a] << " ";
            
        }
        cout << endl;
    }
    
    
    return 0;
}

/** OUTPUT
 
 112 90 50 60 20
 223 15 25 45 35
 334 49 89 29 59
 445 82 92 52 12
 Program ended with exit code: 0
 
 
 
 */
