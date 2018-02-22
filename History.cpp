#include "stdafx.h"
#include "History.h"

#include "Resource.h"
#include "PatronList.h"
#include "ResourceList.h"
#include "ResourceFactory.h"

History::History()
{
}

istream& History::getInput(istream& is) {
	ResourceFactory rFactory;

	int patronID;
	is >> patronID;

	Patron* patronPtr = pListPtr->getPatronPointer(patronID);
	patronPtr->printHistory();



	return is;
}

History::~History()
{
}
