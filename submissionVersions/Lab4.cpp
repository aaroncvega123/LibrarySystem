// Lab4.cpp : Defines the entry point for the console application.
//
////#include "stdafx.h"
#include "Youth.h"
#include "Fiction.h"
#include "Resource.h"
#include "Publication.h"
#include "ResourceList.h"
#include "Patron.h"
#include "PatronList.h"
#include <iostream>
#include <fstream>
#include "LibrarySystem.h"
//#include "Interact.h"
//#include "checkOut.h"
//#include "Display.h"
using namespace std;

int main()
{
	LibrarySystem lib;
	ifstream bookFile("data4books.txt");
	ifstream patronFile("data4patrons.txt");
	ifstream commandFile("data4commands.txt");
	lib.populateResourceList(bookFile);
	lib.populatePatronList(patronFile);
	lib.setCommandsFromFile(commandFile);
	system("PAUSE");
}

