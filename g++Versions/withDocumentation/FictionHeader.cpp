//---------------------------------------------------------------------------
// FictionHeader.cpp
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

//#include "stdafx.h"
#include "FictionHeader.h"

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: None

FictionHeader::FictionHeader()
{
}

//---------------------------------------------------------------------------
// printInfo
// Pre: None
// Post: Will print out Fiction attributes

void FictionHeader::printInfo() {
   cout << "Fiction:" << endl;
   cout.setf(ios::left);
   cout.width(7);
   cout << "AVAIL";
   cout.width(20);
   cout << "AUTHOR";
   cout.width(35);
   cout << "TITLE";
   cout.width(15);
   cout << "YEAR" << endl;
}

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None

FictionHeader::~FictionHeader()
{
}
