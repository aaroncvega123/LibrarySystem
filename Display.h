#pragma once
#include "Interact.h"
#include <ios>
using namespace std;

class PatronList;
class ResourceList;
class ResourceFactory;
class Resource;

struct DisplayNode {
	int available = 0;
	Resource* resource;
};

class Display :
	public Interact
{
public:
	Display();

	virtual Interact* create() const { return new Display; };
	istream& getInput(istream& is);	

	~Display();

protected:

};

