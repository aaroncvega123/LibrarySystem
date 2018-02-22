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

#pragma once
#include "Publication.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Fiction :
   public Publication
{
public:

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: Sets genre to 'F'.
   Fiction();

   //friend istream& operator>>(istream& is, Fiction& F);
   
//---------------------------------------------------------------------------
// hash
// Outputs number based on attributes
// Pre: None
// Post: Returns integer
   int hash() const;

//---------------------------------------------------------------------------
// create
// For creating Fiction Object
// Pre: None
// Post: Returns new Fiction object
   Resource* create() const { return new Fiction; };

//---------------------------------------------------------------------------
// getGenre
// Pre: None
// Post: Returns genre
   char getGenre() const { return genre; };

//---------------------------------------------------------------------------
// operator==
// For comparing two Fiction objects
// Pre: input must be of type fiction
// Post: True, if all attributes (except year) are the same
   bool operator==(const Resource& other) const;
   
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
   virtual void printInfo();

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None
   ~Fiction();
private:

//---------------------------------------------------------------------------
// getInput
// Pre: Input formatted corrected
// Post: sets attributes for this object
   istream& getInput(istream& is);

   string authorFirstName;
   string authorLastName;

protected:

   //bool equals(const Resource& other) const;
};

