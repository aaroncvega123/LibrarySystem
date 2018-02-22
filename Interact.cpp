#include "stdafx.h"
#include "Interact.h"

#include "PatronList.h"
#include "ResourceList.h"
//#include "Display.h";

Interact::Interact()
{
	//cout << "Hello" << endl;
}


void Interact::run() {

}

void Interact::usePatronList(PatronList* pList) {
	pListPtr = pList;
}

void Interact::useResourceList(ResourceList* rList) {
	rListPtr = rList;
}

Interact::~Interact()
{
}
