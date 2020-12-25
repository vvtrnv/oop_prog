#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>
#include "Complex.h"
#include "locale.h" // Для предотвращения ошибки с русскими буквами при некорректном вводе.


using namespace std;

Complex::Complex()// Стандартный конструктор класса.
{
	expression = new char[10];

	this->valid = 0;
	this->image = 0;
	this->to_StrExpression();
}

Complex::Complex(double value_valid, double value_image, const char* appointExpression)// Конструктор класса.
{
	
	valid = value_valid;
	image = value_image;

	int len = strlen(appointExpression) + 1;
	expression = new char[len];
	strcpy_s(expression, len, appointExpression);
}

Complex::Complex(double value_valid, double value_image)
{
	this->valid = value_valid;
	this->image = value_image;
	this->expression = nullptr;
	this->to_StrExpression();
}

Complex::Complex(const Complex& other)// Конструктор копирования.
{
	valid = other.valid;
	image = other.image;
	int len = strlen(other.expression) + 1;
	expression = new char[len];
	strcpy_s(expression, len, other.expression);
}

Complex::~Complex()
{
	delete[] expression;
	expression = nullptr;
}


void Complex::showResult()// Функция класса "Вывод на экран результата"
{
	cout.precision(3);

	if (valid != 0 && image != 0)
	{
		if (image < 0) // Для красоты вывода.
			cout << valid << " " << image << "i\n" << endl;
		else
		{
			cout << valid << " + " << image << "i\n" << endl;
		}
	}
	else if (valid == 0 && image != 0)
		cout << image << "i\n" << endl;
	else if (valid != 0 && image == 0)
		cout << valid << endl << endl;
	else
		cout << "0\n" << endl;
}

void Complex::showNumber()// Вывод кол-ва выражений.
{
	cout << "Number of expressions = " << count << endl;
}

void Complex::summarize(const Complex& first, const Complex& second) // Функция класса "Суммирование".
{
	count++;

	this->valid = first.valid + second.valid;
	this->image = first.image + second.image;
}

void Complex::subtract(const Complex& first, const Complex& second) // Функция класса "Суммирование".
{
	count++;

	this->valid = first.valid - second.valid;
	this->image = first.image - second.image;
}

void Complex::divide(const Complex& first, const Complex& second)// Деление.
{
	count++;

	if ((pow(second.valid, 2) + pow(second.image, 2)) == 0)
		cout << "ERROR! Division by zero." << endl;
	else
	{
		this->valid = (first.valid * second.valid + first.image * second.image) / (pow(second.valid, 2) + pow(second.image, 2));
		this->image = (first.image * second.valid - first.valid * second.image) / (pow(second.valid, 2) + pow(second.image, 2));
	}
}

void Complex::multiply(const Complex& first, const Complex& second)// Умножение.
{
	count++;

	this->valid = first.valid * second.valid - first.image * second.image;
	this->image = first.image * second.valid + first.valid * second.image;
}

void Complex::compare_with(const double& value_valid, const double& value_image)
{
	const double EPS = 1e-3;// Константа для сравнения
	cout << "Expected result: " << value_valid << " + " << value_image << "i"
		 << "\nand Real result: " << this->valid << " + " << this->image << "i" << endl;
	if (abs(value_valid - this->valid) < EPS && abs(value_image - this->image) < EPS)
	{
		cout << "The result matched!\n\n\n";
	}
	else
	{
		cout << "The result didn't match!\n\n\n";
	}
}

bool compare(const Complex& first, const Complex& second)
{
	Complex::count++;

	if (first.valid == second.valid && first.image == second.image)
		return true;
	else return false;
}


ofstream& writingBinary(ofstream& os, const Complex& obj)
{
	os.write((char*)&obj.valid, sizeof(double));
	os.write((char*)&obj.image, sizeof(double));
	return os;
}

ifstream& readingBinary(ifstream& is, Complex& obj)
{
	is.read((char*)&obj.valid, sizeof(double));
	is.read((char*)&obj.image, sizeof(double));
	obj.to_StrExpression();
	return is;
}

Complex& Complex::operator = (const Complex& other)
{
	int len;
	this->valid = other.valid;
	this->image = other.image;

	delete[] this->expression;
	len = strlen(other.expression) + 1;
	this->expression = new char[len];
	strcpy_s(this->expression, len, other.expression);

	return *this;
}

