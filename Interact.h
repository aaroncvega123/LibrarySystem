#pragma once
#include <iostream>
#include <string>
using namespace std;

//#include "LibrarySystem.h"
//#include "PatronList.h"
//#include "ResourceList.h"

class PatronList;
class ResourceList;
class ResourceFactory;
class Resource;

class Interact
{
public:
	Interact();
	virtual void run();
	//friend istream& operator>>(istream& is, Interact& I) {
		//I.getInput(is);
		//return is;
	//};
	virtual istream& getInput(istream& is) {
		return is;
	};

	//void useLibrary(LibrarySystem& Library);
	void usePatronList(PatronList* pList);
	void useResourceList(ResourceList* rList);

	~Interact();

	virtual Interact* create() const { return new Interact; };

	string getName() { return interactName; };

	Resource* getAssociatedResource() { return associatedResource; };

protected:
	string interactName;

	PatronList* pListPtr;
	ResourceList* rListPtr;
	Resource* associatedResource;
};