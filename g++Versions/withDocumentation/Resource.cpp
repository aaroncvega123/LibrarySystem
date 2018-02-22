//---------------------------------------------------------------------------
// Resource.cpp
// Class representing borrowable item of library
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// Resource class: Represents books of fiction
//   -- Allows for storing genre and borrower
//
//  Assumptions:
//   -- Assumes only child classes will be used
//---------------------------------------------------------------------------

//#include "stdafx.h"
#include "Resource.h"

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: None
Resource::Resource()
{
}

//---------------------------------------------------------------------------
// setBorrower
// Pre: No null inputs
// Post: sets patron pointer to borrower
void Resource::setBorrower(Patron* newBorrower) {
   if (isAvailable()) {
      borrower = newBorrower;
   }
}

//---------------------------------------------------------------------------
// clearBorrower
// Pre: None
// Post: if id matches patron pointer's id, the pointer will be set to null
bool Resource::clearBorrower(int id) {
   if (borrower->getID() == id) {
      borrower = NULL;
      return true;
   }
   return false;
}

//---------------------------------------------------------------------------
// getBorrowerID
// Pre: None
// Post: will return ID of person borrower resource
int Resource::getBorrowerID() {
   return borrower->getID();
}

//---------------------------------------------------------------------------
// isAvailable
// Pre: None
// Post: If patron pointer is null, will return true
bool Resource::isAvailable() {
   if (borrower == NULL) {
      return true;
   }
   return false;
}

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None
Resource::~Resource()
{
}
