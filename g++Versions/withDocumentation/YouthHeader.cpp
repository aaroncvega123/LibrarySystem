//---------------------------------------------------------------------------
// YouthHeader.cpp
// Class representing a header in the ResourceList Youth section
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// FictionHeader class: For displaying attribute names of youth books
//   -- Allows printing of attribute names
//
//  Assumptions:
//   -- Only to be in resourceList
//
//---------------------------------------------------------------------------
//#include "stdafx.h"
#include "YouthHeader.h"

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: None

YouthHeader::YouthHeader()
{
}

//---------------------------------------------------------------------------
// printInfo
// Pre: None
// Post: Will print out youth attributes

void YouthHeader::printInfo() {
   cout << "YOUTH:" << endl;
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

YouthHeader::~YouthHeader()
{
}
