//---------------------------------------------------------------------------
// ResourceList.h
// Class representing a collection of all resources
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// ResourceList class: For storing all library resources
//   -- Allows for storage resources
//   -- Allows for extraction
//
// Implementation and assumptions:
//   -- Assumes no material is to be removed
//   -- Assumes material doesn't need to be placed in alphabetical order
//---------------------------------------------------------------------------
#pragma once
#include "Resource.h"
#include <iostream>
#include <fstream>

//---------------------------------------------------------------------------
// ResourceNode
// To be used in case of resource collisions in the hash table
// Pre: None
// Post: None
struct ResourceNode {
   Resource* resource = NULL;
   ResourceNode* nextNode = NULL;
};

class ResourceList
{
public:

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: Headers are added to sections that exist
   ResourceList();

//---------------------------------------------------------------------------
// populateList
// Pre: File should be formatted correctly
// Post: All objects will be added to hash table
   void populateList(ifstream& infile);
   
//---------------------------------------------------------------------------
// addResource
// Pre: None
// Post: Resource will be added to hash table
   void addResource(Resource& input);

//---------------------------------------------------------------------------
// getResource
// Pre: dummy is not null
// Post: Pointer to matching resource will be returned
   Resource* getResource(Resource* dummy);

//---------------------------------------------------------------------------
// getAvailableResource
// Pre: dummy is not null
// Post: Pointer to matching resource will be returned if it's available
   Resource* getAvailableResource(Resource* dummy);

//---------------------------------------------------------------------------
// getBorrowedResource
// Pre: dummy is not null
// Post: Pointer to matching resource will be returned if ID matches borrwer
   Resource* getBorrowedResource(const Resource& dummy, int ID);

//---------------------------------------------------------------------------
// getResourceNode
// Pre: Hash is not less than 0
// Post: Pointer to resource node is returned
   ResourceNode* getResourceNode(int genre, int hash);

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: All stored resources are deallocated
   ~ResourceList();

private:
   
//---------------------------------------------------------------------------
// recursiveDealloc
// Pre: Only used by deconstructor
// Post: With every recursion, nodes in linked list of hash table are
//       deallocated
   void recursiveDealloc(ResourceNode* current);

   char approvedGenres[26] = { 'Y', 'F', 'P' };
   ResourceNode resourceHashTable[26][223];

};

