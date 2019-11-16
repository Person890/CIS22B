//
//  main.cpp
//  HW_2_C
//
//  Created by Natálie Stepankevyčová on 4/22/19.
//  Copyright © 2019 Natálie Stepankevyčová. All rights reserved.
//

/**
 CIS 22B: Homework 2C
 2D Arrays
 
 Project: Perfect Square Table
 A “Perfect Square Table” is a square of positive integers such that the
 sum of each row, column, and diagonal is the same constant.
 This program reads square tables from files, checks if they are
 perfect squares, and displays messages such as
 “This is a Perfect Square Table with a constant of 34!”
 or “This is not a Perfect Square Table”.
 
 NAME:  Natalie Stepankevycova
 IDE:   Xcode
 
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAXTBLSIZE = 100;  // the maximum table size is 100
const int COLUMNWIDTH = 3;

bool readTable(string, int[][MAXTBLSIZE], int&);
int tblConstant(int [][MAXTBLSIZE], int);
int testTable(int [][MAXTBLSIZE], int);
void printTable(int [][MAXTBLSIZE], int);
void printResults(int);


int main( void )
{
    string fileName[] = {"T0.txt", "T1.txt", "T2.txt", "TA.txt",
        "T3.txt", "T4.txt", "T5.txt", "T6.txt", "T7.txt", ""};
    int table[MAXTBLSIZE][MAXTBLSIZE] = {0};
    int tblSize;     // the number of rows and columns
    int tblConstant; // -1 if it is not a perfect table or the table's constant otherwise
    int choice = 1;  // to stop the program to allow the user to see the results one table at a time
    
    // test loop: takes the names of 7 input files from an array
    for (int i = 0; choice == 1 && fileName[i] != ""; i++)
    {
        if (readTable(fileName[i], table, tblSize))
        {
            // assigns value of sum or -1 if not perfect square
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


/** =================================== */
/* Check if the value I am trying to read exists and can be read
 Pre: name of the file, table - empty 2D array to put values in,
    tblSize - to see how many rows does the file have
 Post: change tblSize (for later display) - passed by reference
 Return: true or false - if the file exists
 */

bool readTable(string fileName,int table[][MAXTBLSIZE], int& tblSize){
    ifstream infile;
    infile.open(fileName);
    
    if (infile.fail())
        return false;
    
    infile >> tblSize;
    
    for (int rows = 0; rows < tblSize; rows++){
        for(int columns = 0; columns < tblSize; columns++){
            infile >> table [rows][columns];
        }
    }
    
    return true;
} // called first


/** =================================== */
/*  This function takes a table of integers that are in text files
 and tests if they are "perfect square" --> sum of each row, each column,
 and two diagonals is the same. Function assigns one running sum and
 in the end checks if all sums equal to runnig sum.
 Pre: table[][] - has data, tblSize - has the number of rows and
    columns (same since it's square)
 Post: doesn't change table, just looks for whether the sum of R and C is the same
 Return: sum - returns either -1 if it is not perfect square, or the value of sum
 */

int testTable(int table[][MAXTBLSIZE], int tblSize){
    
    int sum = 0;
    int currentSumR = 0;
    int currentSumC = 0;
    int currentSumD1 = 0;
    int currentSumD2 = 0;
    
    // loops through the table
    for (int rows = 0; rows < tblSize; rows++){
        for(int columns = 0; columns < tblSize; columns++){
            currentSumR += table[rows][columns];
            currentSumC += table[columns][rows];
            
            // test for sum of diagonals
            if (rows == columns) {
                currentSumD1 += table[rows][columns];
                currentSumD2 += table[rows][tblSize - columns - 1];
            }
        }
        if (rows == 0) sum = currentSumR;
        
        if (currentSumR != sum || currentSumC != sum) return -1;
        currentSumR = 0;
        currentSumC = 0;
    }
    
    if (currentSumD1 != sum || currentSumD2 != sum) return -1;
    
    return sum;
}

