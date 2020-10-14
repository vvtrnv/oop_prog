#pragma once
#include <iostream>
using namespace std;

class Complex
{
public:
	// Конструкторы класса.
	Complex(double value_valid, double value_complex, const char* appointExpression);// Конструктор класса.
	Complex();// Стандартный конструктор класса.
	Complex(const Complex& other);// Конструктор копирования.

	// Деструктор класса.
	~Complex();

	// Функции класса.t43t43t43t43t43t3
	char* to_String();// Вывод на экран выражения.
	void showResult();// Вывод на экран результата.
	void showNumber();// Кол-во выражений.
	void summarize(const Complex& first, const Complex& second);// Суммирование.
	void subtract(const Complex& first, const Complex& second);// Вычитание.
	void divide(const Complex& first, const Complex& second);// Деление.
	void multiply(const Complex& first, const Complex& second);// Умножение.
	bool compare(const Complex& first, const Complex& second);// Сравнение.
	void compare_with(const double& value_valid, const double& value_image);// Сравнить полученный результат с ожидаемым результатом.

private:
	double* valid;// Дейстивительная часть числа.
	double* image;// Мнимая часть числа.
	char* expression;// Строковое представление комплексного числа.
	static int count;// Подсчёт кол-ва выражений

};


