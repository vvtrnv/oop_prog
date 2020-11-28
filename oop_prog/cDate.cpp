#include <ctime>
#include "cDate.h"

// Конструкторы.
cDate::cDate() : Complex()
{
	//this->dateCreate = new char[10];
	//dateCreate = nullptr;
	fixTime();
}

cDate::cDate(double var1, double var2) : Complex(var1, var2)
{
	//this->dateCreate = new char[10];
	//dateCreate = nullptr;
	fixTime();
}


// Деструктор, поскольку нужно освободить память.
cDate::~cDate()
{
	delete[] dateCreate;
}


// Геттеры. Сеттеры не нужны, поскольку изменять ничего нельзя.
char* cDate::get_dateCreate() { return this->dateCreate; }

// Методы.
void cDate::fixTime()
{
	time_t now = time(NULL);
	this->dateCreate = new char[30];
	ctime_s(this->dateCreate, 30, &now);
}


