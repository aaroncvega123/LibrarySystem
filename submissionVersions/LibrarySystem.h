#pragma once
#include "PatronList.h"
#include "ResourceList.h"
#include "InteractFactory.h"
#include "ResourceFactory.h"
#include <fstream>
using namespace std;

class LibrarySystem
{
public:
	LibrarySystem();
	~LibrarySystem();
	void populatePatronList(ifstream& infile);
	void populateResourceList(ifstream& infile);
	void setCommandsFromFile(ifstream& infile);
private:
	PatronList patronList;
	ResourceList resourceList;
};

