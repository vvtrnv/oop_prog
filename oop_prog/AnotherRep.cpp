#include <cmath>
#include "AnotherRep.h"

#define strdup _strdup

// Конструкторы.
AnotherRep::AnotherRep() : Complex()
{ 
	this->r = 0;
	this->angle = 0;

	strTrig = new char[30];
	strExp = new char[30];
	strcpy_s(strTrig, 30, "NOT INITIALIZE");
	strcpy_s(strExp, 30, "NOT INITIALIZE");
}

AnotherRep::AnotherRep(double var1, double var2) : Complex(var1, var2) 
{
	this->r = 0;
	this->angle = 0;

	convertTrig();
	convertExp();
}


// Деструктор, поскольку нужно освободить память.
AnotherRep::~AnotherRep()
{
	delete[] strTrig;
	delete[] strExp;
}


// Геттеры. Сеттеры не нужны, тк все поля нужно вычислять.
char* AnotherRep::get_strTrig()
{
	return this->strTrig;
}

char* AnotherRep::get_strExp()
{
	return this->strExp;
}

double AnotherRep::get_R()
{
	return this->r;
}

double AnotherRep::get_Angle()
{
	return this->angle;
}


// Методы.
void AnotherRep::convertTrig()
{
	setlocale(LC_NUMERIC, "C");
	char temp[500];

	this->r = sqrt(pow(get_Valid(), 2) + pow(get_Image(), 2)); // находим аргумент.
	this->angle = atan(get_Image() / get_Valid()); // Находим угол.

	sprintf_s(temp, 500, "%f * [cos(%f) + i*sin(%f)]", this->r, this->angle, this->angle);
	strTrig = strdup(temp);
}

void AnotherRep::convertExp()
{
	setlocale(LC_NUMERIC, "C");
	char temp[500];

	this->r = sqrt(pow(get_Valid(), 2) + pow(get_Image(), 2)); // находим аргумент.
	this->angle = atan(get_Image() / get_Valid()); // Находим угол.

	if (angle < 0)
	{
		double t;
		t = -this->angle;
		sprintf_s(temp, 500, "%f * exp(-i*%f)", this->r, t);
	}
	else sprintf_s(temp, 500, "%f * exp(i*%f)", this->r, this->angle);

	strExp = strdup(temp);
}

void AnotherRep::convertAllForms()
{
	convertTrig();
	convertExp();
}

char* AnotherRep::to_String()
{
	return strTrig;
}