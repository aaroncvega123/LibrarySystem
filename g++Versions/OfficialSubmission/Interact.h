//---------------------------------------------------------------------------
// Interact.h
// Class representing an action involving the library system
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// Interact class: Allows for creating different kinds of interactions
//   -- Allows child classes to inherit basic functions
//
// Implementation and assumptions:
//   -- Assumes only child classes will be used
//   -- Assumes interaction will always have a patron list and resource list
//---------------------------------------------------------------------------

#pragma once
#include <iostream>
#include <string>
using namespace std;

class PatronList;
class ResourceList;
class ResourceFactory;
class Resource;

class Interact
{
public:

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: None
   Interact();

//---------------------------------------------------------------------------
// getInput
// Pre: Input is correctly formatted
// Post: Depends on which child class calls this. Otherwise, returns is
   virtual istream& getInput(istream& is) {
      return is;
   };

//---------------------------------------------------------------------------
// usePatronList
// Pre: pList is not null
// Post: This interact will point to a patron list
   void usePatronList(PatronList* pList);

//---------------------------------------------------------------------------
// useResourceList
// Pre: rList is not null
// Post: This interact will point to a resource list
   void useResourceList(ResourceList* rList);

//---------------------------------------------------------------------------
// create
// Pre: None
// Post: Returns new interact object
   virtual Interact* create() const { return new Interact; };

//---------------------------------------------------------------------------
// getName
// Pre: None
// Post: Returns interactName
   string getName() { return interactName; };

//---------------------------------------------------------------------------
// getAssociatedResource
// Pre: None
// Post: Returns resource this interact was used with, if not null
   Resource* getAssociatedResource() { return associatedResource; };
   
//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None
   ~Interact();

protected:
   string interactName;
   PatronList* pListPtr;
   ResourceList* rListPtr;
   Resource* associatedResource;
};