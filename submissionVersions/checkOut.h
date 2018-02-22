#pragma once
#include "Interact.h"



class checkOut :
	public Interact
{
public:
	checkOut();

	virtual Interact* create() const { return new checkOut; };

	istream& getInput(istream& is);


	~checkOut();
};

