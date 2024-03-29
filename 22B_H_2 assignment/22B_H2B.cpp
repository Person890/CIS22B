/**
 CIS 22B: Homework 2B
 2D Arrays
 
 This program calls a function that takes a table of quizzes and calculates
 and stores the average of each quiz.
 
 For the data shown below, the averages should be:
    10.00, 8.00, 9.00, 9.00, 7.00, 7.75, 9.25, 9.50
 
 Find and fix errors. Run the program and save the output
 as a comment at the end of the program.
 
 NAME:
*/

#include <iostream>

using namespace std;

const int STU = 5;
const int QUIZZES = 10;

void calcQuizAvg(int table[][], int nStu, int nQuiz,  double qAvg[] );

int main( void )
{
    int stu     = 4; //  actual number of students
    int quizzes = 8; //  a total of 8 quizzes
    int table [STU] [QUIZZES] =
    {
        {10,  8,  9, 10,  4,  7, 10,  9},
        {10,  8,  9,  8,  6,  8,  9, 10},
        {10,  8,  9,  8,  9,  8,  8,  9},
        {10,  8,  9, 10,  9,  8, 10, 10},
    };
    double qAvg[STU];
    
    calcQuizAvg( table[][], stu, quizzes, qAvg[] );
    
    for (int i = 0; i < quizzes; i++)
        cout << qAvg[i] << " ";
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
void calcQuizAvg(int table[][], int nQuiz, int nStu, double qAvg )
{
    int sum = 0;
    
    for( int c = 1; c <= nQuiz; c++ )
    {
        for( int r = 1; r <= nStu; r++ )
        {
            sum += table[r][c];
            qAvg[r] = sum / nQuiz;
        }
    }
} 


/** Save the correct output below

 
*/
