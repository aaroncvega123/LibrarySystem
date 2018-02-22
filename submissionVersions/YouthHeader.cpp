//#include "stdafx.h"
#include "YouthHeader.h"


YouthHeader::YouthHeader()
{
}

void YouthHeader::printInfo() {
	cout << "YOUTH:" << endl;
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

YouthHeader::~YouthHeader()
{
}
