//
//  main.cpp
//  HW_2_2
//
//  Created by Natálie Stepankevyčová on 4/19/19.
//  Copyright © 2019 Natálie Stepankevyčová. All rights reserved.
//

/**
 CIS 22B: Homework 2B
 2D Arrays
 
 This program calls a function that takes a table of quizzes and calculates
 and stores the average of each quiz.
 
 For the data shown below, the averages should be:
 10.00, 8.00, 9.00, 9.00, 7.00, 7.75, 9.25, 9.50
 
 Find and fix errors. Run the program and save the output
 as a comment at the end of the program.
 
 NAME: Natalie Stepankevycova
 */

#include <iostream>
#include <iomanip>

using namespace std;

const int STU = 4;      //  actual number of students
const int QUIZZES = 8;  //  a total of 8 quizzes

void calcQuizAvg(int[STU][QUIZZES], int STU, int QUIZZES, double[]);
//void calcQuizAvg(int table[][QUIZZES], int STU, int QUIZZES, double qAvg[]);

int main( void )
{
    
    int table [STU] [QUIZZES] =
    {
        {10,  8,  9, 10,  4,  7, 10,  9},
        {10,  8,  9,  8,  6,  8,  9, 10},
        {10,  8,  9,  8,  9,  8,  8,  9},
        {10,  8,  9, 10,  9,  8, 10, 10},
    };
    double qAvg[QUIZZES];
    
    calcQuizAvg(table, STU, QUIZZES, qAvg);
    
    for (int i = 0; i < QUIZZES; i++){
        if (i > 0)
            cout <<", ";
        cout << setprecision(2) << fixed << qAvg[i];
    }
    cout << endl;
    
    return 0;
}   // main



/*********************************************************************
 This function takes a table of quizzes and calculates and stores the
 average of each quiz
 PRE: - table[][] - has data
 - nStu
 - nQuiz
 - qAvg[] - empty
 POST: qAvg[] - contains the average for each quiz
 */
void calcQuizAvg(int table[STU][QUIZZES], int STU, int QUIZZES, double qAvg[])
{
    double sum = 0;
    
    /*
    for(int r = 0; r <= STU-1; r++ )
    {
        for( int c = 0; c <= QUIZZES-1; c++ )
        {
            cout << table[r][c] << " ";
        }
        cout << endl;
    }
    */

    for(int c = 0; c < QUIZZES; c++ )
    {
        sum = 0;
        for( int r = 0; r < STU; r++ )
        {
            sum += table[r][c];
        }
        qAvg[c] = sum / STU;
    }
    
}


/** OUTPUT
 
 10.00, 8.00, 9.00, 9.00, 7.00, 7.75, 9.25, 9.50
 Program ended with exit code: 0
 
 
 */
