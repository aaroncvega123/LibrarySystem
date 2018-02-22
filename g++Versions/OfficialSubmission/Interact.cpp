//---------------------------------------------------------------------------
// Interact.cpp
// Class representing an action involving the library system
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// Interact class: Allows for creating different kinds of interactions
//   -- Allows child classes to inherit basic functions
//
// Assumptions:
//   -- Assumes only child classes will be used
//   -- Assumes interaction will always have a patron list and resource list
//---------------------------------------------------------------------------

//#include "stdafx.h"
#include "Interact.h"
#include "PatronList.h"
#include "ResourceList.h"

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: None

Interact::Interact()
{
}

//---------------------------------------------------------------------------
// usePatronList
// Pre: pList is not null
// Post: This interact will point to a patron list

void Interact::usePatronList(PatronList* pList) {
   pListPtr = pList;
}

//---------------------------------------------------------------------------
// useResourceList
// Pre: rList is not null
// Post: This interact will point to a resource list

void Interact::useResourceList(ResourceList* rList) {
   rListPtr = rList;
}

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None

Interact::~Interact()
{
}
