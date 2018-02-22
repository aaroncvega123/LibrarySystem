#include "stdafx.h"
#include "PatronList.h"


PatronList::PatronList()
{
}

void PatronList::addPatron(Patron& P) {
	patronArray[P.getID()] = P;
}

void PatronList::populateList(istream& is) {
	while (!is.eof()) {
		Patron patron;
		is >> patron;
		addPatron(patron);
	}
}

void PatronList::printList() {
	for (int i = 0; i < 10000; i++) {
		if (patronArray[i].getID() > 0) {
			cout << patronArray[i].getID() <<
				" " << patronArray[i].getFirstName() <<
				" " << patronArray[i].getLastName() << endl;
		}
	}
}

Patron* PatronList::getPatronPointer(int id) {
	Patron* pPtr;
	pPtr = &patronArray[id];
	if (patronArray[id].getFirstName() == "") {
		cout << id << " is not a valid ID" << endl;
		cout << endl;
	}
	return pPtr;
}

bool PatronList::patronExists(int id) {
	return false;
}

PatronList::~PatronList()
{
}
