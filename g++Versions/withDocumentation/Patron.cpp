//---------------------------------------------------------------------------
// Patron.cpp
// Class representing patron of library system
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// Resource class: Represents books of fiction
//   -- Allows for setting patron name
//   -- Allows for setting ID
//   -- Allows for viewing and storing interaction history
//
//  Assumptions:
//   -- Assumes middle name and birthday are not important
//---------------------------------------------------------------------------

//#include "stdafx.h"
#include "Patron.h"
#include "Interact.h"
#include "Resource.h"

//---------------------------------------------------------------------------
// Default constructor
// Pre: None
// Post: None
Patron::Patron()
{
}

//---------------------------------------------------------------------------
// operator>>
// Uses command line to set Patron attributes
// Pre: is is formatted correctly. No null inputs
// Post: Patron attributes set
istream& operator>>(istream& is, Patron& P) {
   is >> P.ID;
   is >> P.lastName;
   is >> P.firstName;
   return is;
}

//---------------------------------------------------------------------------
// getID
// Pre: None
// Post: ID of patron returned
int Patron::getID(){
   return ID;
}

//---------------------------------------------------------------------------
// getFirstName
// Pre: None
// Post: first name of patron returned
string Patron::getFirstName() {
   return firstName;
}

//---------------------------------------------------------------------------
// getLastName
// Pre: None
// Post: last name of patron returned
string Patron::getLastName() {
   return lastName;
}

//---------------------------------------------------------------------------
// addHistory
// Pre: None
// Post: Adds interact object used to interaction history list
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

//---------------------------------------------------------------------------
// printHistory
// Pre: None
// Post: Prints all interactions, starting from more recent
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

//---------------------------------------------------------------------------
// Deconstructor
// Pre: None
// Post: Deallocates all interactions
Patron::~Patron()
{
   deleteHistory(interactHistoryHead);
   if (interactHistoryHead != nullptr) {
      delete interactHistoryHead;
      interactHistoryHead = nullptr;
   }
}

//---------------------------------------------------------------------------
// deleteHistory
// Pre: Only used by deconstructor
// Post: Deallocates interact history recursively
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
