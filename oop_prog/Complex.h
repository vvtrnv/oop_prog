#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Complex
{
public:
	// Конструкторы класса.
	Complex();// Стандартный конструктор класса.
	Complex(double value_valid, double value_complex, const char* appointExpression);// Конструктор класса.
	Complex(double value_valid, double value_complex); // Конструктор с 2мя принимаемыми параметрами.
	Complex(const Complex& other);// Конструктор копирования.

	// Деструктор класса.
	~Complex();

	// Функции класса.
	void showResult();// Вывод на экран результата.
	void showNumber();// Кол-во выражений.
	void summarize(const Complex& first, const Complex& second);// Суммирование.
	void subtract(const Complex& first, const Complex& second);// Вычитание.
	void divide(const Complex& first, const Complex& second);// Деление.
	void multiply(const Complex& first, const Complex& second);// Умножение.
	void compare_with(const double& value_valid, const double& value_image);// Сравнить полученный результат с ожидаемым результатом.
	

	friend bool compare(const Complex& first, const Complex& second);// Сравнение.
	friend ofstream& writingBinary(ofstream& os, const Complex& obj); // Запись в бинарный файл.
	friend ifstream& readingBinary(ifstream& is, Complex& obj); // Чтение из бинарного файла

	Complex& operator = (const Complex& other); // Оператор присваивания.
	
	friend ostream& operator << (ostream& os, Complex& p); // Перегруженный оператор вывода на экран.
	friend istream& operator >> (istream& is, Complex& p); // Перегруженный оператор ввода из консоли.
	friend ofstream& operator << (ofstream& of, Complex& p); // Перегруженный оператор для записи в txt файл.
	friend ifstream& operator >> (ifstream& is, Complex& p); // Перегруженный оператор для считывания из txt файла.

	double get_Value();
	double get_Image();
	char* to_String();// Получить expression объекта.

	void set_Value();
	void set_Image();
	void to_StrExpression(); // Собрать поле объекта expression.

private:
	double valid;// Дейстивительная часть числа.
	double image;// Мнимая часть числа.
	char* expression;// Строковое представление комплексного числа.
	static int count;// Подсчёт кол-ва выражений

};


