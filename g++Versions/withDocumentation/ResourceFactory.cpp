//---------------------------------------------------------------------------
// ResourceFactory.cpp
// Class which allows production of Resource's child classes
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// ResourceFactory class:
//   -- Allows creation of Resource subclasses
//
// Assumptions:
//  
//---------------------------------------------------------------------------
//#include "stdafx.h"
#include "ResourceFactory.h"

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: Blank objects of type resource are placed in blankResources
ResourceFactory::ResourceFactory()
{
   for (int i = 0; i < 26; i++) blankResources[i] = NULL;
   blankResources[5] = new Fiction();
   blankResources[15] = new Periodical();
   blankResources[24] = new Youth();
}

//---------------------------------------------------------------------------
// produce
// Pre: None
// Post: Blank object of type resource is returned
Resource* ResourceFactory::produce(char choice) const{
   return blankResources[choice - 'A']->create();
}

//---------------------------------------------------------------------------
// isApprovedResource
// Pre: None
// Post: Determines of char used is appropriate
bool ResourceFactory::isApprovedResource(char choice) {
   for (int i = 0; i < 26; i++) {
      if (approvedInputs[i] == choice) {
         return true;
      }
   }
   return false;
}

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None
ResourceFactory::~ResourceFactory()
{
}
