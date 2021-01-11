#pragma once
#include <iostream>
#include "Complex.h"
#include "templateList.h"

void lab7_test1_int()
{
	// Добавление элементов и вывод на экран.
	templateList<int> typeInt;
	const int SIZE = 5;
	for (int i = 0; i < SIZE; i++)
	{
		typeInt.push_back(i + 1);
	}

	for (int i = 0; i < SIZE; i++)
	{
		cout << typeInt[i] << "\t";
	}
	cout << endl << endl;
}

void lab7_test2_Complex()
{
	templateList<Complex> typeComplex;
	const int SIZE = 2;

	Complex arr[2]
	{
		Complex(1,2),
		Complex(22,66)
	};

	for (int i = 0; i < SIZE; i++)
	{
		typeComplex.push_back(arr[i]);
	}

	for (int i = 0; i < SIZE; i++)
	{
		cout << typeComplex[i] << "\t";
	}


}