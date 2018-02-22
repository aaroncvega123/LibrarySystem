//---------------------------------------------------------------------------
// Periodical.cpp
// Class representing a periodical
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// Periodical class: Represents books of periodical
//   -- Allows for storing book information
//   -- Allows to be used for searching ResourceList
//   -- Allows to create hash code for object
//
//  Assumptions:
//   -- Assumes input is correct format
//---------------------------------------------------------------------------
//#include "stdafx.h"
#include "Periodical.h"

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: Sets genre to 'P'.
Periodical::Periodical()
{
   genre = 'P';
}

//---------------------------------------------------------------------------
// hash
// Outputs number based on attributes
// Pre: None
// Post: Returns integer
int Periodical::hash() const{
   int hash = 0;
   hash += format;
   hash += year;
   hash += month;
   for (unsigned int i = 0; i < title.length(); i++) {
      hash += title[i];
   }
   return hash;
}

//---------------------------------------------------------------------------
// operator==
// For comparing two Periodical objects
// Pre: input must be of type Periodical
// Post: True, if all attributes (except year) are the same

bool Periodical::operator==(const Resource& other) const {
   const Periodical& p = (const Periodical&)other;
   if (month == p.month && year == p.year && title == p.title) {
      return true;
   }
   return false;
}

//---------------------------------------------------------------------------
// setSearchData
// For when need a dummy Periodical object for searching the ResourceList
// Pre: None
// Post: Sets month, year, and title

istream& Periodical::setSearchData(istream& is) {
   is >> format;
   is >> year;
   is >> month;
   while (true) {
      string tempTitle;
      is >> tempTitle;
      title += tempTitle;
      if (title.back() == ',') {
         break;
      }
      title += " ";
   }
   return is;
}

//---------------------------------------------------------------------------
// printInfo
// Pre: None
// Post: prints year, month, and title

void Periodical::printInfo() {
   cout.setf(ios::left);
   cout.width(7);
   cout << year;
   cout.width(7);
   cout << month;
   cout << title << endl;
}

//---------------------------------------------------------------------------
// getInput
// Pre: Input formatted corrected
// Post: sets attributes for this object

istream& Periodical::getInput(istream& is) {
   while (true) {
      string tempTitle;
      is >> tempTitle;
      title += tempTitle;
      if (title.back() == ',') {
         break;
      }
      title += " ";
   }
   is >> month;
   is >> year;
   return is;
}

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None

Periodical::~Periodical()
{
}

/*
istream& operator>>(istream& is, Periodical& P) {
   while (true) {
      string tempTitle;
      is >> tempTitle;
      P.title += tempTitle;
      if (P.title.back() = ',') {
         break;
      }
      P.title += " ";
   }
   is >> P.month;
   is >> P.year;
   return is;
}*/