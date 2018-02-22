//---------------------------------------------------------------------------
// Patron.h
// Class representing patron of library system
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// Resource class: Represents books of fiction
//   -- Allows for setting patron name
//   -- Allows for setting ID
//   -- Allows for viewing and storing interaction history
//
//  Implementation and assumptions:
//   -- Assumes middle name and birthday are not important
//---------------------------------------------------------------------------

#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Interact;
class Resource;

//---------------------------------------------------------------------------
// InteractNode
// Used here for storing interaction history in a linked list
// Pre: None
// Post: None
struct InteractNode{
   Interact *interact = NULL;
   InteractNode *next = NULL;
};

class Patron
{
public:

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: None
   Patron();

//---------------------------------------------------------------------------
// operator>>
// Uses command line to set Patron attributes
// Pre: is is formatted correctly. No null inputs
// Post: Patron attributes set
   friend istream& operator>>(istream& is, Patron& P);

//---------------------------------------------------------------------------
// getID
// Pre: None
// Post: ID of patron returned
   int getID();

//---------------------------------------------------------------------------
// getFirstName
// Pre: None
// Post: first name of patron returned
   string getFirstName();

//---------------------------------------------------------------------------
// getLastName
// Pre: None
// Post: last name of patron returned
   string getLastName();

//---------------------------------------------------------------------------
// addHistory
// Pre: None
// Post: Adds interact object used to interaction history list
   void addHistory(Interact& interact);

//---------------------------------------------------------------------------
// printHistory
// Pre: None
// Post: Prints all interactions, starting from more recent
   void printHistory();

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: Deallocates all interactions
   ~Patron();

private:
   int ID;
   string firstName;
   string lastName;
   int interactHistorySize = 0;
   InteractNode* interactHistoryHead = NULL;

//---------------------------------------------------------------------------
// deleteHistory
// Pre: Only used by deconstructor
// Post: Deallocates interact history recursively
   void deleteHistory(InteractNode* current);

};

