//---------------------------------------------------------------------------
// History.h
// Class representing a an action to show patron history
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// History class: Allows for displaying all patron's interactions with
//                library
//   -- Allows user to choose patron and see their checkout/return history
//
// Implementation and assumptions:
//   -- Assumes no date is accounted for
//   -- Assumes no due date is accounted for
//---------------------------------------------------------------------------

#pragma once
#include "Interact.h"
class History :
   public Interact
{
public:

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: InteractName is set to "History"
   History();

//---------------------------------------------------------------------------
// create
// Pre: None
// Post: Returns a new History object
   virtual Interact* create() const { return new History; };

//---------------------------------------------------------------------------
// getInput
// Pre: Input not null
// Post: Will show entire usage history of patron starting from most recent
   istream& getInput(istream& is);

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None
   ~History();
};

