// Implementation file for the LinkedList class
// Written By:  Natalie Stepankevycova
// IDE:         Xcode

#include <iostream>         // For cout  and NULL
#include <iomanip>
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

//**************************************************
// This function extends the reading function by searching for appropriate
// place where to put current node by comparing it to value in node
// and value in next node
// IN - state c-string, string city, int year
// OUT - doesn't return anything
//**************************************************
void LinkedList::insertNode(char state [], std::string city, int year)
{
    ListNode * node = new ListNode; // head points to the sentinel node
    
    node->city.state[0] = state[0];
    node->city.state[1] = state[1];
    node->city.city = city;
    node->city.year = year;
    node->next = NULL;
    count++;
    
    if (count == 1) {       // if first node, keep it blank
        head->next = node;
        return;
    }
    
    ListNode *current = head;       // point to the first node
    while (true) {
        if (current->next == NULL) {    // if comparing to last node, append
            current->next = node;
            break;
            // if current is smaller but one after current is bigger
        } else if (node->city.city < current->next->city.city) {
            ListNode *temp = current->next;
            current->next = node;
            node->next = temp;
            break;
        } else {        // move to the next node
            current = current->next;
        }
    }
}
//**************************************************
// This function displays whole list
// OUT - doesn't return anything
//**************************************************
void LinkedList::displayList() const {
    
    std::string grid = "====== ===================== =====";
    ListNode * current = head->next;
    
    cout << grid << endl;
    cout << setw(5)<< left << "State " << setw(18)<< left << " City "
    << setw(5)<< left << " " << "Year "<< endl;
    cout << grid << endl;
    
    while (current->next != NULL){
        cout << setw(4)<< right << current->city.state
             << "   " << setw(17)<< left
             << current->city.city
             << setw(5)<< left
             << " " << current->city.year<< endl;
        current = current->next;
    }
    cout << grid << endl;
}
//**************************************************
// This function deletes a node from the linked list based on user's input
// IN - targetName (input)
// out - bool true if node successfully deleted
//**************************************************
bool LinkedList::deleteNode(std::string targetName){
    
    ListNode *pCur;       // To traverse the list
    ListNode *pPre;        // To point to the previous node
    bool deleted = false;     // flag
    
    // Initialize pointers
    pPre = head;
    pCur = head->next;
    
    // Find node containing the target
    while (pCur != NULL && pCur->city.city < targetName)
    {
        pPre = pCur;
        pCur = pCur->next;
    }
    
    // If found, delte the node
    if (pCur != NULL && pCur->city.city == targetName)
    {
        pPre->next = pCur->next;
        delete pCur;
        deleted = true;
        count--;        // deduct one from counter
    }
    return deleted;
}
//**************************************************
// This function searches for a city in linked list based on user's input
// IN - targetName (input)
// OUT - doesn't return anything
//**************************************************
void LinkedList::searchNode(std::string targetName) const{
    ListNode *pCur;  // To move through the list
    
    // Position pCur: skip the head of the list.
    pCur = head->next;
    bool found = false;
    // While pCur points to a node, traverse the list.
    while (pCur != NULL)
    {
        if (pCur->city.city == targetName){
            // Display the value in this node.
            cout << "Found:" << endl;
            cout << pCur->city.state << " " << pCur->city.city
                 << " " << pCur->city.year << endl;
            
            found = true;
            break;
        }
        // Move to the next node.
        pCur = pCur->next;
    }
    if (found == false)
        cout << "City not found." << endl;
}
//**************************************************
// Destructor
//  This function destructs all the nodes and releases the memory, in the end
//  it destructs the head
//**************************************************
LinkedList::~LinkedList()
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
        delete pCur;
        
        // Position pCur at the next node.
        pCur = pNext;
    }
    delete head; // delete the sentinel node
    cout << "Finished deleting. " << endl;
}
