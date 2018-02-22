//---------------------------------------------------------------------------
// FictionHeader.h
// Class representing a header in the ResourceList fiction section
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// FictionHeader class: For displaying attribute names of Fiction books
//   -- Allows printing of attribute names
//
//  Assumptions:
//   -- Only to be in resourceList
//
//---------------------------------------------------------------------------

#pragma once
#include "Fiction.h"

using namespace std;

class FictionHeader :
   public Fiction
{
public:

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: None
   FictionHeader();

//---------------------------------------------------------------------------
// printInfo
// Pre: None
// Post: Will print out Fiction attributes
   void printInfo();

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None
   ~FictionHeader();
};

