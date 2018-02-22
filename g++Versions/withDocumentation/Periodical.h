//---------------------------------------------------------------------------
// Periodical.h
// Class representing a periodical
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// Fiction class: Represents books of periodical
//   -- Allows for storing book information
//   -- Allows to be used for searching ResourceList
//   -- Allows to create hash code for object
//
//  Assumptions:
//   -- Assumes input is correct format
//---------------------------------------------------------------------------
#pragma once
#include "Publication.h"
class Periodical :
   public Publication
{
public:

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: Sets genre to 'P'.
   Periodical();

   //friend istream& operator>>(istream& is, Periodical& P);
   
//---------------------------------------------------------------------------
// hash
// Outputs number based on attributes
// Pre: None
// Post: Returns integer
   int hash() const;

//---------------------------------------------------------------------------
// create
// For creating Periodical object
// Pre: None
// Post: Returns new Periodical object
   Resource* create() const { return new Periodical; };

//---------------------------------------------------------------------------
// operator==
// For comparing two Periodical objects
// Pre: input must be of type Periodical
// Post: True, if all attributes (except year) are the same
   bool operator==(const Resource& other) const;

//---------------------------------------------------------------------------
// setSearchData
// For when need a dummy Periodical object for searching the ResourceList
// Pre: None
// Post: Sets month, year, and title
   istream& setSearchData(istream& is);

//---------------------------------------------------------------------------
// printInfo
// Pre: None
// Post: prints year, month, and title
   virtual void printInfo();

//---------------------------------------------------------------------------
// getGenre
// Pre: None
// Post: Returns genre
   char getGenre() const { return genre; };

//---------------------------------------------------------------------------
// getMonth
// Pre: None
// Post: Returns month
   int getMonth() const { return month; };

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None
   ~Periodical();

private:

//---------------------------------------------------------------------------
// getInput
// Pre: Input formatted corrected
// Post: sets attributes for this object
   istream& getInput(istream& is);

   int month;

};

