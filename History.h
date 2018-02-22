#pragma once
#include "Interact.h"
class History :
	public Interact
{
public:
	History();

	virtual Interact* create() const { return new History; };

	istream& getInput(istream& is);

	~History();
};

