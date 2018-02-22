#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Interact;
class Resource;

struct InteractNode{
	Interact *interact = NULL;
	InteractNode *next = NULL;
};

class Patron
{
public:
	Patron();
	~Patron();
	friend istream& operator>>(istream& is, Patron& P);

	int getID();
	string getFirstName();
	string getLastName();

	void addHistory(Interact& interact);
	void printHistory();
private:
	int ID;
	string firstName;
	string lastName;
	int interactHistorySize = 0;
	InteractNode* interactHistoryHead = NULL;
};

