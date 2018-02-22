//---------------------------------------------------------------------------
// YouthHeader.h
// Class representing a header in the ResourceList Youth section
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// FictionHeader class: For displaying attribute names of youth books
//   -- Allows printing of attribute names
//
//  Implementation and ssumptions:
//   -- Only to be in resourceList
//
//---------------------------------------------------------------------------
#pragma once
#include "Youth.h"
class YouthHeader :
   public Youth
{
public:

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: None
   YouthHeader();

//---------------------------------------------------------------------------
// printInfo
// Pre: None
// Post: Will print out youth attributes
   void printInfo();

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None
   ~YouthHeader();
};

