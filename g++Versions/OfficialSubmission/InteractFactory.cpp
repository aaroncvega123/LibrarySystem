//---------------------------------------------------------------------------
// InteractFactory.cpp
// Class which allows production of Interact's child classes
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// Resource class:
//   -- Allows creation of Interact's subclasses
//
//  Implementation and assumptions:
//  
//---------------------------------------------------------------------------

//#include "stdafx.h"
#include "InteractFactory.h"

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: Blank objects of type interact are placed in blankInteracts
InteractFactory::InteractFactory()
{
   blankInteracts[2] = new checkOut();
   blankInteracts[3] = new Display();
   blankInteracts[7] = new History();
   blankInteracts[17] = new Return();
}

//---------------------------------------------------------------------------
// produce
// Pre: None
// Post: Blank object of type interact is returned
Interact* InteractFactory::produce(char choice) const {
   return blankInteracts[choice - 'A']->create();
}

//---------------------------------------------------------------------------
// isApprovedInput
// Pre: None
// Post: Determines of char used is appropriate
bool InteractFactory::isApprovedInput(char choice) {
   for (int i = 0; i < 26; i++) {
      if (approvedInputs[i] == choice) {
         return true;
      }
   }
   return false;
}

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None
InteractFactory::~InteractFactory()
{
}
