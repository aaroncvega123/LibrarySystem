//---------------------------------------------------------------------------
// Display.cpp
// Class representing action to display all library resources
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// Display class: For display all resources
//   -- Allows for viewing of all resources and their availabilities
//
//  Assumptions:
//   -- Assumes material doesn't need to be viewed in alphabetical order
//---------------------------------------------------------------------------

//#include "stdafx.h"
#include "Display.h"

#include "PatronList.h"
#include "ResourceList.h"
#include <string>

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: InteractName is set to "Display"

Display::Display()
{
   interactName = "Display";
}

//---------------------------------------------------------------------------
// getInput
// Accesses resourceHashTable and prints out all contents
// Pre: is not null
// Post: All library resources displayed on console

istream& Display::getInput(istream& is){
   for (int i = 0; i < 26; i++) {
      // Checks to see if Hash table section has items
      ResourceNode* current = rListPtr->getResourceNode(i, 0);
      if (current->resource != NULL) {
         current->resource->printInfo();
         current = current->nextNode;

         DisplayNode nodeArray[100];
         int arraySize = 0;
         
         // Cycles through first index's linked list
         while (true) {
            if (current == NULL || current->resource == NULL) {
               break;
            }
            bool isInArray = false;
            for (int j = 0; j < arraySize; j++) {
               if (nodeArray[j].resource == current->resource) {
                  isInArray = true;
                  if (current->resource->isAvailable()) {
                     nodeArray[j].available++;
                  }
               }
            }

            //Cycles through linked list for occurances of same resource
            if (!isInArray) {
               nodeArray[arraySize].resource = current->resource;
               arraySize++;
               if (current->resource->isAvailable()) {
                  nodeArray[arraySize].available++;
               }
            }
            current = current->nextNode;
         }
         
         for (int j = 0; j < arraySize; j++) {
            cout << nodeArray[j].available;
            nodeArray[j].resource->printInfo();
         }

         // Does similar method above but for rest of hash table section
         for (int j = 1; j < 223; j++) {
            current = rListPtr->getResourceNode(i, j);

            DisplayNode nodeArray[100];
            int arraySize = 0;

            while (true) {
               if (current == NULL || current->resource == NULL) {
                  break;
               }
               bool isInArray = false;
               for (int k = 0; k < arraySize; k++) {
                  if (*nodeArray[k].resource == *current->resource) {
                     isInArray = true;
                     if (current->resource->isAvailable()) {
                        nodeArray[k].available += 1;
                     }
                  }
               }
               if (!isInArray) {
                  nodeArray[arraySize].resource = current->resource;
                  if (current->resource->isAvailable()) {
                     nodeArray[arraySize].available += 1;
                  }
                  arraySize++;
               }
               current = current->nextNode;
            }
            for (int k = 0; k < arraySize; k++) {
               cout.setf(ios::left);
               cout.width(7);
               cout << nodeArray[k].available;
               nodeArray[k].resource->printInfo();
            }

         }
         cout << endl;
      }
   }
   string dummy;
   getline(is, dummy);
   return is;
}

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: None

Display::~Display()
{
}
