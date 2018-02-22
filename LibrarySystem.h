//---------------------------------------------------------------------------
// LibrarySystem.h
// Represents an entire library system
// Author:  Aaron Vega
//---------------------------------------------------------------------------
// LibrarySystem class: For creating and managing a library syste,
//   -- Allows for storing and organizing check out items
//   -- Allows for storing info on patrons
//   -- Allows for storing info on libraries in system
//   -- Allows 
//
// Implementation and assumptions:
//   -- All nodes use string for data in NodeData
//   -- Input file formatted correctly
//---------------------------------------------------------------------------
#pragma once
#include "Entity.h"
#include "CheckOutItem.h"
#include "Function.h"

class LibrarySystem
{
public:
	LibrarySystem();
	~LibrarySystem();

	void addEntity(Entity newEntity);
	void addItem(CheckOutItem newItem);
	void removeEntity(Entity removable);
	void removeItem(CheckOutItem removable);

	//Still needs factory
	void runFunction(char choice);

private:
	Entity *entityList = new Entity[100];
	CheckOutItem *itemList = new CheckOutItem[100];
	Function *functionList = new Function[100];
};

