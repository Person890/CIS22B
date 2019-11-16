/*
 CIS 22B: Homework 6C
 
 Build and procees a sorted linked list of City objects.
 The list is sorted in ascending order by the city name
 Assume that the city name is unique.
 
 Written by:
 IDE: 
 
 */
#include <iostream>
#include "LinkedList.hpp"
using namespace std;

void buildList(string filename, LinkedList &list);
void deleteManager(LinkedList &list);
void searchManager(LinkedList &list);

int main()
{
    const char inputFileName[] = "cities.txt";
    LinkedList list;

    buildList(inputFileName, list);
    // call the first displayList() function
    // call the seconf displayLIst() function
    searchManager(list);
    // show the number of elements in the list
    deleteManager(list);
    // call the third displayList() function
    // show the number of elements in the list
    
    return 0;
}

/*****************************************************************************
 This function reads data about colleges from a given file and inserts them
 into a sorted linked list.
 *****************************************************************************/
void buildList(string filename, LinkedList &list)
{
    
}

/*****************************************************************************
 Delete manager: delete items from the list until the user enters Q to quit
 deleting
 Input Parameter: list
 *****************************************************************************/
void deleteManager(LinkedList &list)
{
    string targetName = "";
    
    cout << "\n Delete\n";
    cout << "=======\n";
    
    while(targetName != "Q")
    {
        cout << endl << "Enter a city name (or Q for stop deleting) : \n";
        getline(cin, targetName);
        
        if(targetName != "Q")
        {
            // call delete
            // . . .
        }
    }
    cout << "___________________END DELETE SECTION_____\n";
}

/*****************************************************************************
 Search manager: search the list until the user enters Q to quit searching
 Input Parameter: list
 *****************************************************************************/
void searchManager(LinkedList &list)
{
    string targetName = "";
    
    cout << "\n Search\n";
    cout <<   "=======\n";
    
    while(targetName != "Q")
    {
        cout << "\nEnter a city name (or Q for stop searching) : \n";
        getline(cin, targetName);
        
        if(targetName != "Q")
        {
            // call search
            // . . .
         }
        
        
    }
    cout << "___________________END SEARCH SECTION _____\n";
}



