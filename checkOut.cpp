#include "stdafx.h"
#include "checkOut.h"

#include "Resource.h"
#include "PatronList.h"
#include "ResourceList.h"
#include "ResourceFactory.h"

checkOut::checkOut()
{
	interactName = "Checked Out";
}

istream& checkOut::getInput(istream& is) {
	ResourceFactory rFactory;
	
	int patronID;
	is >> patronID;

	char resourceGenre;
	is >> resourceGenre;


	if (!rFactory.isApprovedResource(resourceGenre)) {
		cout << resourceGenre << " is not a valid genre" << endl;
		cout << endl;
		string dummy;
		getline(is, dummy);
		return is;
	}
	Resource *searchItem = rFactory.produce(resourceGenre);
	searchItem->setSearchData(is);
	Resource *resourcePtr = rListPtr->getAvailableResource(searchItem);
	Patron *patronPtr = pListPtr->getPatronPointer(patronID);

	if (resourcePtr != NULL && patronPtr != NULL) {
		resourcePtr->setBorrower(patronPtr);

		patronPtr->addHistory(*this);

		associatedResource = resourcePtr;
	}


	return is;
}

checkOut::~checkOut()
{
}
