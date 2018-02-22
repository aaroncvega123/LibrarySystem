//---------------------------------------------------------------------------
// checkOut.h
// Class representing a patron checking out a resource.
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// checkOut class: For patrons checking out library resources
//   -- Allows user to output a new checkOut object
//   -- Runs based on input
//
// Implementation and assumptions:
//   -- Assumes user input is correct format
//   -- Assumes genre is not always correct
//---------------------------------------------------------------------------
#pragma once
#include "Interact.h"

class checkOut :
   public Interact
{
public:

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: InteractName is set to "Checked Out."
   checkOut();

//---------------------------------------------------------------------------
// create
// Pre: None
// Post: Returns a new checkOut object
   virtual Interact* create() const { return new checkOut; };

//---------------------------------------------------------------------------
// getInput
// Pre: Input must be formatted correctly
// Post: If successful, designated resource will have pointer of patron that
//       checked it out
   istream& getInput(istream& is);

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None
   ~checkOut();
};

