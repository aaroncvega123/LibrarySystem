#include "stdafx.h"
#include "ResourceFactory.h"


ResourceFactory::ResourceFactory()
{
	for (int i = 0; i < 26; i++) blankResources[i] = NULL;
	blankResources[5] = new Fiction();
	blankResources[15] = new Periodical();
	blankResources[24] = new Youth();
}

Resource* ResourceFactory::produce(char choice) const{
	return blankResources[choice - 'A']->create();
}

bool ResourceFactory::isApprovedResource(char choice) {
	for (int i = 0; i < 3; i++) {
		if (approvedInputs[i] == choice) {
			return true;
		}
	}
	return false;
}

ResourceFactory::~ResourceFactory()
{
	//delete[] blankResources;
}
