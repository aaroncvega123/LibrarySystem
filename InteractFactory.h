#pragma once
#include "Interact.h"
#include "Display.h"
#include "checkOut.h"
#include "History.h"
#include "Return.h"

using namespace std;

class InteractFactory
{
public:
	InteractFactory();
	~InteractFactory();
	Interact* produce(char choice) const;
	bool isApprovedInput(char choice);

private:
	char approvedInputs[26] = { 'C', 'R', 'D', 'H'};
	Interact* blankInteracts[26];
};

