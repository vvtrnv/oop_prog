﻿#include <iostream>
#include <stdio.h>
#include "Complex.h"

#include "Test_for_1lab.h"
#include "Test_for_3lab.h"
#include "Test_for_4lab.h"
#include "Test_for_5lab.h"
#include "Test_for_8lab.h"
#include "Test_for_6lab.h"
#include "Test_for_7lab.h"

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
	
	/*if (test1_push_back_and_index()) cout << "Тест #1 пройден!\n\n\n";
	else cout << "Ошибка. Тест #1 не пройден!\n\n\n";

	if (test2_push_front_and_clear()) cout << "Тест #2 пройден!\n\n\n";
	else cout << "Ошибка. Тест #2 не пройден!\n\n\n";
	
	if (test3_insert_and_print_all()) cout << "Тест #3 пройден!\n\n\n";
	else cout << "Ошибка. Тест #3 не пройден!\n\n\n";

	if (test4_removeAt_and_pop_back_and_pop_front()) cout << "Тест #4 пройден!\n\n\n";
	else cout << "Ошибка. Тест #4 не пройден!\n\n\n";

	if (test5_polymorphism()) cout << "Тест #5 пройден!\n\n\n";
	else cout << "Ошибка. Тест #5 не пройден!\n\n\n";*/



	// Лабораторная работа № 8. Тесты.
	//try
	//{
	//	if (test1_stack_int()) cout << "stack empty!" << endl;
	//	else
	//		throw exception("stack is not empty!!!");
	//}
	//catch (const exception& ex)
	//{
	//	cout << ex.what() << endl;
	//}


	//try
	//{
	//	if (test2_stack_complex()) cout << "stack empty!" << endl;
	//	else
	//		throw exception("stack is not empty!!");
	//}
	//catch (const exception& ex)
	//{
	//	cout << ex.what() << endl;
	//}

	//try
	//{
	//	if (test3_multiset_int()) cout << "multiset empty!" << endl;
	//	else
	//		throw exception("multiset is not empty!!");
	//}
	//catch (const exception& ex)
	//{
	//	cout << ex.what() << endl;
	//}


	//try
	//{
	//	if (test4_multiset_complex()) cout << "multiset empty!" << endl;
	//	else
	//		throw exception("multiset is not empty!!");
	//}
	//catch (const exception& ex)
	//{
	//	cout << ex.what() << endl;
	//}


	// Лабораторная работа №6. Тесты.
	//try
	//{
	//	if (test_divide())
	//		cout << "~~Test1 completed successfully!" << endl;
	//	else
	//		throw exception("~~Test1 failed!!!");
	//}
	//catch (const exception& ex)
	//{
	//	cout << ex.what() << endl;
	//}

	//test_compare_with();
	//test_pop_front_back();
	//test_insert();
	//test_removeAt();
	//test_index();
	//test_print_empty_list();


	// Лабароторная работа №7. Тесты.
	//lab7_test_1_1_INT(); // Добавление и вывод на экран для INT.
	lab7_test_1_2_INT(); // Удаление первого и последнего элемента для INT.
	//lab7_test_1_3_INT(); // Заполнение с помощью push_front() и вставка элемента для INT.
	//lab7_test_1_4_INT(); // Удаление по индексу для INT.

	//lab7_test_2_1_COMPLEX(); // Добавление и вывод на экран для COMPLEX.
	//lab7_test_2_2_COMPLEX(); // Удаление первого и последнего элемента для COMPLEX.
	//lab7_test_2_3_COMPLEX(); // Заполнение с помощью push_front() и вставка элемента для COMPLEX.
	//lab7_test_2_4_COMPLEX(); // Удаление по индексу для COMPLEX.

	cin.get();
	return 0;
}