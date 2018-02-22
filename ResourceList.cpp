#include "stdafx.h"
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


ResourceList::ResourceList()
{
	resourceHashTable['Y' - 'A'][0].resource = new YouthHeader;
	resourceHashTable['F' - 'A'][0].resource = new FictionHeader;
	resourceHashTable['P' - 'A'][0].resource = new PeriodicalHeader;

}

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

Resource* ResourceList::getResource(Resource* dummy) {
	int hashCode = dummy->hash();
	if (hashCode > 222) {
		hashCode = hashCode % 222;
	}
	ResourceNode* nodePtr = &resourceHashTable[dummy->getGenre() - 'A'][hashCode];

	while (true) {
		if (nodePtr->resource == NULL) {
			return NULL;
		}
		if (*dummy == *nodePtr->resource) {
			return nodePtr->resource;
		}
		nodePtr = nodePtr->nextNode;
	}
	return NULL;
}

Resource* ResourceList::getAvailableResource(Resource* dummy) {
	int hashCode = dummy->hash();
	if (hashCode > 222) {
		hashCode = hashCode % 222;
	}
	ResourceNode* nodePtr = &resourceHashTable[dummy->getGenre() - 'A'][hashCode];

	while (true) {
		if (nodePtr->resource == NULL) {
			return NULL;
		}
		if (*dummy == *nodePtr->resource && nodePtr->resource->isAvailable()) {
			return nodePtr->resource;
		}
		nodePtr = nodePtr->nextNode;
	}
	return NULL;
}

Resource* ResourceList::getBorrowedResource(const Resource& dummy, int ID) {
	ResourceNode* nodePtr = &resourceHashTable[dummy.getGenre() - 'A'][dummy.hash()];
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

ResourceNode* ResourceList::getResourceNode(int y, int x) {
	return &resourceHashTable[y][x];
}

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
