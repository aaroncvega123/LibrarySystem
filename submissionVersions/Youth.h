#pragma once
#include "Publication.h"
#include <iostream>
using namespace std;

class Youth :
	public Publication
{
public:
	Youth();
	~Youth();
	//friend istream& operator>>(istream& is, Youth& Y);

	void print();
	int hash() const;

	Resource* create() const { return new Youth; };

	char getGenre() const { return genre; };

	void setAuthorFirstName(string newFirst) { authorFirstName = newFirst; };
	void setAuthorLastName(string newLast) { authorLastName = newLast; };

	bool operator==(const Resource& other) const;

	istream& setSearchData(istream& is);

	void printInfo();
private:

	string authorFirstName;
	string authorLastName;
	char genre = 'Y';
protected:
	istream& getInput(istream& is);
};

