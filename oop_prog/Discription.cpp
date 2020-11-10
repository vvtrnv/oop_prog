#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <cstdio>
#include "Complex.h"


using namespace std;

const int SIZE = 40;

Complex::Complex()// Стандартный конструктор класса.
{
	expression = new char[10];

	valid = 0;
	image = 0;
	strcpy_s(expression, 10, "0 + 0");
}

Complex::Complex(double value_valid, double value_complex, const char* appointExpression)// Конструктор класса.
{
	
	valid = value_valid;
	image = value_complex;

	int len = strlen(appointExpression) + 1;
	expression = new char[len];
	strcpy_s(expression, len, appointExpression);
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


void Complex::showNumber()// Вывод кол-ва выражений.
{
	cout << "Number of expressions = " << count << endl;
}

char* Complex::toStringExpression()// Метод вывода на экран двух комплексных чисел.
{
	return expression;
}

void Complex::to_StrExpression() // Не работает с объектами класса. Выводит не пойми что :(
{
	char expr[100];
	int j; // Подсчёт кол-ва символов.
	sprintf_s(expr, 100, "(%f + %f i)", this->valid, this->image);

	int len = strlen(expr) + 1;
	this->expression = new char[len];
	strcpy_s(this->expression, len, expr);
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

bool compare(const Complex& first, const Complex& second)
{
	Complex::count++;

	if (first.valid == second.valid && first.image == second.image)
		return true;
	else return false;
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

Complex* resizeArr(const Complex* oldArr, size_t& size)// Меняет размер динамического массива.
{
	Complex* newArr = new Complex[size+1];
	memcpy(newArr, oldArr, sizeof(Complex) * size);
	size++;
	
	delete[] oldArr;
	return newArr;
}

ostream& operator << (ostream& os, Complex& p) // Вывод на экран.
{
	os << "valid = " << p.valid << "\timage = " << p.image /*<< "\t Expression: (" << p.expression << ")"*/<< endl;
	return os;
}

istream& operator >> (istream& is, Complex& p) // Записывание данных с консоли.
{
	char strValid[SIZE], strImage[SIZE], strExpression[SIZE];

	if (p.expression)
	{
		delete p.expression;
	}
	// Для действительной части.
	while (1)
	{
		cout << "Input: valid" << endl;
		cin.getline(strValid, SIZE);

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
		strStream >> p.valid;  //

		break;
	}

	// Для мнимой части.
	while (1)
	{
		cout << "Input: Image" << endl;
		cin.getline(strImage, SIZE);

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
		strStream >> p.image;  //

		p.expression = new char[10];

		break;
	}

	return is;
}

ofstream& operator << (ofstream& os, Complex& p) // Запись в файл.
{
	os << p.valid << " " << p.image << endl;
	return os;
}

ifstream& operator >> (ifstream& is, Complex& p) // Чтение из файла.
{
	if (*(p.expression))
	{
		delete p.expression;
	}
	p.expression = new char[10];
	strcpy_s(p.expression, 10, "0 + 0");

	is >> p.valid >> p.image;	//>> temp;
	
	return is;
}

ofstream& operator < (ofstream& os, const Complex& obj)
{
	os.write((char*)&obj.valid, sizeof(double));
	os.write((char*)&obj.image, sizeof(double));
	return os;
}

ifstream& operator > (ifstream& is, Complex& obj)
{
	if (obj.expression)
	{

		delete obj.expression;
	}
	obj.expression = new char;

	is.read((char*)&obj.valid, sizeof(double));
	is.read((char*)&obj.image, sizeof(double));

	return is;
}

int Complex::count = 0;// Начальное значение.