#pragma once
#include <iostream>
#include "Patron.h"
using namespace std;

class Resource
{
public:
	Resource();
	~Resource();
	virtual int hash() const { return 0; };
	friend istream& operator>>(istream& is, Resource& R) {
		R.getInput(is);
		return is;
	};
	virtual istream& getInput(istream& is) {
		return is;
	};

	virtual istream& setSearchData(istream& is) {
		return is;
	}

	virtual char getGenre() const { return genre; } ;
	virtual Resource* create() const = 0;

	virtual bool operator==(const Resource& other) const {
		return equals(other);
	};
	virtual bool equals(const Resource& other) const { return false; };
	
	void setBorrower(Patron* newBorrower);
	bool clearBorrower(int id);
	int getBorrowerID();

	virtual void printInfo() {};

	bool isAvailable();
protected:

	char genre = ' ';
	Patron* borrower = NULL;

private:

};

