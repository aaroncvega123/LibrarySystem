#pragma once
#include "Patron.h"
#include <iostream>
using namespace std;

class PatronList
{
public:
	PatronList();
	~PatronList();
	void addPatron(Patron& p);
	void populateList(istream& is);
	void printList();
	Patron* getPatronPointer(int ID);
	bool patronExists(int ID);
private:
	Patron patronArray[10000];
};

