#pragma once
#include <iostream>
#include "Complex.h"

using namespace std;

Complex::Complex()// Стандартный конструктор класса.
{
	valid = new double;
	image = new double;
	expression = new char[10];

	*valid = 0;
	*image = 0;
	strcpy_s(expression, 10, "0 + 0");
}

Complex::Complex(double value_valid, double value_complex, const char* appointExpression)// Конструктор класса.
{
	valid = new double;
	image = new double;
	int len = strlen(appointExpression) + 1;
	expression = new char[len];

	*valid = value_valid;
	*image = value_complex;
	strcpy_s(expression, len, appointExpression);
}

Complex::Complex(const Complex& other)// Конструктор копирования.
{
	valid = new double;
	image = new double;


	*valid = *(other.valid);
	*image = *(other.image);
	int len = strlen(other.expression) + 1;
	expression = new char[len];
	strcpy_s(expression, len, other.expression);
}

Complex::~Complex()
{
	delete valid;
	delete image;
	delete[] expression;
}


void Complex::showNumber()// Вывод кол-ва выражений.
{
	cout << "Number of expressions = " << count << endl;
}

char* Complex::to_String()// Метод вывода на экран двух комплексных чисел.
{
	return expression;
}

void Complex::showResult()// Функция класса "Вывод на экран результата"
{
	cout.precision(3);

	if (*valid != 0 && *image != 0)
	{
		if (*image < 0) // Для красоты вывода.
			cout << *valid << " " << *image << "i\n" << endl;
		else
		{
			cout << *valid << " + " << *image << "i\n" << endl;
		}
	}
	else if (*valid == 0 && *image != 0)
		cout << *image << "i\n" << endl;
	else if (*valid != 0 && *image == 0)
		cout << *valid << endl << endl;
	else
		cout << "0\n" << endl;
}

void Complex::summarize(const Complex& first, const Complex& second) // Функция класса "Суммирование".
{
	count++;

	*(this->valid) = *(first.valid) + *(second.valid);
	*(this->image) = *(first.image) + *(second.image);
}

void Complex::subtract(const Complex& first, const Complex& second) // Функция класса "Суммирование".
{
	count++;

	*(this->valid) = *(first.valid) - *(second.valid);
	*(this->image) = *(first.image) - *(second.image);
}

void Complex::divide(const Complex& first, const Complex& second)// Деление.
{
	count++;

	if ((pow(*(second.valid), 2) + pow(*(second.image), 2)) == 0)
		cout << "ERROR! Division by zero." << endl;
	else
	{
		*(this->valid) = (*(first.valid) * *(second.valid) + *(first.image) * *(second.image)) / (pow(*(second.valid), 2) + pow(*(second.image), 2));
		*(this->image) = (*(first.image) * *(second.valid) - *(first.valid) * *(second.image)) / (pow(*(second.valid), 2) + pow(*(second.image), 2));
	}
}

void Complex::multiply(const Complex& first, const Complex& second)// Умножение.
{
	count++;

	*(this->valid) = *(first.valid) * *(second.valid) - *(first.image) * *(second.image);
	*(this->image) = *(first.image) * *(second.valid) + *(first.valid) * *(second.image);
}

bool Complex::compare(const Complex& first, const Complex& second)
{
	count++;

	if (*(first.valid) == *(second.valid) && *(first.image) == *(second.image))
		return true;
	else return false;
}

void Complex::compare_with(const double& value_valid, const double& value_image)
{
	const double EPS = 1e-3;// Константа для сравнения
	cout << "Expected result: " << value_valid << " + " << value_image << "i"
		<< "\nand Real result: " << *(this->valid) << " + " << *(this->image) << "i" << endl;
	if (abs(value_valid - *(this->valid)) < EPS && abs(value_image - *(this->image)) < EPS)
	{
		cout << "The result matched!\n\n\n";
	}
	else
	{
		cout << "The result didn't match!\n\n\n";
	}
}

int Complex::count = 0;// Начальное значение.