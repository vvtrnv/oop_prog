#pragma once
#include "Complex.h"
#include "MyList.h"

bool test_divide()
{
	cout << "~~~~~~~~~Test1. Division by zero~~~~~~~~~" << endl;
	bool status = true;
	Complex A1(11, 11);
	Complex A2(0, 0);
	Complex res;
	
	res.divide(A1,A2);

	if ((res.get_Valid() + res.get_Image()) != 0)
		return false;
	return status;
}

void test_compare_with()
{
	cout << "~~~~~~~~~Test2. Compare with value~~~~~~~~~" << endl;
	Complex A(14, 16);
	A.compare_with(15, 16);
}

void test_pop_front_back()
{
	cout << "~~~~~~~~~Test3. Removing the first item from an empty list~~~~~~~~~" << endl;
	MyList lst;
	cout << "pop_front():" << endl;
	lst.pop_front();
	cout << "pop_back():" << endl;
	lst.pop_back();
}

void test_insert()
{
	cout << "~~~~~~~~~Test4. Going beyond the list size~~~~~~~~~" << endl;
	MyList lst;
	const int SZ = 3;
	Complex* arr[SZ]
	{
		new Complex(1,2),
		new Complex(155,23.11),
		new Complex(199,32)
	};
	Complex* toAdd = new Complex(166, 22);

	for (int i = 0; i < SZ; i++)
	{
		lst.push_back(arr[i]);
	}

	lst.insert(toAdd, 10);
}

void test_removeAt()
{
	cout << "~~~~~~~~~Test5. Deleting a nonexistent element~~~~~~~~~" << endl;
	MyList lst;
	const int SZ = 3;
	Complex* arr[SZ]
	{
		new Complex(1,2),
		new Complex(155,23.11),
		new Complex(199,32)
	};
	Complex* toAdd = new Complex(166, 22);

	for (int i = 0; i < SZ; i++)
	{
		lst.push_back(arr[i]);
	}

	lst.removeAt(7);
}

void test_index()
{
	cout << "~~~~~~~~~Test6. Accessing a nonexistent element~~~~~~~~~" << endl;
	MyList lst;
	const int SZ = 3;
	Complex* arr[SZ]
	{
		new Complex(1,2),
		new Complex(155,23.11),
		new Complex(199,32)
	};
	Complex* toAdd = new Complex(166, 22);

	for (int i = 0; i < SZ; i++)
	{
		lst.push_back(arr[i]);
	}

	lst[7];
}

void test_print_empty_list()
{
	cout << "~~~~~~~~~Test7. Print empty list~~~~~~~~~" << endl;
	MyList lst;
	lst.print_all(cout);
}