﻿#include <iostream>
#include <stdio.h>
#include "Complex.h"

#include "Test_for_1lab.h"
#include "Test_for_3lab.h"

using namespace std;

int main()
{
	// Лабораторная работа №1.Тесты.
	//bool result = true;
	//Lab1_test1(result);
	//Lab1_test2(result);
	//Lab1_test3(result);
	//Lab1_test4(result);
	//Lab1_test5(result);

	// Лабораторная работа №3.Тесты.
	Lab3_test1(); cout << "~Test#1 Successfully!\n\n";

	if (Lab3_test2())cout << "~Test #2 Successfully!\n\n";
	else cout << "Error in test#2\n\n";

	if (Lab3_test3())cout << "~Test #3 Successfully!\n\n";
	else cout << "Error in test#3\n\n";
	

	cin.get();
	return 0;
}