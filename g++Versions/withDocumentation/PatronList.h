//---------------------------------------------------------------------------
// PatronList.h
// Class representing a collection of all patrons
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// PatronList class: For storing all library patrons
//   -- Allows for storing of patrons
//   -- Allows for getting pointers of patrons
//
// Implementation and assumptions:
//   -- Assumes not patrons are removed
//   -- Assumes not more than 10,000 patrons
//---------------------------------------------------------------------------

#pragma once
#include "Patron.h"
#include <iostream>
using namespace std;

class PatronList
{
public:

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: None
   PatronList();

//---------------------------------------------------------------------------
// addPatron
// Pre: None
// Post: Single patron is added to list
   void addPatron(Patron& p);

//---------------------------------------------------------------------------
// populateList
// Pre: File should be formatted correctly
// Post: All patrons will be added to list
   void populateList(istream& is);

//---------------------------------------------------------------------------
// printList
// Pre: None
// Post: All prints and their ID will be printed
   void printList();

//---------------------------------------------------------------------------
// getPatronPointer
// Pre: ID >= 0
// Post: pointer to patron returned if found
   Patron* getPatronPointer(int ID);

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None
   ~PatronList();

private:
   Patron patronArray[10000];
};

