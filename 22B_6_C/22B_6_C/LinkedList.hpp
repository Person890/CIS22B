// Specification file for the LinkedList class
// Written By:
// IDE:

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "City.hpp"


class LinkedList
{
private:
    // Declare a structure for the list
    struct ListNode
    {
        City city;     // The value in this node
        ListNode *next;  // To point to the next node
    };
    
    ListNode *head;      // List head pointer
    int count;           // To keep track of the number of nodes in the list
    
    
public:
    LinkedList();  // Constructor
    ~LinkedList();   // Destructor
    
    //getter
    int getCount(){return count - 1;}   // return count - 1 because of sentinel node
    // Linked list operations
    void displayList() const;
    bool deleteNode(std::string);
    void searchNode(std::string) const;
    void insertNode(char[], std::string, int);      // aka insertion sort
    
};


#endif
