//---------------------------------------------------------------------------
// Return.cpp
// Class representing a patron returning a resource.
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// Return class: For patrons returning library resources
//   -- Allows user to output a new Return object
//   -- Runs based on input
//
// Assumptions:
//   -- Assumes user input is correct format
//   -- Assumes genre is not always correct
//---------------------------------------------------------------------------

//#include "stdafx.h"
#include "Return.h"
#include "Resource.h"
#include "PatronList.h"
#include "ResourceList.h"
#include "ResourceFactory.h"

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: InteractName is set to "Return"

Return::Return()
{
   interactName = "Returned";
}

//---------------------------------------------------------------------------
// getInput
// Pre: Input must be formatted correctly
// Post: If successful, designated resource will have pointer to patron
//       removed, if ID of patron matches person who checked it out

istream& Return::getInput(istream& is) {
   ResourceFactory rFactory;

   int patronID;
   is >> patronID;

   char resourceGenre;
   is >> resourceGenre;

   if (!rFactory.isApprovedResource(resourceGenre)) {
      string dummy;
      getline(is, dummy);
      return is;
   }

   // Gets resource and patron if both are available.
   // If resource belongs to patron, will remove pointer
   // to that patron
   Resource *searchItem = rFactory.produce(resourceGenre);
   searchItem->setSearchData(is);
   Resource *resourcePtr = rListPtr->getResource(searchItem);
   Patron *patronPtr = pListPtr->getPatronPointer(patronID);

   if (resourcePtr != NULL) {
      if (resourcePtr->clearBorrower(patronID)) {
         patronPtr->addHistory(*this);
         associatedResource = resourcePtr;
      }

   }
   return is;
}

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None

Return::~Return()
{
}
