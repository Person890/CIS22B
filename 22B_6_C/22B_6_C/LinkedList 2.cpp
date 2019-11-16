// Implementation file for the LinkedList class
// Written By:
// IDE:

#include <iostream>         // For cout  and NULL
#include "LinkedList.hpp"
using namespace std;


//**************************************************
// Constructor
// This function allocates and initializes a sentinel node
//      A sentinel (or dummy) node is an extra node added before the first data record.
//      This convention simplifies and accelerates some list-manipulation algorithms,
//      by making sure that all links can be safely dereferenced and that every list
//      (even one that contains no data elements) always has a "first" node.
//**************************************************
LinkedList::LinkedList()
{
    head = new ListNode; // head points to the sentinel node
    
    head->city.state[0] = {};
    head->city.state[1] = {};
    head->city.city = "";
    head->city.year = -1;
    head->next = NULL;
    count = 0;
}


void LinkedList::insertNode(char [], std::string, int)
{
    
}
