#include "stdafx.h"
#include "Patron.h"

#include "Interact.h"
#include "Resource.h"

Patron::Patron()
{
}

istream& operator>>(istream& is, Patron& P) {
	is >> P.ID;
	is >> P.lastName;
	is >> P.firstName;
	return is;
}

int Patron::getID(){
	return ID;
}

string Patron::getFirstName() {
	return firstName;
}

string Patron::getLastName() {
	return lastName;
}

void Patron::addHistory(Interact& interact) {
	if (interactHistoryHead == NULL) {
		InteractNode *current = new InteractNode();
		current->interact = &interact;
		interactHistoryHead = current;
		current = nullptr;
	}
	else {
		InteractNode* mostRecent = new InteractNode;
		mostRecent->interact = &interact;
		mostRecent->next = interactHistoryHead;
		interactHistoryHead = mostRecent;
		mostRecent = nullptr;
	}
}

void Patron::printHistory() {
	bool noHistory = true;
	cout << "*** Patron ID = " << ID
		<< " " << lastName
		<< " " << firstName << endl;
	InteractNode* current = interactHistoryHead;
	while (current != NULL) {
		noHistory = false;
		cout.setf(ios::left);
		cout.width(15);
		cout << current->interact->getName();
		current->interact->getAssociatedResource()->printInfo();
		current = current->next;
	}
	if (noHistory) {
		cout << "No history available" << endl;
	}
	cout << endl;
}

void Patron::deleteHistory(InteractNode* current) {
	if (current == nullptr) {
		return;
	}
	else {
		if (current->next != nullptr) {
			delete current->next;
			current->next = nullptr;
			return;
		}
	}
}

Patron::~Patron()
{
	deleteHistory(interactHistoryHead);
	if (interactHistoryHead != nullptr) {
		delete interactHistoryHead;
		interactHistoryHead = nullptr;
	}
}
