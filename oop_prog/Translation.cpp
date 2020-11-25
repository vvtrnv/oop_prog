#include <sstream>
#include "Translation.h"

#define strdup _strdup

Translation::Translation() : Complex() { double_toStr(); }

Translation::Translation(double var1, double var2) : Complex(var1, var2) { double_toStr(); }

Translation::Translation(const char* str) : Complex()
{
	str_toDouble(str); // �� ������ ��������� � double.
	double_toStr(); // �������� ���� strRepresent.
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
	setlocale(LC_NUMERIC, "C"); // ��� stringstream, ����� ������ ������� � ������� ����� ��������� �����.
	int size = 255;
	double value;
	char* strValid = new char[size];
	char* strImage = new char[size];

	// ��� �������������� �����.
	int i = 0;
	for (int j = 0; str[i]; i++)
	{
		if (str[i] == '+') { i++; break; }
		if (isdigit(str[i]) || str[i] == '.')
		{
			if (i >= size - 1) // ���� ������� �� �������- �� �����������.
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
	stringstream sstreamValid; // ����������� �� ������� ������ � double.
	sstreamValid << strValid;  //
	sstreamValid >> value;  //
	set_Valid(value);
	
	// ��� ������ �����.
	for (int j = 0; str[i]; i++)
	{
		if (str[i] == 'i') break;
		if (isdigit(str[i]) || str[i] == '.')
		{
			if (i >= size - 1) // ���� ������� �� �������- �� �����������.
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
	// ����������� �� ������� ������ � double.
	stringstream sstreamImage;
	sstreamImage << strImage;  //
	sstreamImage >> value;  //
	set_Image(value);
}