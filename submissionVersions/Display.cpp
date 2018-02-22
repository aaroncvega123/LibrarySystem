//#include "stdafx.h"
#include "Display.h"

#include "PatronList.h"
#include "ResourceList.h"
#include <string>

Display::Display()
{
	interactName = "Display";
}

istream& Display::getInput(istream& is){
	for (int i = 0; i < 26; i++) {
		ResourceNode* current = rListPtr->getResourceNode(i, 0);
		if (current->resource != NULL) {
			current->resource->printInfo();
			current = current->nextNode;

			DisplayNode nodeArray[100];
			int arraySize = 0;

			while (true) {
				if (current == NULL || current->resource == NULL) {
					break;
				}
				bool isInArray = false;
				for (int j = 0; j < arraySize; j++) {
					if (nodeArray[j].resource == current->resource) {
						isInArray = true;
						if (current->resource->isAvailable()) {
							nodeArray[j].available++;
						}
					}
				}
				if (!isInArray) {
					nodeArray[arraySize].resource = current->resource;
					arraySize++;
					if (current->resource->isAvailable()) {
						nodeArray[arraySize].available++;
					}
				}
				current = current->nextNode;
			}
			for (int j = 0; j < arraySize; j++) {
				cout << nodeArray[j].available;
				nodeArray[j].resource->printInfo();
			}

			for (int j = 1; j < 223; j++) {
				current = rListPtr->getResourceNode(i, j);

				DisplayNode nodeArray[100];
				int arraySize = 0;

				while (true) {
					if (current == NULL || current->resource == NULL) {
						break;
					}
					bool isInArray = false;
					for (int k = 0; k < arraySize; k++) {
						if (*nodeArray[k].resource == *current->resource) {
							isInArray = true;
							if (current->resource->isAvailable()) {
								nodeArray[k].available += 1;
							}
						}
					}
					if (!isInArray) {
						nodeArray[arraySize].resource = current->resource;
						if (current->resource->isAvailable()) {
							nodeArray[arraySize].available += 1;
						}
						arraySize++;
					}
					current = current->nextNode;
				}
				for (int k = 0; k < arraySize; k++) {
					cout.setf(ios::left);
					cout.width(7);
					cout << nodeArray[k].available;
					nodeArray[k].resource->printInfo();
				}

			}
			cout << endl;
		}
	}
	string dummy;
	getline(is, dummy);
	return is;
}

Display::~Display()
{
}
