#pragma once
#include <iostream>
#include <fstream>
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

	// Функции класса.
	char* toStringExpression();// Вывод на экран выражения.
	//void to_StrExpression(); // Собрать поле объекта expression.
	void showResult();// Вывод на экран результата.
	void showNumber();// Кол-во выражений.
	void summarize(const Complex& first, const Complex& second);// Суммирование.
	void subtract(const Complex& first, const Complex& second);// Вычитание.
	void divide(const Complex& first, const Complex& second);// Деление.
	void multiply(const Complex& first, const Complex& second);// Умножение.
	void compare_with(const double& value_valid, const double& value_image);// Сравнить полученный результат с ожидаемым результатом.
	

	friend bool compare(const Complex& first, const Complex& second);// Сравнение.
	friend Complex* resizeArr(const Complex* oldArr, size_t& size); // Меняем размер дин.массива.
	
	friend ostream& operator << (ostream& os, Complex& p); // Перегруженный оператор вывода на экран.
	friend istream& operator >> (istream& is, Complex& p); // Перегруженный оператор ввода из консоли.
	friend ofstream& operator << (ofstream& of, Complex& p); // Пергруженный оператор для записи в txt файл.
	friend ifstream& operator >> (ifstream& is, Complex& p); // Перегруженный оператор для считывания из txt файла.
	friend ofstream& operator < (ofstream& os, const Complex& obj); // Перегруженный оператор для записи в bin файл.
	friend ifstream& operator > (ifstream& is, Complex& obj); // Перегруженный оператор для считывания из bin файла.

private:
	double valid;// Дейстивительная часть числа.
	double image;// Мнимая часть числа.
	char* expression;// Строковое представление комплексного числа.
	static int count;// Подсчёт кол-ва выражений

};


