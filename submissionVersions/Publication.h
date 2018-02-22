#include "Resource.h"
#include <string>
#pragma once

using namespace std;

class Publication : public Resource
{
public:
	Publication();
	~Publication();
	virtual int hash() { return 0; };

	void setTitle(string newTitle) { title = newTitle; };
	void setYear(int newYear) { year = newYear; };

protected:
	string title;
	int year;
	char format = 'H';
	char genre = ' ';
private:

};

