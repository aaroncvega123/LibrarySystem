#pragma once
#include "Publication.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Fiction :
	public Publication
{
public:
	Fiction();
	~Fiction();

	friend istream& operator>>(istream& is, Fiction& F);
	int hash() const;
	Resource* create() const { return new Fiction; };
	char getGenre() const { return genre; };

	bool operator==(const Resource& other) const;
	

	istream& setSearchData(istream& is);

	virtual void printInfo();
private:
	string authorFirstName;
	string authorLastName;
protected:
	istream& getInput(istream& is);
	bool equals(const Resource& other) const;
};

