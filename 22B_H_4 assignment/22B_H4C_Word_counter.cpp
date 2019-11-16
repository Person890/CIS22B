/**
 CIS 22B: Homework 4C
 
 Structures and Strings
 Project: Text Analyzer: Word Count
 
 NAME:
 */
#include <iostream>
#include <iomanip>
using namespace std;

const bool DE_BUG = true;  // when done debugging change the DE_BUG flag to false
const int ARY_SIZE = 100;

/* Define a struct named Word with the following fields:
 
 1. word, a string
 2. cnt, an integer
 
 */



/* Define a struct named WordStats with the following fields:
 
 1. list, an array of ARY_SIZE Word structures defined above
 2. noWords, an integer, for the number of distinct words
 3. maxLength, an integer, for the longest word's length
 4. highFreq, an integer, for the highest frequency
 
 */



// Function prototypes
void printWelcome(void);
void readWords(string inFilename, WordStats *stats);
void insertionSort(Word ary[], int size);
void printHigestFreq( const WordStats *stats);
void writeFile( string outFilename, const WordStats *stats);
void printEnd(void);

int main()
{
    string inFilename[] = {"song_row.txt", "song_ten.txt", "test.txt", ""};
    string outFilename = "";
    
    // use the following data for testing
    // insertionSort, writeFile, and printprintHigestFreq functions
    WordStats stats =
    {
        { {"a", 9},  {"boat", 21}, {"dream", 125}, {"merrily", 44}, {"row", 125}, {"stream", 5}} ,
        6,
        7,
        125
    };
    
    
    printWelcome();
    
    for (int i = 0; inFilename[i] != ""; i++)
    {
        cout << "Read data from: " << inFilename[i] << endl;
        // readWords(inFilename, &data);
        insertionSort(stats.list, stats.noWords);
        writeFile(outFilename, &stats);
        printHigestFreq(&stats);
        // generate the output file name
        cout << "Write report to: " << outFilename << endl << endl;
    }
    printEnd();
    
    return 0;
}
/**************************************************
 
 */
void buildList(string inFilename, WordStats *stats)
{
    if (DE_BUG)
        cout << "\tDEBUG: This is the readWords function" << endl;
}

/**************************************************
 
 */
void insertionSort(Word ary[], int size)
{
    if (DE_BUG)
        cout << "\tDEBUG: This is the insertionSort function" << endl;
    
}


/**************************************************
 
 */
void printHigestFreq( const WordStats *stats)
{
    if (DE_BUG)
        cout << "\tDEBUG: This is the printHigestFreq function" << endl;
}

/**************************************************
 
 */
void writeFile( string outFilename, const WordStats *stats)
{
    if (DE_BUG)
        cout << "\tDEBUG: This is the writeFile function" << endl;
}

/**************************************************
 This function displays a welcome message and briefly
 explains the purpuse of this program.
 */
void printWelcome(void)
{
    if (DE_BUG)
        cout << "\tDEBUG: This is the welcome function\n" << endl;
    cout << "\t\tHomework 4C\n\tText Analyzer: Word Count\n\n";
    cout << "Developer: " << "write your name here" << endl;
    
}

/**************************************************
 This function displays an end of the program message
 */
void printEnd(void)
{
    if (DE_BUG)
        cout << "\tDEBUG: This is the end of the program function\n" << endl;
}
/***************************************************************
 Save the OUTPUT below
 
	DEBUG: This is the welcome function
 
 Homework 4C
	Text Analyzer: Word Count
 
 Read data from: song_row.txt
	DEBUG: This is the insertionSort function
	DEBUG: This is the writeFile function
	DEBUG: This is the printHigestFreq function
 Write report to:
 
 Read data from: song_ten.txt
	DEBUG: This is the insertionSort function
	DEBUG: This is the writeFile function
	DEBUG: This is the printHigestFreq function
 Write report to:
 
 Read data from: test.txt
	DEBUG: This is the insertionSort function
	DEBUG: This is the writeFile function
	DEBUG: This is the printHigestFreq function
 Write report to:
 
	DEBUG: This is the end of the program function
 
 Program ended with exit code: 0
 */

