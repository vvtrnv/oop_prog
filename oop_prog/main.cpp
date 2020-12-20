#include <iostream>
#include <stdio.h>
#include "Complex.h"

#include "Test_for_1lab.h"
#include "Test_for_3lab.h"
#include "Test_for_4lab.h"
#include "Test_for_5lab.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	// Лабораторная работа №1.Тесты.
	//bool result = true;
	//Lab1_test1(result);
	//Lab1_test2(result);
	//Lab1_test3(result);
	//Lab1_test4(result);
	//Lab1_test5(result);

	// Лабораторная работа №3.Тесты.
	//Lab3_test1(); cout << "~Test#1 Successfully!\n\n";
	//if (Lab3_test2())cout << "~Test #2 Successfully!\n\n";
	//else cout << "Error in test#2\n\n";
	//if (Lab3_test3())cout << "~Test #3 Successfully!\n\n";
	//else cout << "Error in test#3\n\n";
	
	// Лабораторная работа №4.Тесты.
	//Lab4_test_1();
	//Lab4_test_2();
	//Lab4_test_3();
	//Lab4_test_4();

	// Лабораторная работа №5.Тесты.
	
	//test1_push_back_and_index();
	//test2_push_front_and_clear();
	//test3_insert_and_print_all();
	//test4_removeAt_and_pop_back_and_pop_front();
	test5_polymorphism();

	cin.get();
	return 0;
}