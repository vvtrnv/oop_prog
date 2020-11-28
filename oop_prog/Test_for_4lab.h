#pragma once
#include <iostream>
#include "AnotherRep.h"
#include "cDate.h"

using namespace std;

bool compareRes(AnotherRep& obj, const double& r, const double& angle)
{
	const double EPS = 1e-3;
	if (abs(obj.get_R() - r) < EPS && abs(obj.get_Angle() - angle) < EPS) return true;
	else return false;
}

void Lab4_test_1()
{
	// Тестируем класс наследник AnotherRep: создание объектов.
	cout << "~~~~~AnotherRep::TEST_1 - CREATE OBJECT WITH PARAMETERS" << endl;
	AnotherRep first(0, -3);
	cout << first.get_strTrig() << endl;
	cout << first.get_strExp() << endl;

	if (compareRes(first, 3, -1.57079)) cout << "THE RESULT MATCHED!\n";
	else cout << "!!!!THE RESULT DIDN`T MATCH\n";
	cout << "\n\n";
}

void Lab4_test_2()
{
	cout << "~~~~~AnotherRep::TEST_2 - CREATE OBJECT WITHOUT PARAMETERS" << endl;
	AnotherRep first;
	cout << first.get_strTrig() << endl;
	cout << first.get_strExp() << endl;

	cout << "SET PARAMETERS:\n";
	first.set_Valid(1);first.set_Image(521.14);
	first.convertAllForms();
	cout << first.get_strTrig() << endl;
	cout << first.get_strExp() << endl;

	if (compareRes(first, 521.14095, 1.56887)) cout << "THE RESULT MATCHED!\n";
	else cout << "!!!!THE RESULT DIDN`T MATCH\n";
	cout << "\n\n";
}

void Lab4_test_3()
{
	cout << "~~~~~cDate::TEST_3 - CREATE OBJECT WITH PARAMETERS" << endl;
	cDate first(141,24);
	cout << first.to_String() << endl;
	cout << first.get_dateCreate() << endl;
	cout << "\n\n";
}

void Lab4_test_4()
{
	cout << "~~~~~cDate::TEST_4 - CREATE OBJECT WITHOUT PARAMETERS" << endl;
	cDate first;
	cout << first.to_String() << endl;
	cout << first.get_dateCreate() << endl;

	cout << "SET PARAMETERS:\n";
	first.set_Valid(421.13); first.set_Image(-1312);
	cout << first.to_String() << endl;
	cout << first.get_dateCreate() << endl;
}