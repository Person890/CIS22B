//
//  main.cpp
//  22B_4_C
//
//  Created by Natálie Stepankevyčová on 5/13/19.
//  Copyright © 2019 Natálie Stepankevyčová. All rights reserved.
//

/**
 CIS 22B: Homework 4C
 
 Structures and Strings
 Project: Text Analyzer: Word Count
 
 NAME:  Natalie Stepankevycova
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <cctype>


using namespace std;

const bool DE_BUG = false;  // when done debugging change the DE_BUG flag to false
const int ARY_SIZE = 100;

//structure of words and counts
struct Word {
    string word;
    int cnt;
};

// structure of statistics
struct WordStats {
    Word list[ARY_SIZE];
    int noWords;
    int maxLength;
    int highFreq;
};


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
    // process all the files
    for (int i = 0; inFilename[i] != ""; i++)
    {
        cout << "Read data from: " << inFilename[i] << endl;
        readWords(inFilename[i], &stats);       //
        insertionSort(stats.list, stats.noWords);
        
        // change outfile name before passing it
        outFilename = inFilename[i].erase(inFilename[i].length()-4, 4) + "_OUT.txt";
        
        writeFile(outFilename, &stats);     // write to output file
        printHigestFreq(&stats);            // print out highest frequency word
        
        cout << "Write report to: " << outFilename << endl << endl;
    }
    printEnd();     // print end message
    
    return 0;
}
/**************************************************
 This function reads words from the textfile, keeps track of the occurrences
 of each word, calculates the highest occurrence, checks which word is the longest
 IN - string inFilename - name of the file that is being read
    - WordStats *stats - pointer to the first element stats structure
 OUT - does not return anything
 */
void readWords(string inFilename, WordStats *stats)
{
    if (DE_BUG){
        cout << "\tDEBUG: This is the readWords function" << endl;
    }
    
    // reseting all the statistics
    (*stats).highFreq = 0;
    (*stats).noWords = 0;
    (*stats).maxLength = 0;
    
    for (int i = 0; i < ARY_SIZE; i++)
        (*stats).list[i] = {};      // reset stats structure
    
    ifstream infile;            // creating file
    infile.open(inFilename);
    
    if (!infile){       // validating if file is open
        cout << "File " << inFilename << " could not be opened." << endl;
    }
    else {
        
        while(!infile.eof()){                       // opening file
            string _word;
            infile >> _word;
            
            _word[0] = tolower(_word[0]);           // converting to lowercase
            if (ispunct(_word[_word.size() - 1])){  //deleting punctuation if any
                _word.pop_back();
            }
            
            // getting max length
            if (_word.length() > ((*stats).maxLength)){
                (*stats).maxLength = (int) _word.length();
            }
            
            if (_word == "") continue;      // if no word, skip it
            
            bool found = false;             // flag if word found in the array
            
            for (int i = 0; i < (*stats).noWords; i++){
               
                // getting highest frequency
                if ((*stats).list[i].cnt > (*stats).highFreq)
                    (*stats).highFreq = (*stats).list[i].cnt;

                if ((*stats).list[i].word == _word) {
                    (*stats).list[i].cnt++;     // word occurrence
                    (*stats).noWords++;         // word count
                    found = true;
                    break;
                }
            }
        
            if (found == false) {          // if the word not found in the array
                (*stats).list[(*stats).noWords].word = _word;
                (*stats).list[(*stats).noWords].cnt = 1;
                (*stats).noWords++;
            }
        }
    }
    infile.close();         // close file
}

/**************************************************
 This function sorts the array of words (with its occurrences) alphabetically
 from 'a' to 'z'
 IN - Word ary[] - array of structures
    - int size - size of the array = number of words
 OUT - does not return anything
 */
void insertionSort(Word ary[], int size)
{
    if (DE_BUG){
        cout << "\tDEBUG: This is the insertionSort function" << endl;
    }
    
    for (int i = 1; i < size; i++)  // ar[i] is element to insert
    {
       Word hold = ary[i];
        int j = 0;
        for(j = i; j > 0; j--)
            if(hold.word < ary[j - 1].word)
               ary[j] = ary[j - 1];
            else break;
        ary[j] =  hold;
    }
}

/**************************************************
 This function is calculating what is the highest occurrence of all the
 words in the file
 IN - const WordStats *stats - pointer to the first element stats structure
 structure --> const = not being changed
 OUT - not returning anything
 */
void printHigestFreq(const WordStats *stats)
{
    if (DE_BUG)
        cout << "\tDEBUG: This is the printHigestFreq function" << endl;
    int count = 0;
    

    for (int i = 0 ; i < (*stats).noWords - 1; i ++){
        if((*stats).highFreq == (*stats).list[i].cnt){
            // print out high frequency words
            cout<< setw(3) << fixed << (*stats).list[i].cnt
            << " " << (*stats).list[i].word << endl;
            count++;
        }
    }
    cout << "There is / are " << count << " high frequency word(s)." << endl;
}

/**************************************************
 This function creates a file with a filename passed to it.
 It writes statistics about input file and structure into new text file.
 IN - string outfilename - modified inputfilename
    - const WordStats *stats - pointer to the first element stats structure
    structure --> const = not being changed
 OUT - not returning anything
 */
void writeFile( string outFilename, const WordStats *stats)
{
    if (DE_BUG)
        cout << "\tDEBUG: This is the writeFile function" << endl;
    ofstream myfile (outFilename);    // creating new file to write to
    
    if (myfile.is_open())           // validating file
    {
        myfile << (*stats).noWords << " words" << endl;    //number of unique words
        myfile << "Maximum length: " << (*stats).maxLength << endl;
        myfile << "Highest frequency: " << (*stats).highFreq << endl << endl;
        
        for (int i = 0; i < stats -> noWords; i++){
            // print out high frequency and words
            if ((*stats).list[i].cnt){      // output all words and occurrences to file
            myfile << setw(3) << fixed << (*stats).list[i].cnt
            << " " << (*stats).list[i].word << endl;
            }
        }
    }
    else
        cout << "Unable to open file";
    
    myfile.close();                 // close the file
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
    cout << "Developer: " << "Natalie Stepankevycova" << endl << endl;
    cout << "Welcome! This program takes various text files as an input " << endl
         << "and outputs number of occurences of each word in the file. Enjoy." << endl << endl;
    
}

/**************************************************
 This function displays an end of the program message
 */
void printEnd(void)
{
    if (DE_BUG)
        cout << "\tDEBUG: This is the end of the program function\n" << endl;
    
    cout << "You've reached the end of the program. Goodbye." << endl;  //
}
/***************************************************************
 Save the OUTPUT below
 
 Homework 4C
 Text Analyzer: Word Count
 
 Developer: Natalie Stepankevycova
 
 Welcome! This program takes various text files as an input
 and outputs number of occurences of each word in the file. Enjoy.
 
 Read data from: song_row.txt
 4 merrily
 There is / are 1 high frequency word(s).
 Write report to: song_row_OUT.txt
 
 Read data from: song_ten.txt
 4 green
 There is / are 1 high frequency word(s).
 Write report to: song_ten_OUT.txt
 
 Read data from: test.txt
 7 three
 7 two
 There is / are 2 high frequency word(s).
 Write report to: test_OUT.txt
 
 You've reached the end of the program. Goodbye.
 Program ended with exit code: 0
 */



