#include "Resource.h"
#include "Fiction.h"
#include "Youth.h"
#include "Periodical.h"
#pragma once
class ResourceFactory
{
public:
	ResourceFactory();
	~ResourceFactory();
	Resource* produce(char choice) const;
	bool isApprovedResource(char choice);
private:

	char approvedInputs[26] = { 'Y', 'P', 'F' };

	Resource* blankResources[26];
};

