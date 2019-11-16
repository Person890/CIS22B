//
//  main.cpp
//  22B_3C
//
//  Created by Natálie Stepankevyčová on 5/7/19.
//  Copyright © 2019 Natálie Stepankevyčová. All rights reserved.
//

/**
 CIS 22B: Homework 3C
 
 Survey Statistics
 
 NAME:  Natalie Stepankevycova
 */
#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;


// Function prototypes
int *readSurveyData(string filename, int &n);
void insertionSort(int *pAry, int *pLast);
void writeArray(int *pAry, int *pLast);
void writeArray(string filename, int *pAry, int *pLast);
double calcAvg(int *pAry, int *pLast, int &smallest, int &largest);
void displayStats(int n, double avg, int smallest, int largest);

int main()
{
    // names of the input files to be tested
    string inFileName[]  =
    {"videogamesurvey.txt", "gamestats.txt", "survey.txt", "testempty.txt", "wrongfile", ""};
    
    // names of the output files
    string outFileName[] =
    {"surveyOut.txt", "statsOut.txt", "out.txt", "testemptyOut.txt", "wrongfileOut", ""};
    int choice = 1;  // to stop the program to allow the user to see the results one file at a time
    
    int n = 0;
    int *pAry;
    double avg;
    int smallest;
    int largest;
    
    // test loop: takes the names of 4 input files from an array
    for (int i = 0; choice == 1 && inFileName[i] != ""; i++)
    {
        pAry = readSurveyData(inFileName[i], n);
        if (pAry) // not NULL
        {
            int *pLast = (pAry + n - 1);
            insertionSort(pAry, pLast);
            writeArray(pAry, pLast);                    // Write sorted array to the screen
            writeArray(outFileName[i], pAry, pLast);    // Write sorted array to a file
            avg = calcAvg(pAry, pLast, smallest, largest);
            displayStats(n, avg, smallest, largest);    // print stats to screen
            
            delete [] pAry;             // deleting dynamically allocated array
            pAry = NULL;
            
        }
        else
        {
            cout << "FILE " << inFileName[i] << " NOT FOUND" << endl;
        }
        cout << "Please enter 1 to continue 0 to stop" << endl;
        cin >> choice;      // if user wants to continue
    }

    return 0;
}

/***************************************************************
 This function reads data from an input file into a dynamically
 allocated array
 filename - the name of the input file
 n - the array size (an output parameter)
 Return - the dynamically allocated array or NULL if
 the file does not exist or if it is empty
 */
int *readSurveyData(string filename, int &n)
{
    ifstream infile;
    infile.open(filename);
    
    if (!infile){
        return NULL;
    }
    
    infile >> n;
    
    int *inFileName = new int[n];     // creating new dynamically allocated array
    for (int *ptr = inFileName; ptr < (inFileName + n ); ptr++){
        infile >> *ptr;
    }
    
    infile.close();             // close file
    return inFileName;          // return pointer to dynamic array
}

/***************************************************************
 This function performs an ascending order insertion sort on an
 array.
 pList - points to the first element in array
 pLast - points to the last element in array
 */
void insertionSort(int *pAry, int *pLast)
{
    for (int *curr = pAry + 1; curr <= pLast; curr++)
    {
        int hold = *curr;                       // copy current element to hold
        int *back = curr - 1;
        while (back >= pAry && hold < *back)   // search where to insert the current element
        {
            *(back + 1) = *back;                // shift to the right
            back--;
        }
        *(back + 1) = hold;                   // put hold back to the array
    }
}

/***************************************************************
 This function writes the contents of an array to the screen
 pAry - points to the first element in array
 pLast - points to the last element in array
 */
void writeArray(int *pAry, int *pLast)
{
    for (int *ptr = pAry; ptr <= pLast; ptr++)
        cout << *ptr << " " << endl;
}

/***************************************************************
 This function writes the contents of an array to a file
 filename - name of the output file
 pList - points to the first element in array
 pLast - points to the last element in array
 */

void writeArray(string filename, int *pAry, int *pLast)
{
    ofstream myfile (filename);         // create new output file(s)
    if (myfile.is_open()){
        myfile << (pLast - pAry) + 1 << endl;
        for (int *ptr = pAry; ptr <= pLast; ptr++){
        myfile << *ptr << " " << endl;
        }
    }
     myfile.close();            // close file
}

/***************************************************************
 Calculate the average of the numbers in an array without the
 lowest and the highest values. The array is sorted in ascending order.
 pList - points to the first element in the array
 pLast - points to the last element in the array
 smallest - smallest number of array passed by reference
 largest - largest number of array passed by reference
 */
double calcAvg(int *pAry, int *pLast, int &smallest, int &largest)
{
  
    smallest = *pAry;       //assuming first value is smallest
    largest = *pAry;        // and largest
    double avg = 0;
    double total = 0;
    for (int *ptr = pAry; ptr <= pLast; ptr++)      // calculating total
    {
        total += *ptr;
        if (*ptr < smallest)
            smallest = *ptr;
        if (*ptr > largest)
            largest = *ptr;
    }
    avg = (total - smallest - largest) / ((pLast - pAry) - 1);
        // calculating average without smallest and largest value
    return avg;
}

/***************************************************************
 This function displays statistics
 n - number of students
 avg - average
 smallest - smallest value in the array
 largest - larges value in the array
 */
void displayStats(int n, double avg, int smallest, int largest)
{
    cout << setprecision(1) << fixed;
    cout << "The number of students surveyed is: " << n << endl;
    cout << "The average of hours per week students play video games: "
         << avg << endl;
    cout << "The smallest number of hours played is: " << smallest << endl;
    cout << "The largest number of hours played is: " << largest << endl;
    
}


/***************************************************************
 Save the OUTPUT below
 
 4
 4
 7
 9
 10
 The number of students surveyed is: 5
 The average of hours per week students play video games: 6.7
 The smallest number of hours played is: 4
 The largest number of hours played is: 10
 Please enter 1 to continue 0 to stop
 1
 0
 0
 1
 1
 2
 2
 3
 3
 4
 5
 The number of students surveyed is: 10
 The average of hours per week students play video games: 2.0
 The smallest number of hours played is: 0
 The largest number of hours played is: 5
 Please enter 1 to continue 0 to stop
 1
 0
 0
 0
 1
 1
 1
 1
 1
 2
 2
 2
 2
 2
 3
 3
 3
 7
 8
 8
 8
 8
 8
 9
 9
 9
 11
 12
 The number of students surveyed is: 27
 The average of hours per week students play video games: 4.4
 The smallest number of hours played is: 0
 The largest number of hours played is: 12
 Please enter 1 to continue 0 to stop
 1
 FILE testempty.txt NOT FOUND
 Please enter 1 to continue 0 to stop
 1
 FILE wrongfile NOT FOUND
 Please enter 1 to continue 0 to stop
 1
 Program ended with exit code: 0
 */


