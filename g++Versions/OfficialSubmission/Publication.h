//---------------------------------------------------------------------------
// Publication.cpp
// Class representing paper based media
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// Publication class: Represents paper based media
//   -- Allows for storing of item title, year, format, and genre
//
//  Implementation and assumptions:
//   -- Assumes only child classes will be used
//---------------------------------------------------------------------------

#include "Resource.h"
#include <string>
#pragma once

using namespace std;

class Publication : public Resource
{
public:
//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: None
   Publication();

//---------------------------------------------------------------------------
// hash
// Meant to take all attributes and return and number based on that
// Pre: None
// Post: None
   virtual int hash() { return 0; };

//---------------------------------------------------------------------------
// setTitle
// Pre: No null inputs
// Post: title is changed to input
   void setTitle(string newTitle) { title = newTitle; };

//---------------------------------------------------------------------------
// setYear
// Pre: No null inputs
// Post: year is changed to input
   void setYear(int newYear) { year = newYear; };

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None
   ~Publication();

protected:
   string title;
   int year;
   char format = 'H';
   char genre = ' ';
private:

};

