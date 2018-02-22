//---------------------------------------------------------------------------
// PeriodicalHeader.h
// Class representing a header in the ResourceList Periodical section
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// FictionHeader class: For displaying attribute names of periodicals
//   -- Allows printing of attribute names
//
//  Implementation and assumptions:
//   -- Only to be in resourceList
//
//---------------------------------------------------------------------------

#pragma once
#include "Periodical.h"
class PeriodicalHeader :
   public Periodical
{
public:

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: None
   PeriodicalHeader();

//---------------------------------------------------------------------------
// printInfo
// Pre: None
// Post: Will print out periodical attributes
   void printInfo();

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None
   ~PeriodicalHeader();
};

