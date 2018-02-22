#include "stdafx.h"
#include "Resource.h"


Resource::Resource()
{
}

void Resource::setBorrower(Patron* newBorrower) {
	if (isAvailable()) {
		borrower = newBorrower;
	}
}

bool Resource::clearBorrower(int id) {
	if (borrower->getID() == id) {
		borrower = NULL;
		return true;
	}
	return false;
}

bool Resource::isAvailable() {
	if (borrower == NULL) {
		return true;
	}
	return false;
}

int Resource::getBorrowerID() {
	return borrower->getID();
}

Resource::~Resource()
{
}
