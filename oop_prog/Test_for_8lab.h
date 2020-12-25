#pragma once
#include <iostream>
#include <ctime>
#include <stack>
#include <set>
#include <iterator>
#include "Complex.h"

using namespace std;

bool test1_stack_int()
{
	srand(time(NULL));
	cout << "~~~~~~~~~~STACK TEST:\n~~~~~~~~stack <int>~~~~~~~~~~\n";
	cout << "1. Stack fill" << endl;
	stack<int> typeInt;
	stack<int> typeInt_toDelete;
	int len = 100000;
	bool status = true;
	bool srch = false;
	const int search = 199;


	int before = clock();

	for (int i = 0; i < len; i++)
	{
		typeInt.push(rand());
	}
	cout << "Time fill stack:\t" << clock() - before << " ms" << endl;

	cout << "2. Stack find:" << endl;
	before = clock();

	for (int i = 0; i < typeInt.size() && srch == false; i++)
	{
		if (typeInt.top() == search)
		{
			cout << "Element is found!" << endl;
			srch = true;
		}

		typeInt.pop();
	}
	if (!srch) cout << "Element is not found! :(" << endl;

	cout << "Time find stack:\t" << clock() - before << " ms" << endl;

	// Очищаем оставшиеся элементы чтобы на новом стеке проверить удаление 100000 элементов.
	while (!typeInt.empty())
	{
		typeInt.pop();
	}

	for (int i = 0; i < len; i++)
	{
		typeInt_toDelete.push(rand());
	}
	cout << "3. Delete stack:" << endl;
	before = clock();
	while (!typeInt_toDelete.empty())
	{
		typeInt_toDelete.pop();
	}
	cout << "Time delete stack:\t" << clock() - before << " ms" << endl;


	if (!typeInt_toDelete.empty()) status = false;


	return status;
}

bool test2_stack_complex()
{
	cout << "~~~~~~~~~~stack <Complex>~~~~~~~~~~\n";
	stack<Complex> typeComplex;
	stack<Complex> typeComplex_toDelete;
	int len = 100000;
	bool status = true;
	bool srch = false;
	Complex search(122, 55);

	cout << "1. Stack push():" << endl;
	int before = clock();
	for (int i = 0; i < len; i++)
	{
		Complex num(rand() % 100, rand() % 100);
		typeComplex.push(num);
	}
	cout << "Time push() stack:\t" << clock() - before << " ms" << endl;

	cout << "2. Stack find:" << endl;
	before = clock();

	for (int i = 0; i < typeComplex.size() && srch == false; i++)
	{
		if (typeComplex.top() == search)
		{
			cout << "Element is found!" << endl;
			srch = true;
		}

		typeComplex.pop();
	}
	if (!srch) cout << "Element is not found! :(" << endl;

	cout << "Time find stack:\t" << clock() - before << " ms" << endl;

	while (!typeComplex.empty())
	{
		typeComplex.pop();
	}

	for (int i = 0; i < len; i++)
	{
		Complex num(rand() % 100, rand() % 100);
		typeComplex_toDelete.push(num);
	}

	cout << "3. Stack pop():" << endl;
	before = clock();
	while (!typeComplex_toDelete.empty())
	{
		typeComplex_toDelete.pop();
	}
	cout << "Time delete stack:\t" << clock() - before << " ms" << endl;

	if (!typeComplex_toDelete.empty()) status = false;


	return status;
}

bool test3_multiset_int()
{
	cout << "~~~~~~~~~~MULTISET TEST:" << endl;
	cout << "~~~~~~~~~~multiset <int>~~~~~~~~~~" << endl;
	multiset <int> typeInt;
	bool status = true;
	const int len = 100000;
	cout << "1. Multiset insert:" << endl;
	int before = clock();
	for (int i = 0; i < len; i++) {
		typeInt.insert(rand());
	}
	cout << "Time insert multiset:\t" << clock() - before << " ms" << endl;


	cout << "2. Multiset find:" << endl;
	before = clock();
	multiset<int>::const_iterator resultInt = typeInt.find(1000);
	try
	{
		if (resultInt == typeInt.end())
			throw exception("Element doesn`t find :(\n");

	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
	cout << "Time find multiset:\t" << clock() - before << " ms" << endl;


	cout << "3. Multiset delete" << endl;
	before = clock();
	typeInt.erase(typeInt.begin(), typeInt.end());
	cout << "Time delete multiset:\t" << clock() - before << " ms" << endl;

	if (!typeInt.empty()) status = false;

	return status;
}

bool test4_multiset_complex()
{
	cout << "~~~~~~~~~~MULTISET TEST:" << endl;
	cout << "~~~~~~~~~~multiset <Complex>~~~~~~~~~~" << endl;
	multiset <Complex> typeComplex;
	bool status = true;
	const int len = 100000;
	cout << "1. Multiset insert:" << endl;
	int before = clock();
	for (int i = 0; i < len; i++)
	{
		Complex num(rand() % 100, rand() % 100);
		typeComplex.insert(num);
	}
	cout << "Time insert multiset:\t" << clock() - before << " ms" << endl;


	cout << "2. Multiset find:" << endl;
	before = clock();
	Complex search(122, 66);
	multiset<Complex>::const_iterator resultInt = typeComplex.find(search);
	try
	{
		if (resultInt == typeComplex.end())
			throw exception("Element doesn`t find :(\n");

	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
	cout << "Time find multiset:\t" << clock() - before << " ms" << endl;


	cout << "3. Multiset delete" << endl;
	before = clock();
	typeComplex.erase(typeComplex.begin(), typeComplex.end());
	cout << "Time delete multiset:\t" << clock() - before << " ms" << endl;

	if (!typeComplex.empty()) status = false;

	return status;
}