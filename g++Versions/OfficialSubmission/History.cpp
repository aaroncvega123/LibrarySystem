//---------------------------------------------------------------------------
// History.cpp
// Class representing a an action to show patron history
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// History class: Allows for displaying all patron's interactions with
//                library
//   -- Allows user to choose patron and see their checkout/return history
//
// Assumptions:
//   -- Assumes no date is accounted for
//   -- Assumes no due date is accounted for
//---------------------------------------------------------------------------

//#include "stdafx.h"
#include "History.h"
#include "Resource.h"
#include "PatronList.h"
#include "ResourceList.h"
#include "ResourceFactory.h"

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: InteractName is set to "History"

History::History()
{
}

//---------------------------------------------------------------------------
// getInput
// Pre: Input not null
// Post: Will show entire usage history of patron starting from most recent

istream& History::getInput(istream& is) {
   ResourceFactory rFactory;

   int patronID;
   is >> patronID;

   Patron* patronPtr = pListPtr->getPatronPointer(patronID);
   patronPtr->printHistory();

   return is;
}

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None

History::~History()
{
}
