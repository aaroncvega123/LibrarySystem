#pragma once
#include "CheckOutItem.h"
class Publication :
	public CheckOutItem
{
public:
	Publication();
	~Publication();

private:
	string title = "";
};

