#pragma once
#include <iostream>
#include "MyList.h"
#include "Complex.h"
#include "cDate.h"

using namespace std;

void test1_push_back_and_index()
{
	MyList lst;
	lst.push_back(1, 2);
	lst.push_back(3, 4);
	lst.push_back(1.6, 11);
	lst.push_back(66, 22);

	for (int i = 0; i < lst.get_Size(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << "Размер: " << lst.get_Size() << endl;

	cout << "Выполняю clear()" << endl;
	lst.clear();

	cout << "Размер: " << lst.get_Size() << endl;
}
