//---------------------------------------------------------------------------
// ResourceFactory.h
// Class which allows production of Resource's child classes
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// ResourceFactory class:
//   -- Allows creation of Resource subclasses
//
//  Implementation and assumptions:
//  
//---------------------------------------------------------------------------


#include "Fiction.h"
#include "Youth.h"
#include "Periodical.h"
#pragma once
class ResourceFactory
{
public:
//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: Blank objects of type resource are placed in blankResources
   ResourceFactory();

//---------------------------------------------------------------------------
// produce
// Pre: None
// Post: Blank object of type resource is returned
   Resource* produce(char choice) const;

//---------------------------------------------------------------------------
// isApprovedResource
// Pre: None
// Post: Determines of char used is appropriate
   bool isApprovedResource(char choice);

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None
   ~ResourceFactory();
private:

   char approvedInputs[26] = {'F', 'P', 'Y'};

   Resource* blankResources[26];
};

