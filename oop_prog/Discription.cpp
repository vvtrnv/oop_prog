#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include "Complex.h"


using namespace std;

const int SIZE = 40;

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

bool compare(const Complex& first, const Complex& second)
{
	Complex::count++;

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


ostream& operator << (ostream& os, Complex& p)
{
	os << "valid = " << *p.valid << "\timage = " << *p.image << "\t Expression: (" << p.expression << ")"<< endl;
	return os;
}

istream& operator >> (istream& is, Complex& p)
{
	char strValid[SIZE], strImage[SIZE], strExpression[SIZE];

	if (p.valid && p.image && p.expression)
	{
		delete p.valid;
		delete p.image;
		delete p.expression;
	}
	// Для действительной части.
	while (1)
	{
		cout << "Input: valid" << endl;
		cin.getline(strValid, SIZE);
		p.valid = new double;

		// Убеждаемся, что каждый символ является цифрой.
		bool flag = true;
		for (int i = 0; strValid[i]; i++)
		{
			if (!isdigit(strValid[i])) // Проверка на наличие букв,символов, пробелов...
			{
				flag = false; // Если нашёлся хотябы один символ, не являющийся цифрой, то flag = false.
				break;
			}
		}
		if (!flag)
			continue;

		stringstream strStream; // Преобразуем из формата строки в int.
		strStream << strValid;  //
		strStream >> *p.valid;  //

		break;
	}

	// Для мнимой части.
	while (1)
	{
		cout << "Input: Image" << endl;
		cin.getline(strImage, SIZE);
		p.image = new double;

		// Убеждаемся, что каждый символ является цифрой.
		bool flag = true;
		for (int i = 0; strImage[i]; i++)
		{
			if (!isdigit(strImage[i])) // Проверка на наличие букв,символов, пробелов...
			{
				flag = false; // Если нашёлся хотябы один символ, не являющийся цифрой, то flag = false.
				break;
			}
		}
		if (!flag)
			continue;

		stringstream strStream; // Преобразуем из формата строки в int.
		strStream << strImage;  //
		strStream >> *p.image;  //

		break;
	}

	// Для строкового представления.
	cout << "Input: Expression(example: 5+10i)" << endl;
	cin >> strExpression;
	size_t len = strlen(strExpression) + 1;
	p.expression = new char[len];
	strcpy_s(p.expression, len, strExpression);

	return is;
}

ofstream& operator << (ofstream& os, Complex& p)
{
	os << *p.valid << " " << *p.image << " " << *p.expression << "\n";
	return os;
}

ifstream& operator >> (ifstream& is, Complex& p)
{
	char temp[40];
	if (p.valid && p.image && p.expression)
	{
		delete p.valid;
		delete p.image;
		delete p.expression;
	}
	p.valid = new double;
	p.image = new double;
	
	is >> *(p.valid) >> *(p.image) >> temp;
	int len = strlen(temp) + 1;
	p.expression = new char[len];
	strcpy_s(p.expression, len, temp);
	return is;
}

int Complex::count = 0;// Начальное значение.