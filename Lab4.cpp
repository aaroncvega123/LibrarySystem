// Lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	cinTest();
    return 0;
}

void cinTest() {
	cout << "Enter Numbers" << endl;
	int i = 10;
	while (i != 0){
		cin >> i;
		cout << i << endl;
	}
}