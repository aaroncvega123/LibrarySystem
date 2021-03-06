#include "stdafx.h"
#include "InteractFactory.h"


InteractFactory::InteractFactory()
{
	blankInteracts[2] = new checkOut();
	blankInteracts[3] = new Display();
	blankInteracts[7] = new History();
	blankInteracts[17] = new Return();
}

Interact* InteractFactory::produce(char choice) const {
	return blankInteracts[choice - 'A']->create();
}

bool InteractFactory::isApprovedInput(char choice) {
	for (int i = 0; i < 26; i++) {
		if (approvedInputs[i] == choice) {
			return true;
		}
	}
	return false;
}

InteractFactory::~InteractFactory()
{
}
