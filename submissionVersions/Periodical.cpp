//#include "stdafx.h"
#include "Periodical.h"


Periodical::Periodical()
{
	genre = 'P';
}

istream& operator>>(istream& is, Periodical& P) {
	while (true) {
		string tempTitle;
		is >> tempTitle;
		P.title += tempTitle;
		if (P.title.back() = ',') {
			break;
		}
		P.title += " ";
	}
	is >> P.month;
	is >> P.year;
	return is;
}

istream& Periodical::getInput(istream& is) {
	while (true) {
		string tempTitle;
		is >> tempTitle;
		title += tempTitle;
		if (title.back() == ',') {
			break;
		}
		title += " ";
	}
	is >> month;
	is >> year;
	return is;
}

int Periodical::hash() const{
	int hash = 0;
	hash += format;
	hash += year;
	hash += month;
	for (unsigned int i = 0; i < title.length(); i++) {
		hash += title[i];
	}
	return hash;
}

bool Periodical::operator==(const Resource& other) const {
	const Periodical& p = (const Periodical&)other;
	if (month == p.month && year == p.year && title == p.title) {
		return true;
	}
	return false;
}

istream& Periodical::setSearchData(istream& is) {
	is >> format;
	is >> year;
	is >> month;
	while (true) {
		string tempTitle;
		is >> tempTitle;
		title += tempTitle;
		if (title.back() == ',') {
			break;
		}
		title += " ";
	}
	return is;
}

void Periodical::printInfo() {
	cout.setf(ios::left);
	cout.width(7);
	cout << year;
	cout.width(7);
	cout << month;
	cout << title << endl;
}

Periodical::~Periodical()
{
}
