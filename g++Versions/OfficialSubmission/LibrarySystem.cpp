//---------------------------------------------------------------------------
// LibrarySystem.cpp
// Manages all associated objects in library sytem
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// Resource class:
//   -- Allows for populating resource list
//   -- Allows for populating patron list
//
//  Assumptions:
//   -- Assumes all inputs come from text file
//---------------------------------------------------------------------------
//#include "stdafx.h"
#include "LibrarySystem.h"
//#include "Display.h"

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: Blank objects of type interact are placed in blankInteracts
LibrarySystem::LibrarySystem()
{
}

//---------------------------------------------------------------------------
// populatePatronList
// Pre: No null input
// Post: patronList will be populated
void LibrarySystem::populatePatronList(ifstream& infile) {
   patronList.populateList(infile);
}

//---------------------------------------------------------------------------
// populateResourceList
// Pre: No null input
// Post: resourceList will be populated
void LibrarySystem::populateResourceList(ifstream& infile) {
   resourceList.populateList(infile);
}

//---------------------------------------------------------------------------
// setCommandsFromFile
// Pre: No null input
// Post: Each line in infile will be used and processed
void LibrarySystem::setCommandsFromFile(ifstream& infile) {
   InteractFactory iFactory;
   char interactChoice = 'M';
   while (!infile.eof()) {

      while (true) {
         infile >> interactChoice;
         if (!iFactory.isApprovedInput(interactChoice)) {
            cout << interactChoice << " is not a valid command" << endl;
            cout << endl;
            string dummy;
            getline(infile, dummy);

            break;
         }

         Interact* interaction = iFactory.produce(interactChoice);
   
         interaction->usePatronList(&patronList);
         interaction->useResourceList(&resourceList);
         interaction->getInput(infile);
         
         interaction = nullptr;

         break;
      }
      if (infile.eof()) {
         break;
      }
   }

}

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None
LibrarySystem::~LibrarySystem()
{
}
