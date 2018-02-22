#pragma once
#include "Publication.h"
class Periodical :
	public Publication
{
public:
	Periodical();
	~Periodical();
	friend istream& operator>>(istream& is, Periodical& P);
	int hash() const;
	Resource* create() const { return new Periodical; };

	char getGenre() const { return genre; };
	int getMonth() const { return month; };

	bool operator==(const Resource& other) const;

	istream& setSearchData(istream& is);

	virtual void printInfo();
private:
	int month;
protected:
	istream& getInput(istream& is);
};

