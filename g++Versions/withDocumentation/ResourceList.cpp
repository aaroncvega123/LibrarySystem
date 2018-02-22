//---------------------------------------------------------------------------
// ResourceList.cpp
// Class representing a collection of all resources
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// ResourceList class: For storing all library resources
//   -- Allows for storage resources
//   -- Allows for extraction
//
// Assumptions:
//   -- Assumes no material is to be removed
//   -- Assumes material doesn't need to be placed in alphabetical order
//---------------------------------------------------------------------------

//#include "stdafx.h"
#include "ResourceList.h"
#include "ResourceFactory.h"
#include "Resource.h"
#include "FictionHeader.h"
#include "YouthHeader.h"
#include "PeriodicalHeader.h"
#include "Fiction.h"
#include <string>
#include <iostream>
using namespace std;

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: Headers are added to sections that exist

ResourceList::ResourceList()
{
   resourceHashTable['Y' - 'A'][0].resource = new YouthHeader;
   resourceHashTable['F' - 'A'][0].resource = new FictionHeader;
   resourceHashTable['P' - 'A'][0].resource = new PeriodicalHeader;

}

//---------------------------------------------------------------------------
// populateList
// Pre: File should be formatted correctly
// Post: All objects will be added to hash table
void ResourceList::populateList(ifstream& infile) {
   ResourceFactory factory;
   while (!infile.eof()) {
      while (!infile.eof()) {
         char resourceFormat;
         infile >> resourceFormat;
         if (!(factory.isApprovedResource(resourceFormat))) {
            string dummy;
            getline(infile, dummy);
            break;
         };
         Resource* newAddition = factory.produce(resourceFormat);
         infile >> *newAddition;
         addResource(*newAddition);
         newAddition = NULL;
      }
   }
}

//---------------------------------------------------------------------------
// addResource
// Pre: None
// Post: Resource will be added to hash table
void ResourceList::addResource(Resource& input) {
   int hashCode = input.hash();
   if (hashCode > 222) {
      hashCode = hashCode % 222;
   }
   ResourceNode* current;
   current = &resourceHashTable[input.getGenre() - 'A'][hashCode];
   while (current->resource != NULL) {
      current = current->nextNode;
   }

   current->resource = &input;
   current->nextNode = new ResourceNode();
   current = NULL;
}

//---------------------------------------------------------------------------
// getResource
// Pre: dummy is not null
// Post: Pointer to matching resource will be returned
Resource* ResourceList::getResource(Resource* dummy) {
   int hashCode = dummy->hash();
   if (hashCode > 222) {
      hashCode = hashCode % 222;
   }
   ResourceNode* nodePtr = 
	   &resourceHashTable[dummy->getGenre() - 'A'][hashCode];

   while (true) {
      if (nodePtr->resource == NULL) {
         return NULL;
      }
      if (*dummy == *nodePtr->resource) {
         //dummy = nullptr;
         return nodePtr->resource;
      }
      nodePtr = nodePtr->nextNode;
   }
   //dummy = nullptr;
   return NULL;
}

//---------------------------------------------------------------------------
// getAvailableResource
// Pre: dummy is not null
// Post: Pointer to matching resource will be returned if it's available

Resource* ResourceList::getAvailableResource(Resource* dummy) {
   int hashCode = dummy->hash();
   if (hashCode > 222) {
      hashCode = hashCode % 222;
   }
   ResourceNode* nodePtr = 
	   &resourceHashTable[dummy->getGenre() - 'A'][hashCode];

   while (true) {
      if (nodePtr->resource == NULL) {
         return NULL;
      }
      if (*dummy == *nodePtr->resource 
		  && nodePtr->resource->isAvailable()) {
         return nodePtr->resource;
      }
      nodePtr = nodePtr->nextNode;
   }
   return NULL;
}

//---------------------------------------------------------------------------
// getBorrowedResource
// Pre: dummy is not null
// Post: Pointer to matching resource will be returned if ID matches borrwer

Resource* ResourceList::getBorrowedResource(const Resource& dummy, int ID) {
   ResourceNode* nodePtr = 
	   &resourceHashTable[dummy.getGenre() - 'A'][dummy.hash()];
   while (nodePtr != NULL) {
      if (dummy == *nodePtr->resource) {
         if (nodePtr->resource->getBorrowerID() == ID) {
            return nodePtr->resource;
         }
      }
      nodePtr = nodePtr->nextNode;
   }
   return NULL;
}

//---------------------------------------------------------------------------
// getResourceNode
// Pre: Hash is not less than 0
// Post: Pointer to resource node is returned

ResourceNode* ResourceList::getResourceNode(int y, int x) {
   return &resourceHashTable[y][x];
}

//---------------------------------------------------------------------------
// recursiveDealloc
// Pre: Only used by deconstructor
// Post: With every recursion, nodes in linked list of hash table are
//       deallocated

void ResourceList::recursiveDealloc(ResourceNode* current) {
   if (current == NULL) {
      return;
   }
   else {
      recursiveDealloc(current->nextNode);
      delete current->resource;
      if (current->resource != NULL) {
         current->resource = nullptr;
      }
      if (current->nextNode != NULL) {
         delete current->nextNode;
         current->nextNode = nullptr;
      }
      return;
   }
   return;
}

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: All stored resources are deallocated
ResourceList::~ResourceList()
{
   for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 223; j++) {
         ResourceNode *current = &resourceHashTable[i][j];
         recursiveDealloc(current);
         current = nullptr;
      }
   }
}