/** =================================== */
/*  This function takes a table of integers that are in text files
 and prints them out in a grid only if the number of rows and columns
 is less than 8. If larger than 8, displays just the size
 Pre: table[][] - has data, tblSize - has the number of rows and columns
        (tblSize same since it's square)
 Post: displays table with the grid and the size of table
 Return: does not return anything
 */

void printTable(int table[][MAXTBLSIZE], int tblSize){
    if (tblSize <= 100){
        
        string rowSeparator = "";
        for (int i = 0; i < (COLUMNWIDTH + 1) * tblSize + 1; i++){
            rowSeparator += "-";    // add dash depending on table size
        }
        
        for (int rows = 0; rows < tblSize; rows++){
            
            cout << rowSeparator << endl;
            
            for(int columns = 0; columns < tblSize; columns++){
                cout << "|";
                cout << setw(COLUMNWIDTH) << table [rows][columns];
            }       // set width as three for the integers in grid
            cout << "|"<< endl;     // vertical separators
        }
        
        cout << rowSeparator << endl; // last vertical separator
        
    }
    cout <<"TABLE SIZE IS  " << tblSize << endl;
}


/** =================================== */
/*  This function checks tblConstant (a value returned from function testTable).
 If tblConstant is -1, it displays that it's not perfect squere,
 otherwise displays message saying it is perfect square and value
 of sum of each row
 Pre: tblConstant - sum of row or -1
 Post: displays message
 Return: void - does not return anything
 */
void printResults(int tblConstant){
    
    if (tblConstant == -1)
        cout << "This is not a Perfect Square Table" << endl;
    else {
        cout << "This is a Perfect Square Table with a constant of "
        << tblConstant << "!" << endl;
    }
}


