#pragma once
#include <iostream>
#include "Translation.h"

using namespace std;

void Test1()
{
	Translation first(1,2);
	first.double_toStr();
	cout << "expression = " << first.to_String() << endl;
	cout << "strRepresent = " << first.get_strRepresent() << endl;
}