//---------------------------------------------------------------------------
// PatronList.h
// Class representing a collection of all patrons
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// PatronList class: For storing all library patrons
//   -- Allows for storing of patrons
//   -- Allows for getting pointers of patrons
//
// Assumptions:
//   -- Assumes not patrons are removed
//   -- Assumes not more than 10,000 patrons
//---------------------------------------------------------------------------

//#include "stdafx.h"
#include "PatronList.h"

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: None
PatronList::PatronList()
{
}

//---------------------------------------------------------------------------
// addPatron
// Pre: None
// Post: Single patron is added to list
void PatronList::addPatron(Patron& P) {
   patronArray[P.getID()] = P;
}

//---------------------------------------------------------------------------
// populateList
// Pre: File should be formatted correctly
// Post: All patrons will be added to list
void PatronList::populateList(istream& is) {
   while (!is.eof()) {
      Patron patron;
      is >> patron;
      addPatron(patron);
   }
}

//---------------------------------------------------------------------------
// printList
// Pre: None
// Post: All prints and their ID will be printed
void PatronList::printList() {
   for (int i = 0; i < 10000; i++) {
      if (patronArray[i].getID() > 0) {
         cout << patronArray[i].getID() <<
            " " << patronArray[i].getFirstName() <<
            " " << patronArray[i].getLastName() << endl;
      }
   }
}

//---------------------------------------------------------------------------
// getPatronPointer
// Pre: ID >= 0
// Post: pointer to patron returned if found
Patron* PatronList::getPatronPointer(int id) {
   Patron* pPtr;
   pPtr = &patronArray[id];
   if(patronArray[id].getFirstName() == ""){
      cout << id << " is not a valid ID" << endl;
      cout << endl;
   }
   return pPtr;
}

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None
PatronList::~PatronList()
{
}
