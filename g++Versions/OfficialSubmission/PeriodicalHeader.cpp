//---------------------------------------------------------------------------
// PeriodicalHeader.cpp
// Class representing a header in the ResourceList Periodical section
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// FictionHeader class: For displaying attribute names of periodicals
//   -- Allows printing of attribute names
//
//  Assumptions:
//   -- Only to be in resourceList
//
//---------------------------------------------------------------------------

//#include "stdafx.h"
#include "PeriodicalHeader.h"

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: None

PeriodicalHeader::PeriodicalHeader()
{
}

//---------------------------------------------------------------------------
// printInfo
// Pre: None
// Post: Will print out periodical attributes

void PeriodicalHeader::printInfo() {
   cout.setf(ios::left);
   cout << "PERIDOCAL:" << endl;
   cout.width(7);
   cout << "AVAIL";
   cout.width(7);
   cout << "YEAR";
   cout.width(7);
   cout << "MO";
   cout << "TITLE " << endl;
}

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None

PeriodicalHeader::~PeriodicalHeader()
{
}
