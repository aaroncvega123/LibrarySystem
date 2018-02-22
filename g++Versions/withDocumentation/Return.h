//---------------------------------------------------------------------------
// Return.h
// Class representing a patron returning a resource.
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// Return class: For patrons returning library resources
//   -- Allows user to output a new Return object
//   -- Runs based on input
//
// Implementation and assumptions:
//   -- Assumes user input is correct format
//   -- Assumes genre is not always correct
//---------------------------------------------------------------------------

#pragma once
#include "Interact.h"
class Return :
   public Interact
{
public:

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: InteractName is set to "Return"
   Return();

//---------------------------------------------------------------------------
// create
// Pre: None
// Post: Returns a new Return object
   virtual Interact* create() const { return new Return; };
   
//---------------------------------------------------------------------------
// getInput
// Pre: Input must be formatted correctly
// Post: If successful, designated resource will have pointer to patron
//       removed, if ID of patron matches person who checked it out
   istream& getInput(istream& is);
   
//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None
   ~Return();
};

