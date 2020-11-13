#include "Complex.h"
#pragma once

void Lab1_test1(bool result)
{
	cout << "===================Test #1===================\n";

	// Создаём объекты комплексного числа.
	Complex ex1_test1(5, 4, "(5 + 4i)"); // Вызвался конструктор с параметрами.
	Complex ex2_test1(11, 7, "(11 + 7i)"); // Вызвался конструктор с параметрами.
	Complex res_test1; // Вызвался стандатртный конструктор.

	// Сложение.
	cout << "---Summation---\n";
	res_test1.summarize(ex1_test1, ex2_test1);
	cout << ex1_test1.getExpression(); cout << " + "; cout << ex2_test1.getExpression(); cout << " = ";
	res_test1.showResult();
	res_test1.compare_with(16, 11);

	// Вычитание.
	cout << "---Subtraction---\n";
	res_test1.subtract(ex1_test1, ex2_test1);
	cout << ex1_test1.getExpression(); cout << " - "; cout << ex2_test1.getExpression(); cout << " = ";
	res_test1.showResult();
	res_test1.compare_with(-6, -3);

	// Деление.
	cout << "---Division---\n";
	res_test1.divide(ex1_test1, ex2_test1);
	cout << ex1_test1.getExpression(); cout << " / "; cout << ex2_test1.getExpression(); cout << " = ";
	res_test1.showResult();
	res_test1.compare_with(0.48823, 0.0529);

	// Умножение.
	cout << "---Multiplication---\n";
	res_test1.multiply(ex1_test1, ex2_test1);
	cout << ex1_test1.getExpression(); cout << " * "; cout << ex2_test1.getExpression(); cout << " = ";
	res_test1.showResult();
	res_test1.compare_with(27, 79);

	// Сравнивание.
	cout << "---Comparison---\n";
	result = compare(ex1_test1, ex2_test1);
	if (result)
	{
		cout << ex1_test1.getExpression(); cout << " = "; cout << ex2_test1.getExpression(); cout << endl;
	}
	else
	{
		cout << ex1_test1.getExpression(); cout << " != "; cout << ex2_test1.getExpression(); cout << endl;
	}

	res_test1.showNumber();

} // вызвалось 3 деструктора для объектов: ex1_test1 ; ex2_test1 ; res_test1 . Память освобождена.

void Lab1_test2(bool result)
{
	cout << "\n===================Test #2===================\n";

	// Создаём объекты комплексного числа.
	Complex ex1_test2(2, 15, "(2 + 15i)"); // Вызвался конструктор с параметрами.
	Complex ex2_test2(17, 7, "(17 + 7i)"); // Вызвался конструктор с параметрами.
	Complex res_test2; // Вызвался стандартный конструктор.

	// Сложение.
	cout << "---Summation---\n";
	res_test2.summarize(ex1_test2, ex2_test2);
	cout << ex1_test2.getExpression(); cout << " + "; cout << ex2_test2.getExpression(); cout << " = ";
	res_test2.showResult();
	res_test2.compare_with(19, 22);

	// Вычитание.
	cout << "---Subtraction---\n";
	res_test2.subtract(ex1_test2, ex2_test2);
	cout << ex1_test2.getExpression(); cout << " - "; cout << ex2_test2.getExpression(); cout << " = ";
	res_test2.showResult();
	res_test2.compare_with(-15, 8);

	// Деление.
	cout << "---Division---\n";
	res_test2.divide(ex1_test2, ex2_test2);
	cout << ex1_test2.getExpression(); cout << " / "; cout << ex2_test2.getExpression(); cout << " = ";
	res_test2.showResult();
	res_test2.compare_with(0.411, 0.713);

	// Умножение.
	cout << "---Multiplication---\n";
	res_test2.multiply(ex1_test2, ex2_test2);
	cout << ex1_test2.getExpression(); cout << " * "; cout << ex2_test2.getExpression(); cout << " = ";
	res_test2.showResult();
	res_test2.compare_with(-71, 269);

	// Сравнивание.
	cout << "---Comparison---\n";
	result = compare(ex1_test2, ex2_test2);
	if (result)
	{
		cout << ex1_test2.getExpression(); cout << " = "; cout << ex2_test2.getExpression(); cout << endl;
	}
	else
	{
		cout << ex1_test2.getExpression(); cout << " != "; cout << ex2_test2.getExpression(); cout << endl;
	}

	res_test2.showNumber();
} // вызвалось 3 деструктора для объектов: ex1_test2 ; ex2_test2 ; res_test2 . Память освобождена.