/** OUTPUT
 
 -----------------
 | 16|  3|  2| 13|
 -----------------
 |  5| 10| 11|  8|
 -----------------
 |  9|  6|  7| 12|
 -----------------
 |  4| 15| 14|  1|
 -----------------
 TABLE SIZE IS  4
 This is a Perfect Square Table with a constant of 34!
 Please enter 1 to continue 0 to stop
 1
 -----------------
 | 16|  3|  2| 13|
 -----------------
 |  5| 10| 11|  8|
 -----------------
 |  9|  6|  7| 12|
 -----------------
 |  4| 15|  1| 14|
 -----------------
 TABLE SIZE IS  4
 This is not a Perfect Square Table
 Please enter 1 to continue 0 to stop
 1
 ---------------------
 |  3| 16|  9| 22| 15|
 ---------------------
 | 20|  8| 21| 14|  2|
 ---------------------
 |  7| 25| 13|  1| 19|
 ---------------------
 | 24| 12|  5| 18|  6|
 ---------------------
 | 11|  4| 17| 10| 23|
 ---------------------
 TABLE SIZE IS  5
 This is a Perfect Square Table with a constant of 65!
 Please enter 1 to continue 0 to stop
 1
 Error: Input file "TA.txt" not found!
 Please enter 1 to continue 0 to stop
 1
 -------------------------
 | 35|  1|  6| 26| 19| 24|
 -------------------------
 |  3| 32|  7| 21| 23| 25|
 -------------------------
 | 31|  9|  2| 22| 27| 20|
 -------------------------
 |  8| 28| 33| 17| 10| 15|
 -------------------------
 | 30|  5| 34| 12| 14| 16|
 -------------------------
 |  4| 36| 29| 13| 11| 18|
 -------------------------
 TABLE SIZE IS  6
 This is not a Perfect Square Table
 Please enter 1 to continue 0 to stop
 1
 -------------------------------------
 | 18|  7| 26| 42| 31| 50| 66| 55| 74|
 -------------------------------------
 | 19| 38| 36| 52| 71| 60| 76| 14|  3|
 -------------------------------------
 | 32| 48| 64| 56| 81| 16|  8| 24| 40|
 -------------------------------------
 | 69| 58| 77| 12|  1| 20| 45| 34| 53|
 -------------------------------------
 | 79| 17|  6| 22| 41| 30| 46| 65| 63|
 -------------------------------------
 |  2| 27| 43| 35| 51| 67| 59| 75| 10|
 -------------------------------------
 | 39| 28| 47| 72| 61| 80| 15|  4| 23|
 -------------------------------------
 | 49| 68| 57| 73| 11|  9| 25| 44| 33|
 -------------------------------------
 | 62| 78| 13|  5| 21| 37| 29| 54| 70|
 -------------------------------------
 TABLE SIZE IS  9
 This is a Perfect Square Table with a constant of 369!
 Please enter 1 to continue 0 to stop
 1
 -------------------------------------------------
 |  9|106| 59| 61| 19| 76|110|128|137| 36| 30| 87|
 -------------------------------------------------
 | 22| 83| 69| 38| 32| 89|120|138| 11|100| 49|  7|
 -------------------------------------------------
 | 35| 93| 46| 48|  6| 99|133|115|124| 20| 77| 62|
 -------------------------------------------------
 | 39| 24| 90|112|121|139| 21| 82| 71| 53|  2|104|
 -------------------------------------------------
 | 52|  1|103|124|134|116| 34| 95| 45| 78| 63| 12|
 -------------------------------------------------
 | 65| 14| 80|135|108|126| 11|105| 58| 25| 91| 40|
 -------------------------------------------------
 |114|123|132| 33| 94| 47| 56|  5| 98| 67| 16| 73|
 -------------------------------------------------
 |127|136|109| 10|107| 57| 66| 15| 72| 86| 44| 29|
 -------------------------------------------------
 |140|113|122| 23| 81| 70| 43| 28| 85|  3| 96| 54|
 -------------------------------------------------
 | 84| 68|  4| 79| 51| 26|101| 37| 18|117|142|131|
 -------------------------------------------------
 | 97| 42| 17| 92| 64|  0| 75| 50| 31|130|119|141|
 -------------------------------------------------
 | 74| 55| 27|102| 41| 13| 88| 60|  8|143|129|118|
 -------------------------------------------------
 TABLE SIZE IS  12
 This is not a Perfect Square Table
 Please enter 1 to continue 0 to stop
 1
 -------------------------------------------------
 |  9|106| 59| 61| 19| 76|110|128|137| 36| 30| 87|
 -------------------------------------------------
 | 22| 83| 69| 38| 32| 89|120|138| 11|100| 49|  7|
 -------------------------------------------------
 | 35| 93| 46| 48|  6| 99|133|115|124| 20| 77| 62|
 -------------------------------------------------
 | 39| 24| 90|112|121|139| 21| 82| 71| 53|  2|104|
 -------------------------------------------------
 | 52|  1|103|124|134|116| 34| 95| 45| 78| 63| 12|
 -------------------------------------------------
 | 65| 14| 80|135|108|126| 11|105| 58| 25| 91| 40|
 -------------------------------------------------
 |114|123|132| 33| 94| 47| 56|  5| 98| 67| 16| 73|
 -------------------------------------------------
 |127|136|109| 10|107| 57| 66| 15| 72| 86| 44| 29|
 -------------------------------------------------
 |140|113|122| 23| 81| 70| 43| 28| 85|  8| 96| 54|
 -------------------------------------------------
 | 84| 68|  4| 79| 51| 26|101| 37| 18|117|142|131|
 -------------------------------------------------
 | 97| 42| 17| 92| 64|  0| 75| 50| 31|130|119|141|
 -------------------------------------------------
 | 74| 55| 27|102| 41| 13| 88| 60|  3|143|129|118|
 -------------------------------------------------
 TABLE SIZE IS  12
 This is not a Perfect Square Table
 Please enter 1 to continue 0 to stop
 1
 Error: Input file "T7.txt" not found!
 Please enter 1 to continue 0 to stop
 1
 Program ended with exit code: 0
 
 
 
 */




