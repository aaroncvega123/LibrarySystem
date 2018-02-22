//---------------------------------------------------------------------------
// LibrarySystem.h
// Manages all associated objects in library sytem
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// Resource class:
//   -- Allows for populating resource list
//   -- Allows for populating patron list
//
//  Implementation and assumptions:
//   -- Assumes all inputs come from text file
//---------------------------------------------------------------------------
#pragma once
#include "PatronList.h"
#include "ResourceList.h"
#include "InteractFactory.h"
#include "ResourceFactory.h"
#include <fstream>
using namespace std;

class LibrarySystem
{
public:
//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: Blank objects of type interact are placed in blankInteracts
   LibrarySystem();

//---------------------------------------------------------------------------
// populatePatronList
// Pre: No null input
// Post: patronList will be populated
   void populatePatronList(ifstream& infile);

//---------------------------------------------------------------------------
// populateResourceList
// Pre: No null input
// Post: resourceList will be populated
   void populateResourceList(ifstream& infile);

//---------------------------------------------------------------------------
// setCommandsFromFile
// Pre: No null input
// Post: Each line in infile will be used and processed
   void setCommandsFromFile(ifstream& infile);

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None
   ~LibrarySystem();

private:
   PatronList patronList;
   ResourceList resourceList;
};

