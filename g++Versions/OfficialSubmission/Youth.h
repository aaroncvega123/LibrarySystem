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

#pragma once
#include "Publication.h"
#include <iostream>
using namespace std;

class Youth :
   public Publication
{
public:
//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: Sets genre to 'Y'.
   Youth();

//---------------------------------------------------------------------------
// hash
// Outputs number based on attributes
// Pre: None
// Post: Returns integer
   int hash() const;

//---------------------------------------------------------------------------
// operator==
// For comparing two Youth objects
// Pre: input must be of type Youth
// Post: True, if all attributes (except year) are the same
   bool operator==(const Resource& other) const;

//---------------------------------------------------------------------------
// create
// For creating Youth Object
// Pre: None
// Post: Returns new Youth object
   Resource* create() const { return new Youth; };

//---------------------------------------------------------------------------
// getGenre
// Pre: None
// Post: Returns genre
   char getGenre() const { return genre; };

//---------------------------------------------------------------------------
// setAuthorFirstName setAuthorLastName
// Pre: no null inputs
// Post: will set name attributes
   void setAuthorFirstName(string newFirst) 
   { authorFirstName = newFirst; };
   void setAuthorLastName(string newLast) 
   { authorLastName = newLast; };

//---------------------------------------------------------------------------
// setSearchData
// For when need a dummy Fiction object for searching the ResourceList
// Pre: None
// Post: Sets author's last name, first name, title, and format
   istream& setSearchData(istream& is);

//---------------------------------------------------------------------------
// printInfo
// Pre: None
// Post: prints author's name, title, and year
   void printInfo();

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None
   ~Youth();
private:

   string authorFirstName;
   string authorLastName;
   char genre = 'Y';
protected:

//---------------------------------------------------------------------------
// getInput
// Pre: Input formatted corrected
// Post: sets attributes for this object
   istream& getInput(istream& is);
};

