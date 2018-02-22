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

	//When i set it to 3 instead of 26, a error
	//shows up in g++. I don't know why.
	char approvedInputs[26] = {'F', 'P', 'Y'};

	Resource* blankResources[26];
};

