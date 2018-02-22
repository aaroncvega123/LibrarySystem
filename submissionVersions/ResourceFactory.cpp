//#include "stdafx.h"
#include "ResourceFactory.h"


ResourceFactory::ResourceFactory()
{
	blankResources[5] = new Fiction();
	blankResources[15] = new Periodical();
	blankResources[24] = new Youth();
}

Resource* ResourceFactory::produce(char choice) const{
	return blankResources[choice - 'A']->create();
}

bool ResourceFactory::isApprovedResource(char choice) {
	if (!(find(begin(approvedInputs), end(approvedInputs), choice) != end(approvedInputs))) {
		return false;
	}
	return true;
}

ResourceFactory::~ResourceFactory()
{
}
