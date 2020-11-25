#include <sstream>
#include "Translation.h"

#define strdup _strdup

Translation::Translation() : Complex() { double_toStr(); }

Translation::Translation(double var1, double var2) : Complex(var1, var2) { double_toStr(); }

Translation::Translation(const char* str) : Complex()
{
	str_toDouble(str); // Из строки переводим в double.
	double_toStr(); // Собираем поле strRepresent.
}

char* Translation::get_strRepresent()
{
	return this->strRepresent;
}

Translation::~Translation()
{
	delete[] strRepresent;
}

void Translation::double_toStr()
{
	char expr[255];
	sprintf_s(expr, 100, "(%f + %f i)", get_Valid(), get_Image());

	if (strRepresent)
	{

		delete[] strRepresent;
		strRepresent = nullptr;
	}
	strRepresent = strdup(expr);
}

void Translation::str_toDouble(const char* str)
{
	setlocale(LC_NUMERIC, "C"); // для stringstream, чтобы вместе запятой в дробном числе показывал точку.
	int size = 255;
	double value;
	char* strValid = new char[size];
	char* strImage = new char[size];

	// Для действительной части.
	int i = 0;
	for (int j = 0; str[i]; i++)
	{
		if (str[i] == '+') { i++; break; }
		if (isdigit(str[i]) || str[i] == '.')
		{
			if (i >= size - 1) // Если размера не хватает- то увеличиваем.
			{
				size = 2 * size;
				char* newStr = new char[size];
				strcpy_s(newStr, size, strValid);
				delete[] strValid;
				strValid = newStr;
			}
			strValid[j] = str[i];
			strValid[++j] = 0;
		}
	}
	stringstream sstreamValid; // Преобразуем из формата строки в double.
	sstreamValid << strValid;  //
	sstreamValid >> value;  //
	set_Valid(value);
	
	// Для мнимой части.
	for (int j = 0; str[i]; i++)
	{
		if (str[i] == 'i') break;
		if (isdigit(str[i]) || str[i] == '.')
		{
			if (i >= size - 1) // Если размера не хватает- то увеличиваем.
			{
				size = 2 * size;
				char* newStr = new char[size];
				strcpy_s(newStr, size, strImage);
				delete[] strImage;
				strImage = newStr;
			}
			strImage[j] = str[i];
			strImage[++j] = 0;
		}
	}
	// Преобразуем из формата строки в double.
	stringstream sstreamImage;
	sstreamImage << strImage;  //
	sstreamImage >> value;  //
	set_Image(value);
}