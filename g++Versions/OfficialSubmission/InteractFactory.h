//---------------------------------------------------------------------------
// InteractFactory.h
// Class which allows production of Interact's child classes
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// Resource class:
//   -- Allows creation of Interact's subclasses
//
//  Implementation and assumptions:
//  
//---------------------------------------------------------------------------

#pragma once
#include "Interact.h"
#include "Display.h"
#include "checkOut.h"
#include "History.h"
#include "Return.h"

using namespace std;

class InteractFactory
{
public:
//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: Blank objects of type interact are placed in blankInteracts
   InteractFactory();

//---------------------------------------------------------------------------
// produce
// Pre: None
// Post: Blank object of type interact is returned
   Interact* produce(char choice) const;

//---------------------------------------------------------------------------
// isApprovedInput
// Pre: None
// Post: Determines of char used is appropriate
   bool isApprovedInput(char choice);

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None
   ~InteractFactory();
private:
   char approvedInputs[26] = { 'C', 'R', 'D', 'H'};
   Interact* blankInteracts[26];
};

