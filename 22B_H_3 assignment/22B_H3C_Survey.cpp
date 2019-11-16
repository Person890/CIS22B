/**
 CIS 22B: Homework 3C
 
 Survey Statistics
 
 NAME:
 */
#include <iostream>
#include <iomanip>
using namespace std;

#ifdef _MSC_VER
#include <crtdbg.h>  // needed to check for memory leaks (Windows only!)
#endif

// Function prototypes
int *readSurveyData(string filename, int &n);
void insertionSort(int *pAry, int *pLast);
void writeArray(int *pAry, int *pLast);
void writeArray(string filename, int *pAry, int *pLast);
double calcAvg(int *pAry, int *pLast);
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
    
    int n;
    int *pAry;
    double avg;
    
    // test loop: takes the names of 4 input files from an array
    for (int i = 0; choice == 1 && inFileName[i] != ""; i++)
    {
        pAry = readSurveyData(inFileName[i], n);
        if (pAry) // not NULL
        {
            int *pLast = pAry + n - 1;
            insertionSort(pAry, pLast);
            writeArray(pAry, pLast);                    // Write sorted array to the screen
            writeArray(outFileName[i], pAry, pLast);    // Write sorted array to a file
            avg = calcAvg(pAry, pLast);
            // displayStats(); // Add parameters here
            
        }
        else
        {
            // write an error message
        }
        cout << "Please enter 1 to continue 0 to stop" << endl;
        cin >> choice;
    }
    
#ifdef _MSC_VER
    cout << _CrtDumpMemoryLeaks() ? "Memory Leak\n" : "No Memory Leak\n";
#endif
    
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
    return NULL; // This line should be changed
}

/***************************************************************
 This function performs an ascending order insertion sort on an
 array.
 pList - points to the first element in array
 pLast - points to the last element in array
 */
void insertionSort(int *pAry, int *pLast)
{
    
}
/***************************************************************
 This function writes the contents of an array to the screen
 pList - points to the first element in array
 pLast - points to the last element in array
 */
void writeArray(int *pAry, int *pLast)
{
    
}

/***************************************************************
 This function writes the contents of an array to a file
 filename - name of the output file
 pList - points to the first element in array
 pLast - points to the last element in array
 */
void writeArray(string filename, int *pAry, int *pLast)
{
    
}

/***************************************************************
 Calculate the average of the numbers in an array without the
 lowest and the highest values. The array is sorted in ascending order.
 pList - points to the first element in the array
 pLast - points to the last element in the array
 */
double calcAvg(int *pAry, int *pLast)
{
    double avg = 0;
    
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
    
}


/***************************************************************
 Save the OUTPUT below
 
 
 */


