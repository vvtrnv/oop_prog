#pragma once
#include <iostream>
#include "AnotherRep.h"
#include "cDate.h"

using namespace std;

//bool compareRes(AnotherRep obj, const char* expectation)
//{
//
//}

void Lab4_test1()
{
	// Тестируем класс наследник AnotherRep: создание объектов.
	cout << "TEST1 - CREATE OBJECTS" << endl;
	AnotherRep first(3, -3);
	cout << first.get_strTrig() << endl;
	cout << first.get_strExp();


}

void Lab4_test2()
{
	cDate a;
	cout << a.get_dateCreate();
}