#pragma once
#include <iostream>
#include "Translation.h"

using namespace std;

void Test1()
{
	Translation a("1125125.11 + 5151515.2515i");
	cout << a.get_strRepresent() << endl;

}