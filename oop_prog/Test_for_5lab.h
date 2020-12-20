#pragma once
#include <iostream>
#include "MyList.h"
#include "Complex.h"
#include "cDate.h"

using namespace std;
void test1_push_back_and_index()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~���� ������� push_back() � ��������� �� �������[]" << endl;
	const int len = 5;
	bool status = true;

	Complex* arr[len]
	{
	new Complex(122, 55),
	new Complex(133, 66),
	new cDate(144, 77),
	new cDate(155, 88),
	new AnotherRep(166, 88)
	};

	MyList objects;
	for (int i = 0; i < len; i++) // ���������� ������
	{
		objects.push_back(arr[i]);
	}

	for (int i = 0; i < objects.get_Size(); i++)
	{
		cout << i << ") " << objects[i]->to_String() << endl;
	}
	cout << "������ ������ = " << objects.get_Size() << endl << endl;
}

void test2_push_front_and_clear()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~���� ������� push_front() � clear()" << endl;
	const int len = 5;

	Complex* arr[len]
	{
	new Complex(122, 55),
	new Complex(133, 66),
	new cDate(144, 77),
	new cDate(155, 88),
	new AnotherRep(166, 88)
	};

	MyList objects;
	for (int i = 0; i < len; i++) // ���������� ������
	{
		objects.push_front(arr[i]);
	}

	for (int i = 0; i < objects.get_Size(); i++)
	{
		cout << i << ") " << objects[i]->to_String() << endl;
	}
	cout << "������ ������ = " << objects.get_Size() << endl;

	cout << "\n~~����� ������� clear():\n";
	objects.clear();
	cout << "������ ������ = " << objects.get_Size() << endl << endl;
}

void test3_insert_and_print_all()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~���� ������� insert() � print_all()" << endl;
	const int len = 5;

	Complex* arr[len]
	{
	new Complex(122, 55),
	new Complex(133, 66),
	new cDate(144, 77),
	new cDate(155, 88),
	new AnotherRep(166, 88)
	};

	Complex* toAdd = new AnotherRep(199.215, 11);

	MyList objects;
	for (int i = 0; i < len; i++) // ���������� ������
	{
		objects.push_back(arr[i]);
	}

	objects.print_all(cout);
	cout << "\n~~����� ������� insert() - ���������� �� ������� 3\n";
	objects.insert(toAdd, 3);
	objects.print_all(cout);
}

void test4_removeAt_and_pop_back_and_pop_front()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~���� ������� removeAt(), pop_front() � pop_back()" << endl;
	const int len = 7;

	Complex* arr[len]
	{
	new Complex(122, 55),
	new Complex(133, 66),
	new cDate(144, 77),
	new cDate(155, 88),
	new AnotherRep(166, 88),
	new AnotherRep(9912, 6126),
	new Complex(1516, 1166)
	};

	MyList objects;
	for (int i = 0; i < len; i++) // ���������� ������
	{
		objects.push_back(arr[i]);
	}

	objects.print_all(cout);

	cout << "\n~~����� ������� removeAt() - �������� �� ������� 4\n";
	objects.removeAt(4);
	objects.print_all(cout);

	cout << "\n~~����� ������� pop_front() - �������� ������� ����\n";
	objects.pop_front();
	objects.print_all(cout);

	cout << "\n~~����� ������� pop_back - �������� ���������� ����\n";
	objects.pop_back();
	objects.print_all(cout);
}

void test5_polymorphism()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~���� ������� to_String() ��� ������������" << endl;
	const int len = 7;

	Complex* arr[len]
	{
	new Complex(122, 55),
	new Complex(133, 66),
	new cDate(144, 77),
	new cDate(155, 88),
	new AnotherRep(166, 88),
	new AnotherRep(9912, 6126),
	new Complex(1516, 1166)
	};

	for (int i = 0; i < len; i++)
	{
		cout << arr[i]->to_String() << endl;
	}
}