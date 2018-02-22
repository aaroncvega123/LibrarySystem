//---------------------------------------------------------------------------
// Display.h
// Class representing action to display all library resources
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// Display class: For display all resources
//   -- Allows for viewing of all resources and their availabilities
//
//  Implementation and assumptions:
//   -- Assumes material doesn't need to be viewed in alphabetical order
//---------------------------------------------------------------------------

#pragma once
#include "Interact.h"
#include <ios>
using namespace std;

class PatronList;
class ResourceList;
class ResourceFactory;
class Resource;

//---------------------------------------------------------------------------
// DisplayNode
// Used to represent how many versions of a resource are available
// Pre: None
// Post: None
struct DisplayNode {
   int available = 0;
   Resource* resource;
};

class Display :
   public Interact
{
public:
//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: InteractName is set to "Display"
   Display();

//---------------------------------------------------------------------------
// create
// Pre: None
// Post: Returns a new checkOut object
   virtual Interact* create() const { return new Display; };

//---------------------------------------------------------------------------
// getInput
// Accesses resourceHashTable and prints out all contents
// Pre: is not null
// Post: All library resources displayed on console
   istream& getInput(istream& is);   

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None
   ~Display();

};

