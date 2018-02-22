#pragma once
#include "Interact.h"
class Return :
	public Interact
{
public:
	Return();



	virtual Interact* create() const { return new Return; };
	istream& getInput(istream& is);
	
	~Return();
};

