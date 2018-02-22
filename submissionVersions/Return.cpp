//#include "stdafx.h"
#include "Return.h"

#include "Resource.h"
#include "PatronList.h"
#include "ResourceList.h"
#include "ResourceFactory.h"

Return::Return()
{
	interactName = "Returned";
}

istream& Return::getInput(istream& is) {
	ResourceFactory rFactory;

	int patronID;
	is >> patronID;

	char resourceGenre;
	is >> resourceGenre;

	if (!rFactory.isApprovedResource(resourceGenre)) {
		string dummy;
		getline(is, dummy);
		return is;
	}

	Resource *searchItem = rFactory.produce(resourceGenre);
	searchItem->setSearchData(is);
	Resource *resourcePtr = rListPtr->getResource(searchItem);
	Patron *patronPtr = pListPtr->getPatronPointer(patronID);

	if (resourcePtr != NULL) {
		if (resourcePtr->clearBorrower(patronID)) {
			patronPtr->addHistory(*this);
			associatedResource = resourcePtr;
		}

	}


	return is;
}


Return::~Return()
{
}
