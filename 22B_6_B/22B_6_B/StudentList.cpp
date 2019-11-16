// Implementation file for the Student List class
// Modified by: Natalie Stepankevycova
// IDE:     Xcode

#include <iostream>         // For cout  and NULL
#include <iomanip>
#include "StudentList.h"
using namespace std;

//**************************************************
// Constructor
// This function allocates and initializes a sentinel node
//      A sentinel (or dummy) node is an extra node added before the first data record.
//      This convention simplifies and accelerates some list-manipulation algorithms,
//      by making sure that all links can be safely dereferenced and that every list
//      (even one that contains no data elements) always has a "first" node.
//**************************************************
StudentList::StudentList()
{
    head = new ListNode; // head points to the sentinel node
    head->next = NULL;
    count = 0;
}

//**************************************************
// displayList shows the value
// stored in each node of the linked list
// pointed to by head.
//**************************************************

void StudentList::displayList() const
{
    ListNode *pCur;  // To move through the list
    
    // Position pCur: skip the head of the list.
    pCur = head->next;
    
    // While pCur points to a node, traverse the list.
    while (pCur)
    {
        // Display the value in this node.
        cout << pCur->stu.getGpa() << " " << pCur->stu.getName() << endl;
        
        // Move to the next node.
        pCur = pCur->next;
    }
    cout << endl;
}
//**************************************************
// displayList shows the value passed to it
//**************************************************
void StudentList::displayList(double gpa) const {
    
    bool found = false;
    ListNode *pCur;
    pCur = head->next;
    while(pCur){
        if (pCur->stu.getGpa() == gpa){
            cout << pCur->stu.getGpa() << "\t" << pCur->stu.getName() << endl;
            found = true;
            pCur = pCur->next;
        }
        pCur = pCur->next;
        
    }
    if (found == false)
        cout << "Value " << setprecision(1) << fixed << gpa << " not found." << endl;
}

//**************************************************
// The insertNode function inserts a node with
// stu copied to its value member.
//**************************************************
void StudentList::insertNode(Student dataIn)
{
    ListNode *newNode;  // A new node
    ListNode *pCur;     // To traverse the list
    ListNode *pPre;     // The previous node
    
    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->stu = dataIn;
    
    // Initialize pointers
    pPre = head;
    pCur = head->next;
    
    // Find location: skip all nodes whose gpa is less than dataIn's gpa
    while (pCur != NULL && pCur->stu.getGpa()< dataIn.getGpa())
    {
        pPre = pCur;
        pCur = pCur->next;
    }
    
    // Insert the new node between pPre and pCur
    pPre->next = newNode;
    newNode->next = pCur;
    
    // Update the counter
    count++;
}

//**************************************************
// The deleteNode function searches for a node
// with num as its value. The node, if found, is
// deleted from the list and from memory.
//**************************************************
bool StudentList::deleteNode(double target)
{
    ListNode *pCur;       // To traverse the list
    ListNode *pPre;        // To point to the previous node
    bool deleted = false;
    
    // Initialize pointers
    pPre = head;
    pCur = head->next;
    
    // Find node containing the target: Skip all nodes whose gpa is less than the target
    while (pCur != NULL && pCur->stu.getGpa() < target)
    {
        pPre = pCur;
        pCur = pCur->next;
    }
    
    // If found, delte the node
    if (pCur != NULL && pCur->stu.getGpa() == target)
    {
        pPre->next = pCur->next;
        delete pCur;
        deleted = true;
        count--;
    }
    return deleted;
    
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************
StudentList::~StudentList()
{
    ListNode *pCur;   // To traverse the list
    ListNode *pNext;  // To point to the next node
    
    // Position nodePtr at the head of the list.
    pCur = head->next;
    
    // While pCur is not at the end of the list...
    while (pCur != NULL)
    {
        // Save a pointer to the next node.
        pNext = pCur->next;
        
        // Delete the current node.
        cout << "DEBUG - Destructor: Now deleting " << pCur->stu.getName() << endl;
        delete pCur;
        
        // Position pCur at the next node.
        pCur = pNext;
    }
    cout << "DEBUG - Destructor: Now deleting the sentinel node gpa = " << head->stu.getGpa() << endl;
    delete head; // delete the sentinel node
}

/**********************************************************************
 OUTPUT BELOW
 
TESTING INSERT

Insert 3.1 Paul
3.1 Paul

This list has 1 student[s]

Insert 2.5 John
2.5 John
3.1 Paul

This list has 2 student[s]

Insert 3.9 Linda
2.5 John
3.1 Paul
3.9 Linda

This list has 3 student[s]

Insert 3.6 Bob
2.5 John
3.1 Paul
3.6 Bob
3.9 Linda

This list has 4 student[s]

Insert 2.7 Ann
2.5 John
2.7 Ann
3.1 Paul
3.6 Bob
3.9 Linda

This list has 5 student[s]

Insert 4 Mary
2.5 John
2.7 Ann
3.1 Paul
3.6 Bob
3.9 Linda
4 Mary

This list has 6 student[s]

Insert 3.2 Andy
2.5 John
2.7 Ann
3.1 Paul
3.2 Andy
3.6 Bob
3.9 Linda
4 Mary

This list has 7 student[s]

Insert 2.3 Tom
2.3 Tom
2.5 John
2.7 Ann
3.1 Paul
3.2 Andy
3.6 Bob
3.9 Linda
4 Mary

This list has 8 student[s]

TESTING DISPLAY

2.3 Tom
2.5 John
2.7 Ann
3.1 Paul
3.2 Andy
3.6 Bob
3.9 Linda
4 Mary

Value 3.0 not found.
TESTING DELETE

Delete the first node
2.5 John
2.7 Ann
3.1 Paul
3.2 Andy
3.6 Bob
3.9 Linda
4.0 Mary

Delete the last node
2.5 John
2.7 Ann
3.1 Paul
3.2 Andy
3.6 Bob
3.9 Linda

Delete 3.1
Deleted
2.5 John
2.7 Ann
3.2 Andy
3.6 Bob
3.9 Linda

Try to delete 3.0
Target (3.0) not found
2.5 John
2.7 Ann
3.2 Andy
3.6 Bob
3.9 Linda

This list has 5 student[s]

DEBUG - Destructor: Now deleting John
DEBUG - Destructor: Now deleting Ann
DEBUG - Destructor: Now deleting Andy
DEBUG - Destructor: Now deleting Bob
DEBUG - Destructor: Now deleting Linda
DEBUG - Destructor: Now deleting the sentinel node gpa = -1.0
Program ended with exit code: 0

**********************************************************************/