void Lab1_test3(bool result)
{
	cout << "\n===================Test #3===================\n";

	// Создаём объекты комплексного числа.
	Complex ex1_test3(18, 16, "(18 + 16i)"); // Вызвался конструктор с параметрами.
	Complex ex2_test3(22, 11, "(22 + 11i)"); // Вызвался конструктор с параметрами.
	Complex res_test3; // Вызвался стандартный конструктор.

	// Сложение.
	cout << "---Summation---\n";
	res_test3.summarize(ex1_test3, ex2_test3);
	cout << ex1_test3.getExpression(); cout << " + "; cout << ex2_test3.getExpression(); cout << " = ";
	res_test3.showResult();
	res_test3.compare_with(40, 27);

	// Вычитание.
	cout << "---Subtraction---\n";
	res_test3.subtract(ex1_test3, ex2_test3);
	cout << ex1_test3.getExpression(); cout << " - "; cout << ex2_test3.getExpression(); cout << " = ";
	res_test3.showResult();
	res_test3.compare_with(-4, 5);

	// Деление.
	cout << "---Division---\n";
	res_test3.divide(ex1_test3, ex2_test3);
	cout << ex1_test3.getExpression(); cout << " / "; cout << ex2_test3.getExpression(); cout << " = ";
	res_test3.showResult();
	res_test3.compare_with(0.945, 0.255);

	// Умножение.
	cout << "---Multiplication---\n";
	res_test3.multiply(ex1_test3, ex2_test3);
	cout << ex1_test3.getExpression(); cout << " * "; cout << ex2_test3.getExpression(); cout << " = ";
	res_test3.showResult();
	res_test3.compare_with(220, 550);

	// Сравнивание.
	cout << "---Comparison---\n";
	result = compare(ex1_test3, ex2_test3);
	if (result)
	{
		cout << ex1_test3.getExpression(); cout << " = "; cout << ex2_test3.getExpression(); cout << endl;
	}
	else
	{
		cout << ex1_test3.getExpression(); cout << " != "; cout << ex2_test3.getExpression(); cout << endl;
	}

	res_test3.showNumber();
} // вызвалось 3 деструктора для объектов: ex1_test3 ; ex2_test3 ; res_test3 . Память освобождена.

void Lab1_test4(bool result)
{
	cout << "\n===================Test #4===================\n";

	// Создаём объекты комплексного числа.
	Complex ex1_test4(0, 0, "(0 + 0i)"); // Вызвался конструктор с параметрами.
	Complex ex2_test4(0, 0, "(0 + 0i)"); // Вызвался конструктор с параметрами.
	Complex res_test4; // Вызвался стандартный конструктор.

	// Сложение.
	cout << "---Summation---\n";
	res_test4.summarize(ex1_test4, ex2_test4);
	cout << ex1_test4.getExpression(); cout << " + "; cout << ex2_test4.getExpression(); cout << " = ";
	res_test4.showResult();
	res_test4.compare_with(0, 0);

	// Вычитание.
	cout << "---Subtraction---\n";
	res_test4.subtract(ex1_test4, ex2_test4);
	cout << ex1_test4.getExpression(); cout << " - "; cout << ex2_test4.getExpression(); cout << " = ";
	res_test4.showResult();
	res_test4.compare_with(0, 0);

	// Деление.
	cout << "---Division---\n";
	res_test4.divide(ex1_test4, ex2_test4);
	cout << ex1_test4.getExpression(); cout << " / "; cout << ex2_test4.getExpression(); cout << " = ";
	res_test4.showResult();
	res_test4.compare_with(0, 0);

	// Умножение.
	cout << "---Multiplication---\n";
	res_test4.multiply(ex1_test4, ex2_test4);
	cout << ex1_test4.getExpression(); cout << " * "; cout << ex2_test4.getExpression(); cout << " = ";
	res_test4.showResult();
	res_test4.compare_with(0, 0);

	// Сравнивание.
	cout << "---Comparison---\n";
	result = compare(ex1_test4, ex2_test4);
	if (result)
	{
		cout << ex1_test4.getExpression(); cout << " = "; cout << ex2_test4.getExpression(); cout << endl;
	}
	else
	{
		cout << ex1_test4.getExpression(); cout << " != "; cout << ex2_test4.getExpression(); cout << endl;
	}

	res_test4.showNumber();
} // вызвалось 3 деструктора для объектов: ex1_test4 ; ex2_test4 ; res_test4 . Память освобождена.

void Lab1_test5(bool result)
{
	cout << "\n===================Test #5===================\n";

	// Создаём объекты комплексного числа.
	Complex ex1_test5(-100, 505, "(-100 + 505i)"); // Вызвался конструктор с параметрами.
	Complex ex2_test5(190, 707, "(190 + 707i)"); // Вызвался конструктор с параметрами.
	Complex res_test5; // Вызвался стандартный конструктор.

	// Сложение.
	cout << "---Summation---\n";
	res_test5.summarize(ex1_test5, ex2_test5);
	cout << ex1_test5.getExpression(); cout << " + "; cout << ex2_test5.getExpression(); cout << " = ";
	res_test5.showResult();
	res_test5.compare_with(90, 1212);

	// Вычитание.
	cout << "---Subtraction---\n";
	res_test5.subtract(ex1_test5, ex2_test5);
	cout << ex1_test5.getExpression(); cout << " - "; cout << ex2_test5.getExpression(); cout << " = ";
	res_test5.showResult();
	res_test5.compare_with(-290, -202);

	// Деление.
	cout << "---Division---\n";
	res_test5.divide(ex1_test5, ex2_test5);
	cout << ex1_test5.getExpression(); cout << " / "; cout << ex2_test5.getExpression(); cout << " = ";
	res_test5.showResult();
	res_test5.compare_with(0.631, 0.311);

	// Умножение.
	cout << "---Multiplication---\n";
	res_test5.multiply(ex1_test5, ex2_test5);
	cout << ex1_test5.getExpression(); cout << " * "; cout << ex2_test5.getExpression(); cout << " = ";
	res_test5.showResult();
	res_test5.compare_with(-376035, 25250);

	// Сравнивание.
	cout << "---Comparison---\n";
	result = compare(ex1_test5, ex2_test5);
	if (result)
	{
		cout << ex1_test5.getExpression(); cout << " = "; cout << ex2_test5.getExpression(); cout << endl;
	}
	else
	{
		cout << ex1_test5.getExpression(); cout << " != "; cout << ex2_test5.getExpression(); cout << endl;
	}

	res_test5.showNumber();
} // вызвалось 3 деструктора для объектов: ex1_test5 ; ex2_test5 ; res_test5 . Память освобождена.