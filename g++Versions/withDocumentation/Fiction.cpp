//---------------------------------------------------------------------------
// Fiction.cpp
// Class representing book of fiction
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// Fiction class: Represents books of fiction
//   -- Allows for storing book information
//   -- Allows to be used for searching ResourceList
//   -- Allows to create hash code for object
//
//  Assumptions:
//   -- Assumes input is correct format
//---------------------------------------------------------------------------

//#include "stdafx.h"
#include "Fiction.h"

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: Sets genre to 'F'.

Fiction::Fiction()
{
   genre = 'F';
}

//---------------------------------------------------------------------------
// hash
// Outputs number based on attributes
// Pre: None
// Post: Returns integer

int Fiction::hash() const{
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
// For comparing two Fiction objects
// Pre: input must be of type fiction
// Post: True, if all attributes (except year) are the same

bool Fiction::operator==(const Resource& other) const{
   const Fiction& f = (const Fiction&)other;
   if (title == f.title && authorFirstName == f.authorFirstName
      && authorLastName == f.authorLastName && format == f.format) {
      return true;
   }
   return false;
}

//---------------------------------------------------------------------------
// setSearchData
// For when need a dummy Fiction object for searching the ResourceList
// Pre: None
// Post: Sets author's last name, first name, title, and format

istream& Fiction::setSearchData(istream& is) {
   is >> format;
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
   return is;
}

//---------------------------------------------------------------------------
// printInfo
// Pre: None
// Post: prints author's name, title, and year

void Fiction::printInfo() {
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
   //cout.width(15);
   cout << year << endl;
}

//---------------------------------------------------------------------------
// getInput
// Pre: Input formatted corrected
// Post: sets attributes for this object

istream& Fiction::getInput(istream& is) {
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

Fiction::~Fiction()
{
}

/*
istream& operator>>(istream& is, Fiction& F) {
   is >> F.authorLastName;

   while (true) {
      string firstName;
      is >> firstName;
      F.authorFirstName += firstName;
      if (F.authorFirstName.back() == ',') {
         break;
      }
      F.authorFirstName += " ";
   }

   while (true) {
      string tempTitle;
      is >> tempTitle;
      F.title += tempTitle;
      if (F.title.back() == ',') {
         break;
      }
      F.title += " ";
   }
   is >> F.year;
   return is;
}
*/

/*
bool Fiction::equals(const Resource& other) const {
   const Fiction& f = (const Fiction&)other;
   if (title == f.title && authorFirstName == f.authorFirstName
      && authorLastName == f.authorLastName && format == f.format) {
      return true;
   }
   return false;
}*/