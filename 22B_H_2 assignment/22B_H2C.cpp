/**
 CIS 22B: Homework 2C
 2D Arrays
 
 Project: Perfect Square Table
 A “Perfect Square Table” is a square of positive integers such that the
 sum of each row, column, and diagonal is the same constant.
 This program reads square tables from files, checks if they are perfect squares,
 and displays messages such as “This is a Perfect Square Table with a constant of 34!”
 or “This is not a Perfect Square Table”.
 
 NAME:
 IDE:
 
 */

#include <iostream>

using namespace std;

const int MAXTBLSIZE = 100;  // the maximum table size is 100


int main( void )
{
    string fileName[] = {"T0.txt", "T1.txt", "T2.txt", "TA.txt", "T3.txt", "T4.txt", "T5.txt", "T6.txt", "T7.txt", ""};
    int table[MAXTBLSIZE][MAXTBLSIZE] = {0};
    int tblSize;     // the number of rows and columns
    int tblConstant; // -1 if it is not a perfect table or the table's constant otherwise
    int choice = 1;  // to stop the program to allow the user to see the results one table at a time
    
    // test loop: takes the names of 7 input files from an array
    for (int i = 0; choice == 1 && fileName[i] != ""; i++)
    {
        if (readTable(fileName[i], table, tblSize))
        {
            tblConstant = testTable(table, tblSize);
            printTable(table, tblSize);
            printResults(tblConstant);
        }
        else
        {
            cout << "Error: Input file \"" << fileName[i] << "\" not found!" << endl;
        }
        
        cout << "Please enter 1 to continue 0 to stop" << endl;
        cin >> choice;
    }
    
    return 0;
}   // main


/** Save the output below
 
 
 */
