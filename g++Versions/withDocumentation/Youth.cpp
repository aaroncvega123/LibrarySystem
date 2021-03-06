//---------------------------------------------------------------------------
// Youth.cpp
// Class representing book of Youth
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// Youth class: Represents books of Youth
//   -- Allows for storing book information
//   -- Allows to be used for searching ResourceList
//   -- Allows to create hash code for object
//
//  Assumptions:
//   -- Assumes input is correct format
//---------------------------------------------------------------------------

//#include "stdafx.h"
#include "Youth.h"

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: Sets genre to 'Y'.
Youth::Youth()
{
   genre = 'Y';
}

//---------------------------------------------------------------------------
// hash
// Outputs number based on attributes
// Pre: None
// Post: Returns integer

int Youth::hash() const{
   int hash = 0;
   hash += format;
   string bookInfo = authorFirstName + authorLastName + title;
   for (unsigned int i = 0; i < bookInfo.length(); i++) {
      hash += bookInfo[i];
   }
   return hash;
}

//---------------------------------------------------------------------------
// operator==
// For comparing two Youth objects
// Pre: input must be of type Youth
// Post: True, if all attributes (except year) are the same

bool Youth::operator==(const Resource& other) const {
   const Youth& y = (const Youth&)other;
   if (format == y.format && title == y.title 
      && authorFirstName == y.authorFirstName
      && authorLastName == y.authorLastName) {
      return true;
   }
   return false;
}

//---------------------------------------------------------------------------
// setSearchData
// For when need a dummy Youth object for searching the ResourceList
// Pre: None
// Post: Sets author's last name, first name, title, and format

istream& Youth::setSearchData(istream& is) {
   is >> format;
   while (true) {
      string tempTitle;
      is >> tempTitle;
      title += tempTitle;
      if (title.back() == ',') {
         break;
      }
      title += " ";
   }
   is >> authorLastName;
   while (true) {
      string firstName;
      is >> firstName;
      authorFirstName += firstName;
      if (authorFirstName.back() == ',') {
         break;
      }
      authorFirstName += " ";
   }

   return is;
}

//---------------------------------------------------------------------------
// printInfo
// Pre: None
// Post: prints author's name, title, and year

void Youth::printInfo() {
   cout.setf(ios::left);
   cout.width(20);
   string name = authorLastName + " " + authorFirstName;
   if (name.length() > 15) {
      cout << name.substr(0, 15) + "...";
   }
   else {
      cout << name;
   }
   cout.width(35);
   if (title.length() > 30) {
      cout << title.substr(0, 30) + "...";
   }
   else {
      cout << title;
   }
   cout.width(15);
   cout << year << endl;
}

//---------------------------------------------------------------------------
// getInput
// Pre: Input formatted corrected
// Post: sets attributes for this object

istream& Youth::getInput(istream& is) {
   is >> authorLastName;

   while (true) {
      string firstName;
      is >> firstName;
      authorFirstName += firstName;
      if (authorFirstName.back() == ',') {
         break;
      }
      authorFirstName += " ";
   }

   while (true) {
      string tempTitle;
      is >> tempTitle;
      title += tempTitle;
      if (title.back() == ',') {
         break;
      }
      title += " ";
   }
   is >> year;
   return is;
}

//---------------------------------------------------------------------------
// Deconsructor
// Pre: None
// Post: None

Youth::~Youth()
{
}

/*
istream& operator>>(istream& is, Youth& Y) {
   is >> Y.authorLastName;

   while (true) {
      string firstName;
      is >> firstName;
      Y.authorFirstName += firstName;
      if (Y.authorFirstName.back() == ',') {
         break;
      }
      Y.authorFirstName += " ";
   }

   while (true) {
      string tempTitle;
      is >> tempTitle;
      Y.title += tempTitle;
      if (Y.title.back() == ',') {
         break;
      }
      Y.title += " ";
   }
   is >> Y.year;
   return is;
}*/

/*
void Youth::print() {
   cout << authorLastName << " " << authorFirstName <<
      " " << title << " " << year;
}*/
