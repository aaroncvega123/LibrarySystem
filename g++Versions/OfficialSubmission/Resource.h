//---------------------------------------------------------------------------
// Resource.h
// Class representing borrowable item of library
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// Resource class: Represents books of fiction
//   -- Allows for storing genre and borrower
//
//  Implementation and assumptions:
//   -- Assumes only child classes will be used
//---------------------------------------------------------------------------
#pragma once
#include <iostream>
#include "Patron.h"
using namespace std;

class Resource
{
public:

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: None
   Resource();

//---------------------------------------------------------------------------
// hash
// Meant to take all attributes and return and number based on that
// Pre: None
// Post: None
   virtual int hash() const { return 0; };

//---------------------------------------------------------------------------
// operator>>
// Meant to take input and run it with getInput()
// Pre: Items not null
// Post: Returns is
   friend istream& operator>>(istream& is, Resource& R) {
      R.getInput(is);
      return is;
   };

//---------------------------------------------------------------------------
// getInput
// Meant to run command line. To be overrided by child classes
// Pre: is not null
// Post: Returns is
   virtual istream& getInput(istream& is) {
      return is;
   };

//---------------------------------------------------------------------------
// setSearchData
// Meant to run command line. To be overrided by child classes
// Pre: is not null
// Post: Returns is
   virtual istream& setSearchData(istream& is) {
      return is;
   }

//---------------------------------------------------------------------------
// getGenre
// Pre: None
// Post: Returns genre
   virtual char getGenre() const { return genre; } ;

//---------------------------------------------------------------------------
// create
// Meant to be overrided by child classes
// Pre: None
// Post: None
   virtual Resource* create() const = 0;

//---------------------------------------------------------------------------
// operator==
// Meant to compare two resources
// Pre: Both resources must be of same class
// Post: Returns true if shares similar attributes
   virtual bool operator==(const Resource& other) const {
	   return false;
   };
   
//---------------------------------------------------------------------------
// setBorrower
// Pre: No null inputs
// Post: sets patron pointer to borrower
   void setBorrower(Patron* newBorrower);

//---------------------------------------------------------------------------
// clearBorrower
// Pre: None
// Post: if id matches patron pointer's id, the pointer will be set to null
   bool clearBorrower(int id);

//---------------------------------------------------------------------------
// getBorrowerID
// Pre: None
// Post: will return ID of person borrower resource
   int getBorrowerID();

//---------------------------------------------------------------------------
// printInfo
// Meant to be overrided so items can print their own custom data
// Pre: None
// Post: None
   virtual void printInfo() {};

//---------------------------------------------------------------------------
// isAvailable
// Pre: None
// Post: If patron pointer is null, will return true
   bool isAvailable();
   
//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None
   ~Resource();
protected:

   char genre = ' ';
   Patron* borrower = NULL;

};

