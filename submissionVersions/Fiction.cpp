//#include "stdafx.h"
#include "Fiction.h"


Fiction::Fiction()
{
	genre = 'F';
}

istream& operator>>(istream& is, Fiction& F) {
	is >> F.authorLastName;

	while (true) {
		string firstName;
		is >> firstName;
		F.authorFirstName += firstName;
		if (F.authorFirstName.back() == ',') {
			break;
		}
		F.authorFirstName += " ";
	}

	while (true) {
		string tempTitle;
		is >> tempTitle;
		F.title += tempTitle;
		if (F.title.back() == ',') {
			break;
		}
		F.title += " ";
	}
	is >> F.year;
	return is;
}

istream& Fiction::getInput(istream& is) {
	is >> authorLastName;

	while (true) {
		string firstName;
		is >> firstName;
		authorFirstName += firstName;
		if (authorFirstName.back() == ',') {
			break;
		}
		authorFirstName += " ";
	}

	while (true) {
		string tempTitle;
		is >> tempTitle;
		title += tempTitle;
		if (title.back() == ',') {
			break;
		}
		title += " ";
	}
	is >> year;
	return is;
}

int Fiction::hash() const{
	int hash = 0;
	hash += format;
	string bookInfo = authorFirstName + authorLastName + title;
	for (unsigned int i = 0; i < bookInfo.length(); i++) {
		hash += bookInfo[i];
	}
	return hash;
}

bool Fiction::operator==(const Resource& other) const{
	const Fiction& f = (const Fiction&)other;
	if (title == f.title && authorFirstName == f.authorFirstName
		&& authorLastName == f.authorLastName && format == f.format) {
		return true;
	}
	return false;
}

bool Fiction::equals(const Resource& other) const {
	const Fiction& f = (const Fiction&)other;
	if (title == f.title && authorFirstName == f.authorFirstName
		&& authorLastName == f.authorLastName && format == f.format) {
		return true;
	}
	return false;
}

istream& Fiction::setSearchData(istream& is) {
	is >> format;
	is >> authorLastName;
	while (true) {
		string firstName;
		is >> firstName;
		authorFirstName += firstName;
		if (authorFirstName.back() == ',') {
			break;
		}
		authorFirstName += " ";
	}
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

void Fiction::printInfo() {
	cout.setf(ios::left);
	cout.width(20);
	string name = authorLastName + " " + authorFirstName;
	if (name.length() > 15) {
		cout << name.substr(0, 15) + "...";
	}
	else {
		cout << name;
	}
	cout.width(35);
	if (title.length() > 30) {
		cout << title.substr(0, 30) + "...";
	}
	else {
		cout << title;
	}
	cout.width(15);
	cout << year << endl;
}

Fiction::~Fiction()
{
}
