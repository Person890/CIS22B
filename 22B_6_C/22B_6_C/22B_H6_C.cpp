/*
 CIS 22B: Homework 6C
 
 Build and procees a sorted linked list of City objects.
 The list is sorted in ascending order by the city name
 Assume that the city name is unique.
 
 Written by:    Natalie Stepankevycova
 IDE:           Xcode
 
 */
#include <iostream>
#include <fstream>
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
    list.displayList(); // call the first displayList() function

    searchManager(list);
    // show the number of elements in the list
    cout << endl;
    cout << "Number of elements in the list " << list.getCount() << endl;
    deleteManager(list);
    list.displayList();     // call the displayList() function again
    // show the number of elements in the list
    cout << endl;
    cout << "Number of elements in the list " << list.getCount() << endl;
    
    
    return 0;
}

/*****************************************************************************
 This function reads data about colleges from a given file and inserts them
 into a sorted linked list.
 *****************************************************************************/
void buildList(string filename, LinkedList &list)
{

    ifstream infile;            // creating file
    infile.open(filename);
    char _state[2] = {};
    string _city = "";
    int _year = 0;
    
    while (!infile.eof()){       // validating if file is open
        infile >> _state;
        infile >> _year;
        infile.ignore();        // ignore space between year and city
        getline(infile, _city);
    //function to place the current node in right place
        list.insertNode(_state, _city, _year);
    }
    infile.close();
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
            if (list.deleteNode(targetName))
                cout << "Node deleted" << endl;
            else
                cout << "Couldn't delete the node. " << endl;
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
            list.searchNode(targetName);
        }
        
        
    }
    cout << "___________________END SEARCH SECTION _____\n";
}

/*****************************************************************************
OUTPUT BELOW

====== ===================== =====
State  City                  Year
====== ===================== =====
MD   Baltimore             1797
MA   Boston                1822
IL   Chicago               1837
OH   Columbus              1834
TX   Dallas                1856
MI   Detroit               1815
TX   Huston                1837
IN   Indianapolis          1832
FL   Jacksonville          1822
CA   Los Angeles           1850
TN   Memphis               1826
WI   Milwaukee             1846
NY   New York              1898
PA   Philadelphia          1701
AZ   Phoenix               1881
TX   San Antonio           1837
CA   San Diego             1850
CA   San Francisco         1850
CA   San Jose              1850
====== ===================== =====

Search
=======

Enter a city name (or Q for stop searching) :
Dallas
Found:
TX Dallas 1856

Enter a city name (or Q for stop searching) :
San Francisco
Found:
CA San Francisco 1850

Enter a city name (or Q for stop searching) :
Montreal
City not found.

Enter a city name (or Q for stop searching) :
Q
___________________END SEARCH SECTION _____

Number of elements in the list 19

Delete
=======

Enter a city name (or Q for stop deleting) :
San Jose
Node deleted

Enter a city name (or Q for stop deleting) :
Baltimore
Node deleted

Enter a city name (or Q for stop deleting) :
Detroit
Node deleted

Enter a city name (or Q for stop deleting) :
Q
___________________END DELETE SECTION_____
====== ===================== =====
State  City                  Year
====== ===================== =====
MA   Boston                1822
IL   Chicago               1837
OH   Columbus              1834
TX   Dallas                1856
TX   Huston                1837
IN   Indianapolis          1832
FL   Jacksonville          1822
CA   Los Angeles           1850
TN   Memphis               1826
WI   Milwaukee             1846
NY   New York              1898
PA   Philadelphia          1701
AZ   Phoenix               1881
TX   San Antonio           1837
CA   San Diego             1850
CA   San Francisco         1850
====== ===================== =====

Number of elements in the list 16
Finished deleting.
Program ended with exit code: 0

 *****************************************************************************/
