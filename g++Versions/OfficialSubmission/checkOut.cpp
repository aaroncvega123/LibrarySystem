//---------------------------------------------------------------------------
// checkOut.cpp
// Class representing a patron checking out a resource.
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// checkOut class: For patrons checking out library resources
//   -- Allows user to output a new checkOut object
//   -- Runs based on input
//
//  Assumptions:
//   -- Assumes user input is correct format
//   -- Assumes genre is not always correct
//---------------------------------------------------------------------------

//#include "stdafx.h"
#include "checkOut.h"
#include "Resource.h"
#include "PatronList.h"
#include "ResourceList.h"
#include "ResourceFactory.h"

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: InteractName is set to "Checked Out"

checkOut::checkOut()
{
   interactName = "Checked Out";
}

//---------------------------------------------------------------------------
// getInput
// Takes input to determine which patron checks out which resource
// Pre: Input must be formatted correctly
// Post: If successful, designated resource will have pointer of patron that
//       checked it out

istream& checkOut::getInput(istream& is) {
   ResourceFactory rFactory;
   
   int patronID;
   is >> patronID;

   char resourceGenre;
   is >> resourceGenre;

   if (!rFactory.isApprovedResource(resourceGenre)) {
      cout << resourceGenre << " is not a valid genre" << endl;
      cout << endl;
      string dummy;
      getline(is, dummy);
      return is;
   }

   // searchItem is a temporary resource object that holds similar
   // attributes to desired resource. Uses == to find desired resource.
   Resource *searchItem = rFactory.produce(resourceGenre);
   searchItem->setSearchData(is);
   Resource *resourcePtr = rListPtr->getAvailableResource(searchItem);
   Patron *patronPtr = pListPtr->getPatronPointer(patronID);

   if (resourcePtr != NULL) {
      resourcePtr->setBorrower(patronPtr);

      patronPtr->addHistory(*this);

      associatedResource = resourcePtr;
   }


   return is;
}

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None

checkOut::~checkOut()
{
}
