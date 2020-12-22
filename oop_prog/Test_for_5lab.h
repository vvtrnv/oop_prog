#pragma once
#include <iostream>
#include <ctime>
#include "MyList.h"
#include "Complex.h"
#include "cDate.h"

using namespace std;

void compare(bool& st, const char* expected[], MyList& obj); // Сравнение результатов.
void fill_list(const int& len, Complex* arr[], MyList& obj); // Заполнение списка.

bool test1_push_back_and_index()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Тест функции push_back() и обращения по индексу[]" << endl;
	const int len = 5;
	bool status = true;

	time_t now = time(NULL);
	char tme[30];
	ctime_s(tme, 30, &now);

	Complex* arr[len]
	{
	new Complex(122, 55),
	new Complex(133, 66),
	new cDate(144, 77),
	new cDate(155, 88),
	new AnotherRep(166, 88)
	};

	const char* expected[len]
	{
		"(122.000000 + 55.000000 i)",
		"(133.000000 + 66.000000 i)",
		tme,
		tme,
		"187.882942 * [cos(0.487453) + i*sin(0.487453)]"
	};

	MyList objects;
	fill_list(len, arr, objects);

	cout << "Размер списка = " << objects.get_Size() << endl << endl;

	compare(status, expected, objects);


	return status;
}

bool test2_push_front_and_clear()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Тест функции push_front() и clear()" << endl;
	const int len = 5;
	bool status = true;

	time_t now = time(NULL);
	char tme[30];
	ctime_s(tme, 30, &now);

	Complex* arr[len]
	{
	new Complex(122, 55),
	new Complex(133, 66),
	new cDate(144, 77),
	new cDate(155, 88),
	new AnotherRep(166, 88)
	};

	const char* expected[len]
	{
		"187.882942 * [cos(0.487453) + i*sin(0.487453)]",
		tme,
		tme,
		"(133.000000 + 66.000000 i)",
		"(122.000000 + 55.000000 i)",
	};

	MyList objects;
	for (int i = 0; i < len; i++)
	{
		objects.push_front(arr[i]);
	}

	cout << "Размер списка = " << objects.get_Size() << endl;

	compare(status, expected, objects);

	cout << "\n~~Вызов функции clear():\n";
	objects.clear();
	cout << "Размер списка = " << objects.get_Size() << endl << endl;


	return status;
}

bool test3_insert_and_print_all()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Тест функции insert() и print_all()" << endl;
	const int len = 5;
	bool status = true;

	time_t now = time(NULL);
	char tme[30];
	ctime_s(tme, 30, &now);

	Complex* arr[len]
	{
	new Complex(122, 55),
	new Complex(133, 66),
	new cDate(144, 77),
	new cDate(155, 88),
	new AnotherRep(166, 88)
	};

	Complex* toAdd = new AnotherRep(199.215, 11);

	const char* expected[len + 1]
	{
		"(122.000000 + 55.000000 i)",
		"(133.000000 + 66.000000 i)",
		tme,
		"199.518461 * [cos(0.055161) + i*sin(0.055161)]",
		tme,
		"187.882942 * [cos(0.487453) + i*sin(0.487453)]"
	};

	MyList objects;
	fill_list(len, arr, objects);
	objects.print_all(cout);

	cout << "\n~~Вызов функции insert() - Добавление по индексу 3\n";
	objects.insert(toAdd, 3);
	
	compare(status, expected, objects);


	return status;
}

bool test4_removeAt_and_pop_back_and_pop_front()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Тест функции removeAt(), pop_front() и pop_back()" << endl;
	const int len = 7;
	bool status = true;

	time_t now = time(NULL);
	char tme[30];
	ctime_s(tme, 30, &now);

	Complex* arr[len]
	{
	new Complex(122, 55),//
	new Complex(133, 66),
	new cDate(144, 77),
	new cDate(155, 88),
	new AnotherRep(166, 88),//
	new AnotherRep(9912, 6126),
	new Complex(1516, 1166)//
	};

	const char* expected[len - 3]
	{
		"(133.000000 + 66.000000 i)",
		tme,
		tme,
		"11652.279605 * [cos(0.553578) + i*sin(0.553578)]",
	};

	MyList objects;
	fill_list(len, arr, objects);
	
	cout << "\n~~Изначальный список:\n";
	objects.print_all(cout);

	cout << "\n~~Вызов функции removeAt() - удаление по индексу 4\n";
	objects.removeAt(4);
	objects.print_all(cout);

	cout << "\n~~Вызов функции pop_front() - удаление первого узла\n";
	objects.pop_front();
	objects.print_all(cout);

	cout << "\n~~Вызов функции pop_back - удаление последнего узла\n\n";
	objects.pop_back();

	compare(status, expected, objects);


	return status;
}

bool test5_polymorphism()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Тест функции to_String() при полиморфизме" << endl;
	const int len = 7;
	bool status = true;

	time_t now = time(NULL);
	char tme[30];
	ctime_s(tme, 30, &now);

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

	const char* expected[len]
	{
		"(122.000000 + 55.000000 i)",
		"(133.000000 + 66.000000 i)",
		tme,
		tme,
		"187.882942 * [cos(0.487453) + i*sin(0.487453)]",
		"11652.279605 * [cos(0.553578) + i*sin(0.553578)]",
		"(1516.000000 + 1166.000000 i)"
	};

	MyList objects;
	fill_list(len, arr, objects);
	
	compare(status, expected, objects);


	return status;
}


// Функция сравнения результата с ожидаемым.
void compare(bool& st, const char* expected[], MyList& obj)
{
	for (int i = 0; i < obj.get_Size(); i++)
	{
		cout << "Ожидаемое значение:\t" << expected[i] << endl;
		cout << "Реальное значение:\t" << obj[i]->to_String() << endl << endl;

		if (strcmp(expected[i], obj[i]->to_String()) != 0) st = false;
	}
}

// Заполнение списка.
void fill_list(const int& len, Complex* arr[], MyList& obj)
{
	for (int i = 0; i < len; i++)
	{
		obj.push_back(arr[i]);
	}
}