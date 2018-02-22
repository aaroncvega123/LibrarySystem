//#include "stdafx.h"
#include "PeriodicalHeader.h"


PeriodicalHeader::PeriodicalHeader()
{
}

void PeriodicalHeader::printInfo() {
	cout.setf(ios::left);
	cout << "PERIDOCAL:" << endl;
	cout.width(7);
	cout << "AVAIL";
	cout.width(7);
	cout << "YEAR";
	cout.width(7);
	cout << "MO";
	cout << "TITLE " << endl;
}

PeriodicalHeader::~PeriodicalHeader()
{
}
