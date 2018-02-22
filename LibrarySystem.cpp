#include "stdafx.h"
#include "LibrarySystem.h"
//#include "Display.h"

LibrarySystem::LibrarySystem()
{
}

void LibrarySystem::populatePatronList(ifstream& infile) {
	patronList.populateList(infile);
}

void LibrarySystem::populateResourceList(ifstream& infile) {
	resourceList.populateList(infile);
}

void LibrarySystem::setCommandsFromFile(ifstream& infile) {
	InteractFactory iFactory;
	char interactChoice;
	while (!infile.eof()) {

		while (!infile.eof()) {
			infile >> interactChoice;
			if (!iFactory.isApprovedInput(interactChoice)) {
				cout << interactChoice << " is not a valid command" << endl;
				cout << endl;
				string dummy;
				getline(infile, dummy);

				break;
			}

			Interact* interaction = iFactory.produce(interactChoice);
	
			interaction->usePatronList(&patronList);
			interaction->useResourceList(&resourceList);
			interaction->getInput(infile);

			interaction = nullptr;

			break;
		}
		if (infile.eof()) {
			break;
		}
	}

}

LibrarySystem::~LibrarySystem()
{
	
}