bool operator<(const Complex& left, const Complex& right)
{
	if (left.valid < right.valid) return true;
	else if (left.valid == right.valid)
	{
		if (left.image < right.image) return true;
		else return false;
	}
	else return false;
}

bool Complex::operator==(const Complex& obj)
{
	if (strcmp(this->expression, obj.expression) == 0)
		return true;
	else return false;
}

ostream& operator << (ostream& os, Complex& p) // Вывод на экран.
{
	os << "valid = " << p.valid << "\timage = " << p.image << "\texpression = "  << p.expression << endl;
	return os;
}

istream& operator >> (istream& is, Complex& p) // Записывание данных с консоли.
{
	int size = 100;
	char* strValid = new char[size];
	char* strImage = new char[size];
	setlocale(LC_ALL, "rus"); // Чтобы предотвратить вылет программы при некорректном вводе. русских символов.
	setlocale(LC_NUMERIC, "C"); // для stringstream, чтобы вместе запятой в дробном числе показывал точку.

	// Для действительной части.
	while (1)
	{
		char c;
		int i = 0;
		while (is.get(c))
		{
			if (c == '\n') break;
			if (i >= size - 1)
			{
				size = 2 * size;
				char* newStr = new char[size];
				strcpy_s(newStr, size, strValid);
				delete[] strValid;
				strValid = newStr;
			}
			strValid[i] = c;
			strValid[i + 1] = '\0';
			i++;
		}

		// Убеждаемся, что каждый символ является цифрой.
		bool flag = true;
		for (int i = 0; strValid[i]; i++)
		{
			if (!isdigit(strValid[i])) // Проверка на наличие букв,символов, пробелов...
			{
				if (strValid[i] == '.') continue;
				flag = false; // Если нашёлся хотябы один символ, не являющийся цифрой, то flag = false.
				break;
			}
		}
		if (!flag)
			continue;

		stringstream strStream; // Преобразуем из формата строки в int.
		strStream << strValid;  //
		strStream >> p.valid;  //

		break;
	}

	// Для мнимой части.
	while (1)
	{
		// Считываем посимвольно, если не хватает размера - увеличиваем в 2 раза.
		char c;
		int i = 0;
		while (is.get(c))
		{
			if (c == '\n') break;
			if (i >= size - 1)
			{
				size = 2 * size;
				char* newStr = new char[size];
				strcpy_s(newStr, size, strImage);
				delete[] strImage;
				strImage = newStr;
			}
			strImage[i] = c;
			strImage[i + 1] = '\0';
			i++;
		}

		// Убеждаемся, что каждый символ является цифрой.
		bool flag = true;
		for (int i = 0; strImage[i]; i++)
		{
			if (!isdigit(strImage[i])) // Проверка на наличие букв,символов, пробелов...
			{
				if (strImage[i] == '.') continue;
				flag = false; // Если нашёлся хотябы один символ, не являющийся цифрой, то flag = false.
				break;
			}
		}
		if (!flag)
			continue;

		stringstream strStream; // Преобразуем из формата строки в int.
		strStream << strImage;  //
		strStream >> p.image;  //

		break;
	}
	p.to_StrExpression();

	return is;
}

ofstream& operator << (ofstream& os, Complex& p) // Запись в файл.
{
	os << p.valid << " " << p.image << "\n";
	return os;
}

ifstream& operator >> (ifstream& is, Complex& p) // Чтение из файла.
{
	is >> p.valid >> p.image;
	p.to_StrExpression();

	return is;
}


double Complex::get_Valid()
{
	return this->valid;
}

double Complex::get_Image()
{
	return this->image;
}

char* Complex::to_String()// Получить строковое представление.
{
	return expression;
}

void Complex::set_Valid(const double& var)
{
	this->valid = var;
	to_StrExpression();
}

void Complex::set_Image(const double& var)
{
	this->image = var;
	to_StrExpression();
}

void Complex::to_StrExpression()
{
	setlocale(LC_NUMERIC, "C");
	char expr[255];
	sprintf_s(expr, 100, "(%f + %f i)", this->valid, this->image);

	if (this->expression)
	{

		delete[] this->expression;
		this->expression = nullptr;
	}
	int len = strlen(expr) + 1;
	this->expression = new char[len];
	strcpy_s(this->expression, len, expr);
}

int Complex::count = 0;// Начальное значение.