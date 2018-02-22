#pragma once
#include "Resource.h"
#include <iostream>
#include <fstream>


struct ResourceNode {
	Resource* resource = NULL;
	ResourceNode* nextNode = NULL;
};

class ResourceList
{
public:

	ResourceList();
	~ResourceList();
	//Resource& findResource(int hash);
	void addResource(Resource& input);
	void populateList(ifstream& infile);
	Resource* getResource(Resource* dummy);
	Resource* getAvailableResource(Resource* dummy);
	Resource* getBorrowedResource(const Resource& dummy, int ID);
	ResourceNode* getResourceNode(int genre, int hash);
private:

	char approvedGenres[26] = { 'Y', 'F', 'P' };
	ResourceNode resourceHashTable[26][223];


};

