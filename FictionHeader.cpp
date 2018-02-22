#include "stdafx.h"
#include "FictionHeader.h"


FictionHeader::FictionHeader()
{
}

void FictionHeader::printInfo() {
	cout << "Fiction:" << endl;
	cout.setf(ios::left);
	cout.width(7);
	cout << "AVAIL";
	cout.width(20);
	cout << "AUTHOR";
	cout.width(35);
	cout << "TITLE";
	cout.width(15);
	cout << "YEAR" << endl;
}

FictionHeader::~FictionHeader()
{
}
